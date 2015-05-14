#include "qtypes.h"
#include "auxil.h"
#include "dbauxil.h"
#include "aux_meta.h"
#include "extract_S.h"

#define MAX_LEN 32

int
conv_x(
       char *aux_info,
       char *ptr_x
       )
{
	int status = 0;
	bool all_digits = true;
	char x = 0; *ptr_x = 0;
	for ( int i = 0; i < strlen(aux_info); i++ ) { 
		if ( !isdigit(aux_info[i]) ) { all_digits = false; break; }
	}
	if ( all_digits ) { 
		int itemp;
		status = stoI4(aux_info, &itemp); cBYE(status);
		if ( ( itemp <= 0 ) || ( itemp >= 128 ) ) { go_BYE(-1); }
		x = (char)itemp;
	}
	else {
		if ( strcasecmp(aux_info, "comma") == 0 ) { 
			x = ',';
		}
		else if ( strcasecmp(aux_info, "opensquare") == 0 ) { 
			x = '[';
		}
		else if ( strcasecmp(aux_info, "closesquare") == 0 ) { 
			x = ']';
		}
		else if ( strcasecmp(aux_info, "opencurly") == 0 ) { 
			x = '{';
		}
		else if ( strcasecmp(aux_info, "closecurly") == 0 ) { 
			x = '}';
		}
		else if ( strcasecmp(aux_info, "comma") == 0 ) { 
			x = ',';
		}
		else if ( strcasecmp(aux_info, "tab") == 0 ) { 
			x = '\t';
		}
		else if ( strcasecmp(aux_info, "ctrl_a") == 0 ) { 
			x = 1; 
		}
		else if ( strcasecmp(aux_info, "ctrl_z") == 0 ) { 
			x = 26; 
		}
		else {
			go_BYE(-1);
		}
	}
	*ptr_x = x;
BYE:
	return(status);
}

// START FUNC DECL
int
process_aux_info(
		 char *in_aux_info, 
		 bool *ptr_ignore_hdr, 
		 char *ptr_fld_sep, 
		 char *ptr_fld_open,
		 char *ptr_fld_close,
		 char *ptr_rec_delim
		 )
// STOP FUNC DECL
{
  int status = 0;
  char rec_delim = '\n'; // default
  char fld_sep   = ','; // default 
  char fld_open  = '"'; // default 
  char fld_close = '"'; // default 
  bool ignore_hdr = false;
  bool is_null; char aux_info[MAX_LEN]; zero_string(aux_info, MAX_LEN);

  if ( ( in_aux_info != NULL ) && ( *in_aux_info != '\0' ) ) {
    status = chk_aux_info(in_aux_info); cBYE(status);
    zero_string(aux_info, MAX_LEN);
    status = extract_S(in_aux_info, "ignore_hdr=[", "]", aux_info, MAX_LEN, &is_null);
    if ( is_null ) { 
      ignore_hdr = false;
    }
    else {
      if ( strcasecmp(aux_info, "true") == 0 ) { 
	ignore_hdr = true;
      }
      else if ( strcasecmp(aux_info, "false") == 0 ) { 
	ignore_hdr = false;
      }
      else {
	go_BYE(-1);
      }
    }
    //---------------------------------------------------------------
    zero_string(aux_info, MAX_LEN);
    status = extract_S(in_aux_info, "fld_sep=[", "]", aux_info, MAX_LEN, &is_null);
    if ( !is_null ) { status = conv_x(aux_info, &fld_sep); cBYE(status); }
    //---------------------------------------------------------------
    zero_string(aux_info, MAX_LEN);
    status = extract_S(in_aux_info, "fld_open=[", "]", aux_info, MAX_LEN, &is_null);
    if ( !is_null ) { status = conv_x(aux_info, &fld_open); cBYE(status); }
    //---------------------------------------------------------------
    zero_string(aux_info, MAX_LEN);
    status = extract_S(in_aux_info, "fld_close=[", "]", aux_info, MAX_LEN, &is_null);
    if ( !is_null ) { status = conv_x(aux_info, &fld_close); cBYE(status); }
    //---------------------------------------------------------------
  }
  *ptr_ignore_hdr = ignore_hdr;
  *ptr_fld_sep    = fld_sep;
  *ptr_fld_open   = fld_open;
  *ptr_fld_close  = fld_close;
  *ptr_rec_delim  = rec_delim;
 BYE:
  return status ;
}
