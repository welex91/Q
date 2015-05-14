extern int hop_sort_compare(
		     const void *in1, 
		     const void *in2
		     )
;
//----------------------------
extern int
setup_ht_dict(
	      HT_REC_TYPE **ptr_ht, 
	      int *ptr_sz_ht, 
	      int *ptr_n_ht
	      )
;
//----------------------------
extern int
add_to_dict(
	    char *inval,
	    HT_REC_TYPE *ht,
	    int sz_ht,
	    int *ptr_n_ht,
	    unsigned long long *ptr_outval

	    )
;
//----------------------------
extern int dump_ht(
	    HT_REC_TYPE *ht,
	    int sz_ht,
	    int n_ht,
	    char *data_dir,
	    char *chrfile,
	    char *keyfile,
	    char *lenfile,
	    char *offfile
	    )
;
//----------------------------
extern int
get_from_dict(
	      char *inval,
	      long long *keys, /* [n_keys] */
	      int n_keys,
	      char *text,
	      long long *offsets, /* [n_keys] */
	      short *lens, /* [n_keys] */
	      int *ptr_idx
	      )
;
//----------------------------
