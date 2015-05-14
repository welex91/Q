#include <stdint.h>
#include <unistd.h>
#include "crc32.h"
// START FUNC DECL
void
crc32_I8( 
		    unsigned long long *in, 
		    long long nR, 
		    uint32_t *out
		    )
// STOP FUNC DECL
{
  int sz = sizeof(long long);
  for ( long long i = 0; i < nR; i++ ) { 
    long long inval = in[i];
    const uint8_t *data_ptr = (const uint8_t *)(&inval);
    uint32_t outval = crc32_calc_buffer(data_ptr, sz);
    out[i] = outval;
  }
}
