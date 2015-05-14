// START FUNC DECL
void
concat_I2_I2_to_I4(
    unsigned short *X,
    unsigned short *Y,
    long long n,
    unsigned int *Z
    )
// STOP FUNC DECL
{
  unsigned int   tmp1_UI4, tmp2_UI4;
  unsigned short tmp1_UI2, tmp2_UI2;

  for ( long long i = 0; i < n; i++ ) { 
    tmp1_UI2 = *X;
    tmp2_UI2 = *Y;

    tmp1_UI4 = (unsigned int )tmp1_UI2;
    tmp2_UI4 = (unsigned int )tmp2_UI2;

    *Z = (tmp1_UI4 << 16) | tmp2_UI4;
    X++;
    Y++;
    Z++;
  }
}
