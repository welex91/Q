extern int 
lkp_sort(
	char *t1,
	char *f1,
	char *t2,
	char *cnt, /* t2[i] is the number of times t1.f1 has value i */
	/* Hence, t1.f1 < num_rows(t2) */
	char *idx_f1,
	char *srt_f1
	)
;
//----------------------------
