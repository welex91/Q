#include "qtypes.h"
#include "hash_string.h"
#include "is_tbl.h"
#include "aux_meta.h"
#include "is_fld.h"
#include "mix.h"

#include "meta_globals.h"
// START FUNC DECL
int
is_fld(
    const char *tbl,
    int in_tbl_id,
    const char *fld,
    int *ptr_fld_id,
    FLD_REC_TYPE *ptr_fld_rec,
    int *ptr_nn_fld_id,
    FLD_REC_TYPE *ptr_nn_fld_rec
    )
// STOP FUNC DECL
{
  int status = 0;
  int idx, startloc, tbl_id, fld_id = INT_MIN, nn_fld_id = INT_MIN;
  unsigned int hashval;
  TBL_REC_TYPE  tbl_rec;
  FLD_REC_TYPE fld_rec, nn_fld_rec;

  if ( ptr_fld_id     != NULL ) { *ptr_fld_id = INT_MIN; }
  if ( ptr_fld_rec    != NULL ) { zero_fld_rec(ptr_fld_rec); }
  if ( ptr_nn_fld_id  != NULL ) { *ptr_nn_fld_id = INT_MIN; }
  if ( ptr_nn_fld_rec != NULL ) { zero_fld_rec(ptr_nn_fld_rec); }

  // Provide either tbl or in_tbl_id but not both
  if ( in_tbl_id < 0 ) { 
    status = is_tbl(tbl, &tbl_id, &tbl_rec); cBYE(status);
    if ( tbl_id < 0 ) { goto BYE; }
  }
  else {
    if ( tbl != NULL ) { go_BYE(-1); }
    tbl_id = in_tbl_id;
  }
  status = hash_string_UI4(fld, &hashval); cBYE(status);
  hashval = mix_I8(((unsigned long long)tbl_id << 32) | hashval);
  idx = hashval % g_n_ht_fld;
  startloc = g_ht_fld[idx].val;
  if ( startloc < 0 ) { startloc = 0; }

  for ( int iter = 0; iter < 2; iter++ ) { 
    int lb, ub;
    if ( fld_id >= 0 ) { break; }
    switch ( iter ) { 
      case 0 : lb = startloc; ub = g_n_fld; break; 
      case 1 : lb = 0; ub = startloc; break;
      default : go_BYE(-1); break;
    }
    for ( int i = lb; i < ub; i++ ) { 
      if ( g_flds[i].tbl_id != tbl_id ) { continue; }
      if ( strcmp(g_flds[i].name, fld) == 0 ) {
        fld_id = i;
        fld_rec = g_flds[i];
        nn_fld_id = g_flds[i].nn_fld_id;
        nn_fld_id = nn_fld_id;
        if ( nn_fld_id >= 0 ) { 
          nn_fld_rec = g_flds[nn_fld_id];
        }
        break;
      }
    }
  }
BYE:
  if ( ptr_fld_id     != NULL ) { *ptr_fld_id     = fld_id; }
  if ( ptr_fld_rec    != NULL ) { *ptr_fld_rec    = fld_rec; }
  if ( ptr_nn_fld_id  != NULL ) { *ptr_nn_fld_id  = nn_fld_id; }
  if ( ptr_nn_fld_rec != NULL ) { *ptr_nn_fld_rec = nn_fld_rec; }
  return(status);
}
