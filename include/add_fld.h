extern int
get_empty_fld(
    int tbl_id,
    const char *fld,
    FLD_REC_TYPE *flds,
    int n_fld,
    int *ptr_fld_id
    )
;
//----------------------------
extern int
add_fld(
	int tbl_id,
	const char *fld,
	int ddir_id,
	int fileno,
	int *ptr_fld_id,
	FLD_REC_TYPE *ptr_fld_rec
	)
;
//----------------------------
extern int
ext_add_fld(
	    const char *tbl,
	    const char *fld,
	    const char *fldspec
	    )
;
//----------------------------
