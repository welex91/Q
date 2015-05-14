#include <stdint.h>
#include <unistd.h>
#include "crc32.h"
// START FUNC DECL
void
crc32_I4( 
		    unsigned int *in, 
		    long long nR, 
		    uint32_t *out
		    )
// STOP FUNC DECL
{
  int sz = sizeof(int);
  for ( long long i = 0; i < nR; i++ ) { 
    int inval = in[i];
    const uint8_t *data_ptr = (const uint8_t *)(&inval);
    uint32_t outval = crc32_calc_buffer(data_ptr, sz);
    out[i] = outval;
  }
}
