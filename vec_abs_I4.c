#include <math.h>
// START FUNC DECL
void
vec_abs_I4( 
			    int *in, 
			    int nR, 
			    int *out
			    )
// STOP FUNC DECL
{
  int i;
  for ( i = 0; i < nR; i++ ) { 
		if ( *in < 0 ) { 
      *out = -1 * *in;
		}
		else {
			*out = *in;
		}
    in++;
    out++;
  }
}

