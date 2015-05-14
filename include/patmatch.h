extern int
patmatch(
	 char *t1,
	 char *f1, /* value to match */
	 char *brk_fld, /* session break field */
	 char *out_fld, /* condition field to be created */
	 char *tp, /* table that identifies pattern */
	 char *pat_fld, /* patfld[i] = ith member of pattern */
	 char *lb_fld, /* lb[i] = min number of times patfld[i] should occur */
	 char *ub_fld /* ub[i] = max number of times patfld[i] should occur */
	 )
;
//----------------------------
