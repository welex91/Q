/* Eliminates the first n lines */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "constants.h"
#include "macros.h"
#include "behead.h"
#include "auxil.h"

#define MAXLINE   65536 // max length of line
// START FUNC DECL
int
behead(
    char *infile, /* input */
    char *opfile, /* output */
    char *str_n /* number of lines to eliminate */
    )
// STOP FUNC DECL
{
  int status = 0;
  FILE *ifp = NULL;
  FILE *ofp = NULL;
  char line[MAXLINE];
  int n, lno; 

  zero_string(line, MAXLINE);
  //-------------------------------------------------------------
  if ( *infile  == '\0' ) {
    ifp = stdin;
  }
  else { 
    ifp = fopen(infile, "r");
    return_if_fopen_failed(ifp, infile, "r");
  }
  //-------------------------------------------------------------
  if ( *opfile  == '\0' ) {
    ofp = stdout;
  }
  else { 
    ofp = fopen(opfile, "w");
    return_if_fopen_failed(ofp, opfile, "w");
  }
  if ( ( *infile != '\0' ) && ( *opfile != '\0' ) ) {
    if ( strcmp(infile, opfile) == 0 ) { go_BYE(-1); } 
  }

  //-------------------------------------------------------------
  status = stoI4(str_n, &n); cBYE(status);
  for ( lno = 0; ; lno++ ) {
    if ( fgets(line, MAXLINE, ifp) == NULL ) { break; }
    if ( lno < n ) { continue; }
    fprintf(ofp, "%s", line);
    zero_string_to_nullc(line);
  }
BYE:
  if ( *infile  != '\0' ) {
    fclose_if_non_null(ifp);
  }
  if ( *opfile  != '\0' ) {
    fclose_if_non_null(ofp);
  }
  return(status);
}
