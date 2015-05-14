extern int
determine_b_k(
	      double err,
	      int num_quantiles,
	      long long siz,
	      int *ptr_b,
	      int *ptr_k
	      )
;
//----------------------------
extern int 
approx_quantile(
		int *x, /* input data */
		long long siz, /* number of elements */
		int num_quantiles, /* number of quantiles */
		double err, /* acceptable error */
		int *y /* output */
		)
;
//----------------------------
