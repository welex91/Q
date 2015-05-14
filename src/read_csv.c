#include <limits.h>
#include <sys/mman.h>
#include "qtypes.h"
#include "auxil.h"
#include "dbauxil.h"
#include "mmap.h"
#include "read_meta_data.h"
#include "dbauxil.h"
#include "mk_dict.h"
#include "is_fld.h"
#include "get_nR.h"
#include "read_csv.h" 
#include "print_cell.h" 

/* Given a CSV file and the meta-data for it (as an array), convert the
 * CSV file into the raw files that can be loaded into Q. Since we may
 * want to ignore some of the fields, we provide a string of the form
 * "1:0:1:1" where 1 indicates we want the field an 0 indicates that we
 * wish to ignore it.  If the string is empty or NULL, then we want all
 * fields */

/* Structure of lkp table
 * q describe lkp_bool
 * 1757,text,"",clob,int
 * 2383,idx,"",I4,int
 * 3131,key,"",I8,int
 * 3299,off,"",I4,int
 * 3343,len,"",I4,int
 */

#define pr_error(X, nX, i, num_rows, fld_idx) {				\
	int lb = i-20; if ( lb <  0  ) { lb = 0; } \
	int ub = i+20; if ( lb >= nX ) { ub = nX; } \
	fprintf(stderr, "Error at position %lld\n", i);			\
	fprintf(stderr, "Printing region.. \n");				\
	for ( int ii = lb; ii < ub; ii++ ) {  fprintf(stderr, "%c", X[ii]); }	\
	fprintf(stderr, "\n");						\
	fprintf(stderr, "Rows consumed so far = %lld \n", num_rows);	\
	fprintf(stderr, "Processing %dth field = [%s]\n", fld_idx+1, flds[fld_idx]);\
	go_BYE(-1);  \
}

#define START_OF_VAL 1000
#define END_OF_VAL   2000
#define IN_VAL       3000

extern char g_cwd[MAX_LEN_DIR_NAME+1];
long long g_num_rows;

extern FLD_REC_TYPE *g_flds;
extern int g_n_fld;

// last review 9/5/2013
// START FUNC DECL
int
read_csv(
	 char *data_dir,
	 char *infile,
	 char fld_sep, 
	 char fld_open, 
	 char fld_close, 
	 char rec_delim, 
	 bool ignore_hdr, /* whether to ignore header or not */
	 char flds[MAX_NUM_FLDS_TO_LOAD][MAX_LEN_FLD_NAME+1],
	 int n_flds,
	 FLD_TYPE fldtype[MAX_NUM_FLDS_TO_LOAD],
	 FLD_PROPS_TYPE fld_props[MAX_NUM_FLDS_TO_LOAD], /* properties of fields */
	 int filenos[MAX_NUM_FLDS_TO_LOAD],
	 int nn_filenos[MAX_NUM_FLDS_TO_LOAD],
	 int len_filenos[MAX_NUM_FLDS_TO_LOAD],
	 HT_REC_TYPE *hts[MAX_NUM_FLDS_TO_LOAD],
	 int sz_hts[MAX_NUM_FLDS_TO_LOAD],
	 int n_hts[MAX_NUM_FLDS_TO_LOAD],
	 int dict_tbl_id[MAX_NUM_FLDS_TO_LOAD],
	 long long *ptr_num_rows
	 )
// STOP FUNC DECL
{
  int status = 0;
  char *X = NULL; size_t nX = 0;
  char bslash = '\\';
  long long num_rows = 0; long long num_cells = 0; int fld_idx; 
  FILE *fps[MAX_NUM_FLDS_TO_LOAD];
  FILE *nn_fps[MAX_NUM_FLDS_TO_LOAD];
  FILE *len_fps[MAX_NUM_FLDS_TO_LOAD];
  char filename[MAX_LEN_FILE_NAME+1]; 

  char *dld_buf = NULL; int buflen = 0, bufidx = 0;

  char *txt_X[MAX_NUM_FLDS_TO_LOAD]; size_t txt_nX[MAX_NUM_FLDS_TO_LOAD];
  char *key_X [MAX_NUM_FLDS_TO_LOAD]; size_t key_nX[MAX_NUM_FLDS_TO_LOAD];
  char *off_X [MAX_NUM_FLDS_TO_LOAD]; size_t off_nX[MAX_NUM_FLDS_TO_LOAD];
  char *len_X [MAX_NUM_FLDS_TO_LOAD]; size_t len_nX[MAX_NUM_FLDS_TO_LOAD];
  int n_keys[MAX_NUM_FLDS_TO_LOAD];

  if ( n_flds <= 0 ) { go_BYE(-1); }
  if ( ( infile == NULL ) || ( *infile == '\0' ) ) { go_BYE(-1); }

  for ( int i = 0; i < MAX_NUM_FLDS_TO_LOAD; i++ ) { 
    txt_X[i] = NULL; txt_nX[i] = 0;
    key_X [i] = NULL;  key_nX[i] = 0;
    off_X [i] = NULL;  off_nX[i] = 0;
    len_X [i] = NULL;  len_nX[i] = 0;
    fps[i] = NULL;
    nn_fps[i] = NULL;
    len_fps[i] = NULL;
  }
  /* TODO: Put limit of 32767 on length of string and maybe 1M for
   * number of keys */
  for ( int i = 0; i < MAX_NUM_FLDS_TO_LOAD; i++ ) { 
    long long tmpnR;
    FLD_REC_TYPE tempfldrec, nn_tempfldrec; int itemp, nn_itemp;
    if ( dict_tbl_id[i] >= 0 ) {
      /* text */
      status = is_fld(NULL, dict_tbl_id[i], "txt", &itemp, &tempfldrec,
          &nn_itemp, &nn_tempfldrec);
      cBYE(status);
      status = get_data(tempfldrec, &(txt_X[i]), &(txt_nX[i]), false);
      cBYE(status);
      if ( nn_itemp >= 0 ) { go_BYE(-1); }
      /* key */
      status = is_fld(NULL, dict_tbl_id[i], "key", &itemp, &tempfldrec,
          &nn_itemp, &nn_tempfldrec);
      cBYE(status);
      status = get_data(tempfldrec, &(key_X[i]), &(key_nX[i]), false);
      cBYE(status);
      if ( nn_itemp >= 0 ) { go_BYE(-1); }
      /* len */
      status = is_fld(NULL, dict_tbl_id[i], ".len.txt", &itemp, &tempfldrec,
          &nn_itemp, &nn_tempfldrec);
      cBYE(status);
      status = get_data(tempfldrec, &(len_X[i]), &(len_nX[i]), false);
      cBYE(status);
      if ( nn_itemp >= 0 ) { go_BYE(-1); }
      /* off */
      status = is_fld(NULL, dict_tbl_id[i], ".off.txt", &itemp, &tempfldrec,
          &nn_itemp, &nn_tempfldrec);
      cBYE(status);
      status = get_data(tempfldrec, &(off_X[i]), &(off_nX[i]), false);
      cBYE(status);
      if ( nn_itemp >= 0 ) { go_BYE(-1); }
      /* number of keys */
      status = int_get_nR(dict_tbl_id[i], &tmpnR); cBYE(status);
      n_keys[i] = tmpnR;
    }
  }

  g_num_rows = 0; 
  buflen = 8191; bufidx = 0;
  dld_buf = (char *)malloc(buflen+1);
  return_if_malloc_failed(dld_buf);
  zero_string(dld_buf, buflen+1);
  zero_string(filename, MAX_LEN_FILE_NAME+1);

  /*----------------------------------------------------------------------*/
  for ( int i = 0; i < MAX_NUM_FLDS_TO_LOAD; i++ ) { 
    fps[i] = NULL; 
    nn_fps[i] = NULL; 
    len_fps[i] = NULL; 
  }
  /*-----------------------------------------------------------------------*/
  // Open input data file to read
  status = rs_mmap(infile, &X, &nX, 0); cBYE(status);
  fld_idx = 0; 

  // Open file pointers for fields (and nn fields if they might be needed)
  status = chdir(data_dir); cBYE(status);
  for ( int i = 0; i < n_flds; i++ ) {
    if ( fld_props[i].is_load == false ) { continue; }
    filenos[i] = get_max_fileno();
    zero_string_to_nullc(filename); mk_file_name(filename, filenos[i]);
    fps[i] = fopen(filename, "wb");
    return_if_fopen_failed(fps[i], filename,  "wb");
    // Create a nn field if there is a chance that you might need it 
    if ( fld_props[i].is_all_def == false ) { 
      nn_filenos[i] = get_max_fileno();
      zero_string_to_nullc(filename); mk_file_name(filename, nn_filenos[i]);
      nn_fps[i] = fopen(filename, "wb");
      return_if_fopen_failed(nn_fps[i], filename,  "wb");
    }
    // If variable length field, then create a len field for it 
    if ( fldtype[i] == SV ) { 
      len_filenos[i] = get_max_fileno();
      zero_string_to_nullc(filename); mk_file_name(filename, len_filenos[i]);
      len_fps[i] = fopen(filename, "wb");
      return_if_fopen_failed(len_fps[i], filename,  "wb");
    }
  }
  //---------------------------------------------------------------------
  bool fld_open_seen = false;
  int state = START_OF_VAL;
  fld_idx = 0;
  num_rows = 0;
  for ( unsigned long long i = 0; i < nX; ) {
    char val = X[i];

    switch ( state ) {
      case END_OF_VAL :
        if ( val == rec_delim ) {
          if ( (fld_idx+1) != n_flds ) { 
            pr_error(X, nX, i, num_rows, fld_idx);
          }
          state = START_OF_VAL;
        }
        else if ( val == fld_sep ) {
          if ( (fld_idx+1) >= n_flds ) {
            pr_error(X, nX, i, num_rows, fld_idx);
          }
          state = START_OF_VAL;
        }
        else {
          pr_error(X, nX, i, num_rows, fld_idx);
        }
        // now print unless it is header row 
        if ( ( num_rows == 0 ) && ( ignore_hdr == true ) ) {
          // nothing to print
        }
        else {
#undef TESTING
#ifdef TESTING
          fprintf(stderr, "Row %lld, Col %d, Val [%s]\n", num_rows, fld_idx,
              dld_buf);
#endif
          status = print_cell(dld_buf, bufidx, fldtype[fld_idx], 
              &(fld_props[fld_idx]), fps[fld_idx], nn_fps[fld_idx], 
              len_fps[fld_idx], n_keys[fld_idx], key_X[fld_idx], txt_X[fld_idx], 
              off_X[fld_idx], len_X[fld_idx], 
              hts[fld_idx], sz_hts[fld_idx], 
              &(n_hts[fld_idx]));
          cBYE(status);
        }
        //----------------------------
        if ( val == rec_delim ) { 
          fld_idx = 0; 
          num_rows++;
        } 
        else { 
          fld_idx++; 
        }
        fld_open_seen = false;
        zero_string_to_nullc(dld_buf); bufidx = 0;
        num_cells++;
        i++; // consume this character
        break;
      case START_OF_VAL :
        if ( ( fld_open != 0 ) && ( val == fld_open ) ) {
          i++; // consume this character
          fld_open_seen = true;
        }
        else {
          // do nothing but just change state.
        }
        state = IN_VAL;
        break;
      case IN_VAL : 
        /* deal with escaping */
        if ( val == bslash ) {
          if ( ( i + 1 ) >= nX ) { go_BYE(-1); }
          if ( X[i+1] == bslash ) {
            dld_buf[bufidx++] = bslash;
          }
          else {
            if ( fld_open_seen == true ) { 
              if ( X[i+1] == fld_close ) {
                dld_buf[bufidx++] = fld_close;
              }
              else {
                go_BYE(-1);
              }
            }
            else {
              if ( X[i+1] == fld_sep ) {
                dld_buf[bufidx++] = fld_sep;
              }
              else {
                go_BYE(-1);
              }
            }
          }
          i += 2; // consume 2 characters
        }
        else {
          if ( fld_open_seen == true ) { 
            if ( val == fld_close ) {
              state = END_OF_VAL;
              i++; // consume this character
              fld_open_seen = false;
            }
          }
          else {
            if ( ( val == fld_sep ) || ( val == rec_delim ) ) {
              state = END_OF_VAL;
            }
          }
          if ( state != END_OF_VAL ) { 
            // put the character into the buffer
            dld_buf[bufidx++] = val; i++; 
          }
        }
        break;
      default : 
        pr_error(X, nX, i, num_rows, fld_idx);

        break;
    }
  }
  if ( num_cells != ( n_flds * num_rows ) ) {
    fprintf(stderr, "num_cells = %lld   \n", num_cells);
    fprintf(stderr, "n_flds    = %d   \n", n_flds   );
    fprintf(stderr, "num_rows  = %lld \n", num_rows);
    go_BYE(-1); 
  }
  if ( ignore_hdr ) { 
    num_rows--; // Because you have eliminated first row 
  }
  *ptr_num_rows = num_rows;
BYE:
  for ( int i = 0; i < MAX_NUM_FLDS_TO_LOAD; i++ ) { 
    fclose_if_non_null(fps[i]);
    fclose_if_non_null(nn_fps[i]);
    fclose_if_non_null(len_fps[i]);
  }
  /* Delete temporary files if problem */
  if ( status < 0 ) { 
    for ( int i = 0; i < MAX_NUM_FLDS_TO_LOAD; i++ ) { 
      if ( filenos[i] > 0 ) { 
        zero_string_to_nullc(filename); mk_file_name(filename, filenos[i]); 
        unlink(filename);
      }
      if ( nn_filenos[i] > 0 ) { 
        zero_string_to_nullc(filename); mk_file_name(filename, nn_filenos[i]); 
        unlink(filename);
      }
    }
  }
  /*------------------------------------*/
  rs_munmap(X, nX);
  free_if_non_null(dld_buf);
  for ( int i = 0; i < MAX_NUM_FLDS_TO_LOAD; i++ ) { 
    rs_munmap(txt_X[i], txt_nX[i]);
    rs_munmap(key_X[i], key_nX[i]);
    rs_munmap(off_X[i], off_nX[i]);
    rs_munmap(len_X[i], len_nX[i]);
  }
  status = chdir(g_cwd); cBYE(status);
  return(status);
}
