extern int
read_csv(
	 char *data_dir,
	 char *infile,
	 char fld_sep, 
	 char fld_open, 
	 char fld_close, 
	 char rec_delim, 
	 bool ignore_hdr, /* whether to ignore header or not */
	 char flds[MAX_NUM_FLDS_TO_LOAD][MAX_LEN_FLD_NAME+1],
	 int n_flds,
	 FLD_TYPE fldtype[MAX_NUM_FLDS_TO_LOAD],
	 FLD_PROPS_TYPE fld_props[MAX_NUM_FLDS_TO_LOAD], /* properties of fields */
	 int filenos[MAX_NUM_FLDS_TO_LOAD],
	 int nn_filenos[MAX_NUM_FLDS_TO_LOAD],
	 int len_filenos[MAX_NUM_FLDS_TO_LOAD],
	 HT_REC_TYPE *hts[MAX_NUM_FLDS_TO_LOAD],
	 int sz_hts[MAX_NUM_FLDS_TO_LOAD],
	 int n_hts[MAX_NUM_FLDS_TO_LOAD],
	 int dict_tbl_id[MAX_NUM_FLDS_TO_LOAD],
	 long long *ptr_num_rows
	 )
;
//----------------------------
