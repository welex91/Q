#include <stdlib.h>
// START FUNC DECL
int
s_to_f_random_I4(
    int *X,
    const long long nX,
    const int lb,
    const int ub,
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
    int val = (int)roundl(dtemp);
    val += lb;
#ifdef DEBUG
    if ( ( val >= ub ) || ( val < lb ) ) { go_BYE(-1); }
#endif
    X[i] = val;
  }
BYE:
  return status;
}
