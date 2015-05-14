extern int 
ext_approx_quantile(
   char *tbl,
   char *fld,
   char *cfld,
   char *outtbl,
   char *str_num_q,
   char *str_eps,
   int *ptr_is_good
   )
;
//----------------------------
extern int 
approx_quantile(
		int * x,
		char * cfld,
		long long siz,
		int num_quantiles,
		double eps,
		int *y,
		long long y_siz,
		int *ptr_estimate_is_good
		)
;
//----------------------------
