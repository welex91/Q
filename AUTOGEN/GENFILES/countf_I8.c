#include <stdio.h>
#include <stdbool.h>
#include "constants.h"
#include "macros.h"
// START FUNC DECL
int
countf_I8(
		 int *src_fld, /* [src_nR] */
		 long long *fk_fld, /* [src_nR] */
		 long long src_nR,
		 long long * restrict cnt, /* [dst_nR] */
		 int dst_nR,
		 bool safe_mode
		 )
// STOP FUNC DECL
{
  int status = 0;
  if ( safe_mode == false ) {
    for ( long long i = 0; i < src_nR; i++ ) {
      long long idx = fk_fld[i];
      int idxI4 = (int )idx;
      int val  = src_fld[i];
      cnt[idxI4] += val;
    }
  }
  else {
    for ( long long i = 0; i < src_nR; i++ ) {
      long long idx = fk_fld[i];
      if ( ( idx < 0 ) || ( idx >= dst_nR ) ) { go_BYE(-1); }
      int idxI4 = (int )idx;
      int val  = src_fld[i];
      cnt[idxI4] += val;
    }
  }
 BYE:
  return status ;
}
