extern int
decide_on_parallelism(
		      char *distribution,
		      char *X,
		      int tbl_id,
		      int fld_id,
		      long long nR,
		      long long *ptr_minI8,
		      long long *ptr_maxI8,
		      bool *ptr_use_par_sort
		      )
;
//----------------------------
extern int 
fop(
    char *tbl,
    char *fld,
    char *str_op_spec
    )
;
//----------------------------
