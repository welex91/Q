#include "qtypes.h"
#include "auxil.h"
extern int  g_num_cores; // number of cores on this machine
extern char g_docroot[MAX_LEN_DIR_NAME+1];
extern char g_cwd[MAX_LEN_DIR_NAME+1];
extern FILE *g_ofp;
// START FUNC DECL
int
  q_init(
      int argc,
      FILE *ofp
      )
// STOP FUNC DECL
  {
    int status = 0;

  zero_string(g_docroot,    (MAX_LEN_DIR_NAME+1));
  if ( ofp == NULL ) { 
    g_ofp = stdout;
  }
  else {
    g_ofp = ofp;
  }

#ifdef MAC_OSX
  g_num_cores = 1; 
#else
  g_num_cores = get_nprocs();
#endif
  if ( g_num_cores < 1 ) { go_BYE(-1); }
  zero_string(g_cwd, (MAX_LEN_DIR_NAME+1));
  if ( getcwd(g_cwd, MAX_LEN_DIR_NAME) == NULL ) { go_BYE(-1); } 
  if ( ( argc < 2 ) || ( argc > MAX_NUM_ARGS ) ) { go_BYE(-1); }
BYE:
  return(status);
}
