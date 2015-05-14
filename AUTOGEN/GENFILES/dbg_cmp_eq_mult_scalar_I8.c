// START FUNC DECL
void
dbg_cmp_eq_mult_scalar_I8( 
			      long long *invals, 
			      long long n1, 
			      long long *svals, 
			      int n_svals,
			      char * restrict out
			       )
// STOP FUNC DECL
{
  /* Assumption: in2 is sorted in ascending order */
  /* TODO: Can we flip loop order to get vectorization? */
//  long long minval = svals[0];
//  long long maxval = svals[n_svals-1];

#pragma simd
  for ( long long i = 0; i < n1; i++ ) { 
    out[i] = 0;
  }
  for ( int j = 0; j < n_svals; j++ ) { 
    char *l_out = out;
    long long *l_in = invals;
    register long long svals_j = svals[j];
#pragma simd
    for ( long long i = 0; i < n1; i++ ) { 
      if ( *l_in == svals_j ) {
	*l_out = 1;
      }
      l_out++;
      l_in++;
    }
  }
}
