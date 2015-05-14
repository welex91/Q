// START FUNC DECL
void
conv_I8_to_I2( 
			    long long *in, 
			    int nR, 
			    short * restrict out
			    )
// STOP FUNC DECL
{
  for ( long long i = 0; i < nR; i++ ) { 
    *out = (short) *in;
    in++;
    out++;
  }
}

