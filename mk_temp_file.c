#include <stdio.h>
#include "qtypes.h"
#include "mmap.h"
#include "auxil.h"
#include "dbauxil.h"
#include "mk_file.h"
#include "open_file_in_dir.h"
#include "mk_temp_file.h"
#include "meta_globals.h"

extern DDIR_REC_TYPE *g_ddirs; 
extern char g_cwd[MAX_LEN_DIR_NAME+1];

// START FUNC DECL
bool 
space_in_dir(
    char *dir,
    unsigned long long *ptr_free_space
    )
// STOP FUNC DECL
{
  int status = 0;
  if ( ( dir == NULL ) || ( *dir == '\0' ) ) { go_BYE(-1); }
  status = get_disk_space(dir, ptr_free_space, "free_space"); cBYE(status);
  // fprintf(stderr, "free space in %s = %u \n", dir, *ptr_free_space);
BYE:
  return status;
}

// START FUNC DECL
int
mk_temp_file(
    unsigned long long filesz,
    int *ptr_ddir_id,
    int *ptr_fileno
    )
// STOP FUNC DECL
{
  int status = 0;
  char *dir = NULL;
  int ddir_id = 0;

  if ( filesz <= 0 ) { go_BYE(-1); }

  *ptr_fileno = -1;

  dir = g_ddirs[ddir_id].name;
  if ( dir == NULL ) { go_BYE(-1); }
  // Check if you have enough space
  unsigned long long free_space = 0; 
  unsigned long long reserve = 1024*1048576; /* leave 1 GB */
  status = space_in_dir(dir, &free_space); cBYE(status);
  if ( (filesz + reserve) > free_space ) { 
    fprintf(stderr, "insufficient space (%llu) in %s \n", 
	(unsigned long long)free_space, dir); 
    fprintf(stderr, "need (%llu) plus (%llu) reserve \n",
	(unsigned long long)filesz, 
	(unsigned long long)reserve);
    go_BYE(-1); 
  }
  // Make file name 
  char filename[32]; zero_string(filename, 32);

  int l_max_fileno = get_max_fileno();
  mk_file_name(filename, l_max_fileno);
  // Make empty file with that name 
  status = open_file_in_dir(g_cwd, dir, filename, filesz); cBYE(status);
  // Stretch it to appropriate size
  status = mk_file(g_cwd, dir, filename, filesz); cBYE(status);
  *ptr_fileno = l_max_fileno;
  *ptr_ddir_id = ddir_id;
BYE:
  return(status);
}
