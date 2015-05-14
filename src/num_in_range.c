#include "qtypes.h"
#include "mmap.h"
#include "auxil.h"
#include "dbauxil.h"
#include "aux_meta.h"
#include "add_fld.h"
#include "is_tbl.h"
#include "is_fld.h"
#include "mk_temp_file.h"
#include "add_tbl.h"
#include "del_tbl.h"
#include "num_in_range.h"
#include "meta_globals.h"
#include "assign_I4.h"
#include "bin_search_I4.h"
#include "get_meta.h"
#include "f_to_s.h"

// last review 9/11/2013
//---------------------------------------------------------------
// START FUNC DECL
int 
num_in_range(
    char *t1,
    char *f1,
    char *t2, /* We expect this table to be small */
    char *lb,
    char *ub,
    char *cnt,
    char *rslt_buf
    )
// STOP FUNC DECL
{
  int status = 0;
  char *f1_X = NULL; size_t f1_nX = 0;
  char *lb_X = NULL; size_t lb_nX = 0;
  char *ub_X = NULL; size_t ub_nX = 0;
  char *cnt_X = NULL; size_t cnt_nX = 0;
  int t1_id = INT_MIN, t2_id = INT_MIN;
  int f1_id = INT_MIN, lb_id = INT_MIN, ub_id = INT_MIN, cnt_id = INT_MIN;
  int nn_f1_id = INT_MIN, nn_lb_id = INT_MIN, nn_ub_id = INT_MIN;
  TBL_REC_TYPE t1_rec, t2_rec;
  FLD_REC_TYPE f1_rec, lb_rec, ub_rec, cnt_rec;
  FLD_REC_TYPE nn_f1_rec, nn_lb_rec, nn_ub_rec;
  long long nR1 = INT_MIN, nR2 = INT_MIN;
  long long *offsets = NULL;
#define BUFLEN 32
  char f1_buf[BUFLEN], lb_ub_buf[BUFLEN];
  int ddir_id = -1, fileno = -1 ;
  FLD_TYPE cnt_fldtype = I4;
  int fldsz = 0; size_t filesz = 0;
  //----------------------------------------------------------------
  if ( ( t1 == NULL ) || ( *t1 == '\0' ) ) { go_BYE(-1); }
  if ( ( f1 == NULL ) || ( *f1 == '\0' ) ) { go_BYE(-1); }
  if ( ( t2 == NULL ) || ( *t2 == '\0' ) ) { go_BYE(-1); }
  if ( ( lb == NULL ) || ( *lb == '\0' ) ) { go_BYE(-1); }
  if ( ( ub == NULL ) || ( *ub == '\0' ) ) { go_BYE(-1); }
  if ( ( cnt  == NULL ) || ( *cnt == '\0' ) ) { go_BYE(-1); }
  if ( strcmp(t1, t2) == 0 ) { go_BYE(-1); }
  if ( strcmp(lb, ub) == 0 ) { go_BYE(-1); }
  if ( strcmp(ub, cnt) == 0 ) { go_BYE(-1); }
  if ( strcmp(cnt, lb) == 0 ) { go_BYE(-1); }
  zero_string(f1_buf, BUFLEN);
  zero_string(lb_ub_buf, BUFLEN);
  //--------------------------------------------------------
  status = is_tbl(t1, &t1_id, &t1_rec); cBYE(status);
  chk_range(t1_id, 0, g_n_tbl);
  nR1 = t1_rec.nR;
  if ( nR1 > INT_MAX ) { go_BYE(-1); }
  //--------------------------------------------------------
  status = is_fld(NULL, t1_id, f1, &f1_id, &f1_rec, &nn_f1_id, &nn_f1_rec); 
  cBYE(status);
  chk_range(f1_id, 0, g_n_fld);
  status = get_data(f1_rec, &f1_X, &f1_nX, 0); cBYE(status);
  if ( nn_f1_id >= 0 ) { go_BYE(-1); }
  if ( f1_rec.fldtype != I4 ) { go_BYE(-1); }
  //--------------------------------------------------------
  status = is_tbl(t2, &t2_id, &t2_rec); cBYE(status);
  chk_range(t2_id, 0, g_n_tbl);
  nR2 = t2_rec.nR;
  //--------------------------------------------------------
  status = is_fld(NULL, t2_id, lb, &lb_id, &lb_rec, &nn_lb_id, &nn_lb_rec); 
  cBYE(status);
  chk_range(lb_id, 0, g_n_fld);
  status = get_data(lb_rec, &lb_X, &lb_nX, 0); cBYE(status);
  if ( nn_lb_id >= 0 ) { go_BYE(-1); }
  if ( lb_rec.fldtype != I4 ) { cBYE(-1); } 
  //--------------------------------------------------------
  status = is_fld(NULL, t2_id, ub, &ub_id, &ub_rec, &nn_ub_id, &nn_ub_rec); 
  cBYE(status);
  chk_range(ub_id, 0, g_n_fld);
  status = get_data(ub_rec, &ub_X, &ub_nX, 0); cBYE(status);
  if ( nn_ub_id >= 0 ) { go_BYE(-1); }
  if ( ub_rec.fldtype != I4 ) { cBYE(-1); } 
  //--------------------------------------------------------
  /*-- Current implementation assumes that numbers sorted in particular
   * manner. This is checked below */
  status = f_to_s(t1, f1, "is_sorted", f1_buf, BUFLEN); cBYE(status);
  if ( ( strcmp(f1_buf, "ascending") != 0 ) && 
       ( strcmp(f1_buf, "descending") != 0 ) ) { 
    fprintf(stderr , "fld [%s] in tbl [%s] should be sorted\n", f1, t1);
    go_BYE(-1);
  }
  status = f_to_s(t2, lb, "is_sorted", lb_ub_buf, BUFLEN); cBYE(status);
  if ( strcmp(lb_ub_buf, f1_buf) != 0 ) { 
    fprintf(stderr , "Expect fld %s in tbl %s to be sorted ", lb, t2);
    fprintf(stderr , "same as fld %s in tbl %s\n", f1, t2);
    go_BYE(-1);
  }
  status = f_to_s(t2, ub, "is_sorted", lb_ub_buf, BUFLEN); cBYE(status);
  if ( strcmp(lb_ub_buf, f1_buf) != 0 ) { 
    fprintf(stderr , "Expect fld %s in tbl %s to be sorted ", ub, t2);
    fprintf(stderr , "same as fld %s in tbl %s\n", f1, t2);
    go_BYE(-1);
  }
  /* Make space for output */
  cnt_fldtype = I4;
  status = get_fld_sz(cnt_fldtype, &fldsz); cBYE(status);
  filesz = fldsz * nR2;
  status = mk_temp_file(filesz, &ddir_id, &fileno); cBYE(status);
  status = q_mmap(ddir_id, fileno, &cnt_X, &cnt_nX, 1);
  int *cntptr = (int *)cnt_X;
  assign_const_I4(cntptr, nR2, 0);
  long long chk_nR1 = 0;
  //-----------------------------------------------------------
  int *inptr = (int *)f1_X;
  int *lbptr = (int *)lb_X;
  int *ubptr = (int *)ub_X;
  int t2idx = 0;
  int lbval = lbptr[0];
  int ubval = ubptr[0];
  if ( strcmp(f1_buf, "ascending") == 0 ) { 
    for ( long long i = 0; i < nR1; i++ ) { 
      int valI4 = inptr[i];
      if ( valI4 < lbval ) { continue; }
      for ( ; t2idx < nR2 ; ) { 
        if ( valI4 < ubval ) { 
          cntptr[t2idx]++;
          chk_nR1++;
          break;
        }
        t2idx++;
        if ( t2idx >= nR2 ) { break; }
        lbval = lbptr[t2idx];
        ubval = ubptr[t2idx];
        if ( valI4 < lbval ) { break; }
      }
      if ( t2idx == nR2 ) { break; }
    }
  }
  else if ( strcmp(f1_buf, "descending") == 0 ) {
    for ( long long i = 0; i < nR1; i++ ) { 
      int valI4 = inptr[i];
      if ( valI4 >= ubval ) { continue; }
      for ( ; t2idx < nR2 ; ) { 
        if ( valI4 >= lbval ) { 
          cntptr[t2idx]++;
          chk_nR1++;
          break;
        }
        t2idx++;
        if ( t2idx >= nR2 ) { break; }
        lbval = lbptr[t2idx];
        ubval = ubptr[t2idx];
        if ( valI4 >= ubval ) { break; }
      }
      if ( t2idx == nR2 ) { break; }
    }
  }
  else {
    go_BYE(-1);
  }
  sprintf(rslt_buf, "%lld", chk_nR1); // return number of matches

  zero_fld_rec(&cnt_rec); cnt_rec.fldtype  = cnt_fldtype;
  status = add_fld(t2_id, cnt, ddir_id, fileno, &cnt_id, &cnt_rec); cBYE(status);
BYE:
  rs_munmap(f1_X, f1_nX);
  rs_munmap(lb_X, lb_nX);
  rs_munmap(ub_X, ub_nX);
  rs_munmap(cnt_X, cnt_nX);
  free_if_non_null(offsets);
  return(status);
}
