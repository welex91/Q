extern int
int_get_meta(
	     int tbl_id,
	     int fld_id,
	     char *attr,
	     char *value
	     )
;
//----------------------------
extern int
get_meta(
	 char *tbl,
	 char *fld,
	 char *attr,
	 char *rslt_buf,
	 int sz_rslt_buf // TODO P3: Use this to check for buffer overflow
	 )
;
//----------------------------
