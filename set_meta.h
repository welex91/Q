extern int set_min_max_sum(
		    const char *attr, 
		    const char *value, 
		    int fld_id
		    )
;
//----------------------------
extern int
int_set_meta(
	     int tbl_id,
	     int fld_id,
	     const char *attr,
	     const char *value,
	     bool is_internal
	     )
;
//----------------------------
extern int
set_meta(
	 const char *tbl,
	 const char *fld,
	 const char *attr,
	 const char *value
	 )
;
//----------------------------
