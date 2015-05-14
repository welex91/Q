extern int 
mk_ldb_dict(
	    char *infile,
	    char *str_fld_sep,
	    char *ldb_dict,
	    char *str_mode, /* read, write, append */
	    char *joinfile, /* to store join key if provided */
	    char *outfile, /* to store outputs as I4 */
	    char *options, 
	    char *in_q_data_dir
	    )
;
//----------------------------
