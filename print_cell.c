#include "qtypes.h"
#include "auxil.h"
#include "print_cell.h" 
#include "mk_dict.h" 

// last review 11/5/2013
// START FUNC DECL
int
print_cell(
	   char *dld_buf,
		 int buflen,
	   FLD_TYPE fldtype,
	   FLD_PROPS_TYPE *ptr_fld_prop,
	   FILE *fp,
	   FILE *nn_fp, 
	   FILE *len_fp, 
	   int n_keys,
	   char *key_X,
	   char *txt_X,
	   char *off_X,
	   char *len_X,
	   HT_REC_TYPE *ht,
	   int sz_ht,
	   int *ptr_n_ht
	   )
// STOP FUNC DECL
{
  int status = 0;
  int valI4; 
  char valI1; 
  short valI2; 
  long long valI8; 
  unsigned long long uvalI8; 
  float valF4; 
  double valF8;
  char c_nn;
  int n_ht = *ptr_n_ht;
  char nullc = '\0';

  if ( ptr_fld_prop->is_all_def ) { if ( nn_fp != NULL ) { go_BYE(-1); } }
  if ( fldtype == SV ) { if ( len_fp == NULL ) { go_BYE(-1); } }
  if ( fldtype != SV ) { if ( len_fp != NULL ) { go_BYE(-1); } }
  if ( dld_buf == NULL ) { go_BYE(-1); }
  if ( fp  == NULL ) { go_BYE(-1); }

  // Note that buflen can be zero if field allows null values 
  if ( ptr_fld_prop->is_lkp ) { 
    if ( buflen >= MAX_LEN_STR ) { 
      fprintf(stderr, "value too long [%s] \n", dld_buf);
      go_BYE(-1);
    }
  }
  else {
    switch ( fldtype ) {
      case I1 : case I2 : case I4 : case I8 : case F4 : case F8 : 
        if ( buflen > 32 ) { 
          fprintf(stderr, "Field too long: [%s] \n", dld_buf);
          fprintf(stderr, "Printing first 64 characters \n\t");
          for ( int i = 0; i < strlen(dld_buf); i++ ) { 
            fprintf(stderr, "%c", dld_buf[i]);
          }
          fprintf(stderr, "\n");
          go_BYE(-1); 
        }
        for ( int i = 0; i < buflen; i++ ) { 
          char c = dld_buf[i];
          if ( ( ( c < '0' ) && ( c > '9' ) ) && ( c != '.' ) && ( c != '-' ) ) {
            fprintf(stderr, "Cannot convert [%s] to numeric\n", dld_buf);
            go_BYE(-1); 
          }
        }
        break;
      case SC : case SV : 
        if ( buflen >= MAX_LEN_STR ) { 
          fprintf(stderr, "Field too long: [%s]\n", dld_buf); 
          go_BYE(-1);
        }
        break;
      default : 
        fprintf(stderr, "fldtype = %d \n", fldtype);
        go_BYE(-1); 
        break;
    }
  }

  /*--- START: Determine out nn value */
  if ( buflen == 0 ) { /* null value */
    if ( ptr_fld_prop->is_all_def ) { 
      fprintf(stderr, "Null value not allowed \n");
      go_BYE(-1); 
    }
    c_nn = FALSE;
    ptr_fld_prop->is_any_null = true;
  }
  else {
    c_nn = TRUE;
  }
  /*--- STOP : Determine out nn value */

  valI1 = valI2 = valI4 = valI8 = 0;
  valF4 = valF8 = 0.0;

  if ( ptr_fld_prop->is_lkp ) {
    if ( c_nn == TRUE ) {
      if ( key_X != NULL ) { /* reading from existing dictionary */
        status = get_from_dict(dld_buf, (long long *)key_X, n_keys, txt_X, 
            (long long *)off_X, (short *)len_X, &valI4);
        cBYE(status);
        if ( valI4 < 0 ) {
          if ( ptr_fld_prop->is_null_if_missing ) {
            c_nn = FALSE;
            valI4 = 0; // null values are set to 0
          }
          else {
            fprintf(stderr, "Could not find %s in dictionary \n", dld_buf);
            go_BYE(-1);
          }
        }
        else {
          c_nn = TRUE;
        }
      }
      else {
        status = add_to_dict(dld_buf, ht, sz_ht, &n_ht, &uvalI8); cBYE(status);
        c_nn = TRUE;
      }
    }
    else {
      uvalI8 = 0;
    }
    if ( key_X != NULL ) { /* reading from existing dictionary */
      fwrite(&valI4, sizeof(int), 1, fp);
    }
    else {
      fwrite(&uvalI8, sizeof(unsigned long long), 1, fp);
    }
  }
  else {
    switch ( fldtype ) {
      case I1 : 
      case I2 : 
      case I4 : 
      case I8 : 
        if ( c_nn == TRUE ) { 
          status = stoI8(dld_buf, &valI8);  
          cBYE(status);
        }
        else {
          valI8 = 0;
          ptr_fld_prop->is_any_null = true;
        }
        switch ( fldtype ) { 
          case I1 : 
            if ( valI8 > SCHAR_MAX ) { go_BYE(-1); }
            if ( valI8 < SCHAR_MIN ) { go_BYE(-1); }
            valI1 = (char)valI8;
            fwrite(&valI1, sizeof(char), 1, fp);
            break;
          case I2 : 
            if ( valI8 > SHRT_MAX ) { go_BYE(-1); }
            if ( valI8 < SHRT_MIN ) { go_BYE(-1); }
            valI2 = (short)valI8;
            fwrite(&valI2, sizeof(short), 1, fp);
            break;
          case I4 : 
            if ( valI8 > INT_MAX ) { go_BYE(-1); }
            if ( valI8 < INT_MIN ) { go_BYE(-1); }
            valI4 = (int)valI8;
            fwrite(&valI4, sizeof(int), 1, fp);
            break;
          case I8 : 
            fwrite(&valI8, sizeof(long long), 1, fp);
            break;
          default :
            go_BYE(-1);
            break;
        }
        break;
      case F4 : 
        if ( c_nn == TRUE ) { 
          status = stoF4(dld_buf, &valF4); 
          if ( status < 0 ) { break; }
        }
        else {
          valF4 = 0;
        }
        fwrite(&valF4, sizeof(float), 1, fp);
        break;
      case F8 : 
        if ( c_nn == TRUE ) { 
          status = stoF8(dld_buf, &valF8); 
          if ( status < 0 ) { break; }
        }
        else {
          valF8 = 0;
        }
        fwrite(&valF8, sizeof(double), 1, fp);
        break;
      case SC : 
        if ( ptr_fld_prop->is_trunc ) { 
          buflen = ptr_fld_prop->maxlen;
        }
        if ( buflen > ptr_fld_prop->maxlen ) {
          fprintf(stderr, "max    length of string is %d \n", 
              ptr_fld_prop->maxlen);
          fprintf(stderr, "actual length of string is %d \n", buflen);
          go_BYE(-1);
        }
        fwrite(dld_buf, buflen, 1, fp);
        int padding = ptr_fld_prop->maxlen - buflen + 1;
        for ( int i = 0; i < padding; i++ ) { 
          fwrite(&nullc,               1, 1, fp);
        }
        if ( *dld_buf == '\0' ) { c_nn = FALSE; } else { c_nn = TRUE; } 
        break;
      case SV : 
        if ( ptr_fld_prop->maxlen > 0 ) {
          if ( buflen > ptr_fld_prop->maxlen ) {
            fprintf(stderr, "max    length of string is %d \n", 
                ptr_fld_prop->maxlen);
            fprintf(stderr, "actual length of string is %d \n", buflen);
            go_BYE(-1);
          }
        }
        if ( len_fp == NULL ) { go_BYE(-1); }
        if ( buflen > 32767 ) { go_BYE(-1); }
        fwrite(&buflen, sizeof(short), 1, len_fp);
        if ( buflen > 0 ) { 
          fwrite(dld_buf, buflen, 1, fp);
        }
        fwrite(&nullc,               1, 1, fp);
        break;
      default : 
        go_BYE(-1);
        break;
    }
  }
  if ( status < 0 ) { go_BYE(-1); }
  // fprintf(stderr, "[%s]:%d\n", dld_buf, c_nn);
  if ( ptr_fld_prop->is_all_def == false ) { 
    fwrite(&c_nn, sizeof(char), 1, nn_fp);
  }
  zero_string_to_nullc(dld_buf);
  *ptr_n_ht = n_ht;
BYE:
  if ( status < 0 ) { 
    fprintf(stderr, "Bad Value: "); 
    for ( int i = 0; i < min(64, strlen(dld_buf)); i++ ) { 
      fprintf(stderr, "%c", dld_buf[i]);
    }
    fprintf(stderr, "\n");
  }
  return(status);
}
