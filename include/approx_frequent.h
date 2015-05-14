extern int 
ext_approx_frequent(
   char *tbl,
   char *fld,
   char *cfld,
   char *outtbl,
   char *str_min_freq,
   char *str_max_err,
   int *ptr_is_good
   )
;
//----------------------------
extern int 
approx_frequent (
		 int * x, 
		 char * cfld,
		 long long siz, 
		 long long min_freq, 
		 long long err, 
		 int * y, 
		 int * f, 
		 long long out_siz,
		 long long * ptr_len,
		 int * ptr_estimate_is_good
		 )
;
//----------------------------
