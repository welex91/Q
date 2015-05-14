extern int
read_meta_data(
	       char *infile,
	       char flds[MAX_NUM_FLDS_TO_LOAD][MAX_LEN_FLD_NAME+1],
	       FLD_TYPE fldtype[MAX_NUM_FLDS_TO_LOAD],
	       FLD_PROPS_TYPE fld_props[MAX_NUM_FLDS_TO_LOAD],
	       char dicts[MAX_NUM_FLDS_TO_LOAD][MAX_LEN_TBL_NAME+1],
	       int *ptr_n_flds
	       )
;
//----------------------------
