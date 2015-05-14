#include <stdlib.h>
// START FUNC DECL
int
s_to_f_random___XTYPE__(
    __ITYPE__ *X,
    const long long nX,
    const __ITYPE__ lb,
    const __ITYPE__ ub,
    const long long seed
    )
// STOP FUNC DECL
{
  int status = 0;
  if ( seed != 0 ) {
    srand48(seed);
  }
  double range = (ub - lb) + 1;
  for ( long long i = 0; i < nX; i++ ) {
    double dtemp = drand48();
    dtemp *= range;
    __ITYPE__ val = (__ITYPE__)roundl(dtemp);
    val += lb;
#ifdef DEBUG
    if ( ( val >= ub ) || ( val < lb ) ) { go_BYE(-1); }
#endif
    X[i] = val;
  }
BYE:
  return status;
}
