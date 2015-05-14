extern int 
ext_approx_unique(
   char *tbl,
   char *fld,
   char *cfld,
   long long *ptr_num_unique,
   double *ptr_estimate_accuracy_percent,
   int *ptr_estimate_is_good  
   )
;
//----------------------------
extern int 
approx_unique (
	       int *x,
	       char *cfld,
	       long long siz,
	       long long *y,
	       double *ptr_estimate_accuracy_percent,
	       int *ptr_estimate_is_good 
	       )
;
//----------------------------
