extern int
core_pr_flds(
	     int tbl_id,
	     const char *str_flds,
	     char *cfld_X,
	     long long lb,
	     long long ub,
	     long long nR,
	     FILE *ofp
	     )
;
//----------------------------
extern int
core_pr_fld(
	    int tbl_id,
	    int fld_id,
	    FLD_REC_TYPE fld_rec,
	    FLD_REC_TYPE nn_fld_rec,
	    char *cfld_X,
	    long long lb,
	    long long ub,
	    long long nR,
	    FILE *ofp
	    )
;
//----------------------------
extern int 
pr_fld(
       const char *tbl,
       const char *fld,
       const char *filter,
       FILE *ofp
       )
;
//----------------------------
