#
# make with c compiler, using 4rd party .h files and .a files
#
#
CC=gcc
GCCOPTFLAG= -O4
GCCOPTFLAG= -g

LINKER=g++

# PICFLAG=-fPIC: add -fPIC when compiling q.a for shell loadable builtin
PICFLAG=
GCCFLAGS = ${GCCOPTFLAG} -ansi -pedantic -std=gnu99 $(PICFLAG) -Wall -fopenmp
DBG = -DDEBUG 
CFLAGS= ${GCCFLAGS} ${DBG} -I../include -I../AUTOGEN/GENFILES

## FOLLOWING FOR MAC_OSX
# GCCFLG = ${GCCOPTFLAG} -ansi -pedantic -std=c99 $(PICFLAG) -Wall -DMAC_OSX
## ABOVE FOR MAC_OSX

# make variable for compiles with the -I command 
#
#INCLUDES=-I/where/the/header/file/is -I/other/header/files
AUTOGEN_HEADER_DIR=../AUTOGEN/GENFILES
AUTOGEN_SRC_DIR=../AUTOGEN/GENFILES
HEADER_DIR=../include
INCLUDES=-I$(AUTOGEN_HEADER_DIR) -I$(HEADER_DIR) -I${HOME}/local/include
#
# make variable for extra libraries
# link with -L and -l
#
# LIBS=-L/where/the/lib/file/is -L/other/lib/files -lUSR1 -lUSR2 -lOTHER
LIBS=/home/subramon/local/lib
#
#
.PHONY: all clean 

ALL = \
	q \
	ut_webhdfs \
	qhttpd \
	qtils \
	test_driver_qsort  


all: ${ALL}

clean:
	rm -f *.o ${ALL} *.so q.a 
	rm -f incl_f_to_s_*.c ; 
	rm -f ./AUTOGEN/*.o; rm -f orig_meta_globals.c
	make -f ./httpd_Makefile clean

INC1 = $(HEADER_DIR)/constants.h $(HEADER_DIR)/macros.h $(HEADER_DIR)/qtypes.h

RD_META_Q = \
	dbauxil.o \
	auxil.o \
	open_file_in_dir.o  \
	mmap.o \
	mk_file.o \
	logger.o \
	md5c.o \
	mddriver.o \
	hash_string.o \
	MurmurHash3.o \
	mix.o \
	extract_S.o \
	aux_meta.o \
	url.o \
	\
	get_type_op_fld.o \
	list_files.o \
	dump.o \
	list_tbls.o \
	is_tbl.o \
	is_fld.o \
	is_aux_fld.o \
	tbl_meta.o \
	fld_meta.o \
	get_meta.o \
	get_nR.o \
	meta_data.o  \
	assign_I1.o \
	assign_I2.o \
	sort_asc_I8.o  \
	sort_asc_F8.o  \
        crc32.o


COREQ = \
	q.o \
	q_core.o \
	q_init.o \
	q_batch.o \
	top_n.o \
	compound.o \
	mk_temp_file.o \
	add_tbl.o \
	add_fld.o \
	add_aux_fld.o \
	del_tbl.o \
	del_fld.o \
	set_meta.o \
	unset_meta.o \
	drop_aux_fld.o \
	rename_fld.o \
	rename_tbl.o \
	f_to_s.o \
	vec_f_to_s.o \
	f1f2_to_s.o \
	pr_fld.o \
	pr_fld_SC.o \
	pr_fld_SV.o \
	bindmp.o \
	mk_hashes_I1.o \
	mk_hashes_I2.o \
	mk_hashes_I4.o \
	mk_hashes_I8.o \
	permute_I4.o \
	permute_I8.o \
	saturate_I1.o \
	saturate_I2.o \
	saturate_I4.o \
	saturate_I8.o \
	set_val.o \
	get_val.o \
	read_meta_data.o \
	read_csv.o \
	print_cell.o \
	aux_dld.o \
	dld.o \
	binld.o \
	wisifxthenyelsez.o \
	stride.o \
	s_to_f.o \
	vec_s_to_f.o \
	pack.o \
	unpack.o \
	find_largest_leq_I4.o \
	find_smallest_geq_I4.o \
	find_largest_leq_I8.o \
	find_smallest_geq_I8.o \
	lkp_sort.o \
	rng_sort.o \
	num_in_range.o \
	crossprod.o \
	percentiles.o \
	app_tbl.o \
	f1opf2_shift.o \
	count_vals.o \
	mk_bins.o \
	f1f2opf3.o \
	vec_f1f2opf3.o \
	is_a_in_b.o \
	dir_is_a_in_b.o \
	mk_dict.o \
	rd_dict.o \
	vec_f1opf2.o \
	conv.o \
	f1opf2_cum.o \
	f1opf2_idx_with_reset.o \
	copy_fld.o \
	copy_tbl.o \
	copy_fld_ranges.o \
	mv_fld.o \
	mk_nn_fld.o \
	break_nn_fld.o \
	spooky_hash.o \
	approx_unique.o \
	approx_quantile.o \
	approx_frequent.o \
	sorted_array_to_id_freq.o \
	update_counter.o \
	Collapse.o \
	New.o \
	Output.o \
	determine_b_k.o \
	determine_rho_loc.o \
	regex_match.o \
	f1s1opf2.o \
	f1opf2.o \
	f1opf2f3.o \
	vec_f1s1opf2.o \
	srt_join.o \
	rng_join.o \
	count_ht.o \
	count.o \
	countf.o \
	zero_after_n.o \
	smear.o \
	is_s_in_f.o \
	patmatch.o \
	par_sort_with_bins.o \
	fop.o \
	sortf1f2.o \
	xfer.o \
	dup_fld.o \
	app_fld.o \
	subsample.o \
	patmatch_I1.o \
	patmatch_I2.o \
	patmatch_I4.o \
	extract_I1.o \
	extract_I2.o \
	extract_I4.o \
	extract_I8.o \
	extract_UI8.o \
	s_to_f_const_I1.o \
	s_to_f_const_I2.o \
	s_to_f_const_I4.o \
	s_to_f_const_I8.o \
	s_to_f_const_F4.o \
	s_to_f_random_I4.o \
	s_to_f_random_I8.o  \
	s_to_f_seq_I1.o \
	s_to_f_seq_I2.o \
	s_to_f_seq_I4.o \
	s_to_f_seq_I8.o  \
	pr_fld_I1.o  \
	pr_fld_I2.o  \
	pr_fld_I4.o  \
	pr_fld_I8.o \
	pr_fld_F4.o  \
	pr_fld_F8.o \
	f_to_s_min_I1.o  \
	f_to_s_min_I2.o  \
	f_to_s_min_I4.o  \
	f_to_s_min_I8.o \
	f_to_s_min_F4.o \
	f_to_s_min_F8.o \
	nn_f_to_s_min_I1.o  \
	nn_f_to_s_min_I2.o  \
	nn_f_to_s_min_I4.o  \
	nn_f_to_s_min_I8.o  \
	nn_f_to_s_min_F4.o \
	nn_f_to_s_min_F8.o \
	f_to_s_max_I1.o  \
	f_to_s_max_I2.o  \
	f_to_s_max_I4.o  \
	f_to_s_max_I8.o \
	f_to_s_max_F4.o \
	f_to_s_max_F8.o \
	nn_f_to_s_max_I1.o  \
	nn_f_to_s_max_I2.o  \
	nn_f_to_s_max_I4.o  \
	nn_f_to_s_max_I8.o  \
	nn_f_to_s_max_F4.o \
	nn_f_to_s_max_F8.o \
	f_to_s_sum_B.o  \
	f_to_s_sum_I1.o  \
	f_to_s_sum_I2.o  \
	f_to_s_sum_I4.o  \
	f_to_s_sum_I8.o \
	f_to_s_sum_F4.o \
	f_to_s_sum_F8.o \
	nn_f_to_s_sum_I1.o  \
	nn_f_to_s_sum_I2.o  \
	nn_f_to_s_sum_I4.o  \
	nn_f_to_s_sum_I8.o  \
	nn_f_to_s_sum_F4.o \
	nn_f_to_s_sum_F8.o  \
	xfer_SC_I4.o \
	xfer_SC_I8.o \
	xfer_I1_I4.o \
	xfer_I2_I4.o \
	xfer_I4_I4.o \
	xfer_I8_I4.o \
	xfer_F4_I4.o \
	xfer_F8_I4.o  \
	xfer_I1_I8.o \
	xfer_I2_I8.o \
	xfer_I4_I8.o \
	xfer_I8_I8.o \
	xfer_F4_I8.o \
	xfer_F8_I8.o  \
	qsort_asc_I1.o \
	qsort_asc_I4.o \
	qsort_asc_I8.o \
	qsort_dsc_I4.o \
	qsort_dsc_I8.o \
	qsort_with_idx_int.o \
	qsort_with_idx_longlong.o  \
	qsort_asc_val_I4_idx_I4.o \
	qsort_asc_val_I4_idx_I8.o \
	qsort_asc_val_I8_idx_I4.o \
	qsort_asc_val_I8_idx_I8.o  \
	qsort_dsc_val_I4_idx_I4.o \
	qsort_dsc_val_I4_idx_I8.o \
	qsort_dsc_val_I8_idx_I4.o \
	qsort_dsc_val_I8_idx_I8.o  \
	sort_asc_I4.o \
	sort_dsc_I4.o \
	sort_asc_I8.o \
	sort_dsc_I8.o \
	sort_asc_F4.o \
	sort_dsc_F4.o \
	sort_dsc_F8.o \
	core_srt_join_I4_I4_I4.o \
	core_srt_join_I4_I4_I8.o \
	core_srt_join_I8_I4_I4.o \
	core_srt_join_I8_I4_I8.o \
	core_srt_join_I4_I8_I4.o \
	core_srt_join_I4_I8_I8.o \
	core_srt_join_I8_I8_I4.o \
	core_srt_join_I8_I8_I8.o \
	assign_I4.o \
	assign_I8.o \
	assign_F4.o \
	assign_F8.o \
	is_sorted_alldef_I1.o \
	is_sorted_alldef_I2.o \
	is_sorted_alldef_I4.o \
	is_sorted_alldef_I8.o \
	cmp_lt_or_gt_I1.o \
	cmp_le_or_ge_I1.o \
	cmp_gt_and_lt_I1.o \
	cmp_ge_and_le_I1.o \
	cmp_lt_or_gt_I2.o \
	cmp_le_or_ge_I2.o \
	cmp_gt_and_lt_I2.o \
	cmp_ge_and_le_I2.o \
	cmp_lt_or_gt_I4.o \
	cmp_le_or_ge_I4.o \
	cmp_gt_and_lt_I4.o \
	cmp_ge_and_le_I4.o \
	cmp_eq_mult_scalar_I1.o \
	cmp_eq_mult_scalar_I2.o \
	cmp_eq_mult_scalar_I4.o \
	cmp_eq_mult_scalar_I8.o \
	dbg_cmp_neq_mult_scalar_I1.o \
	dbg_cmp_neq_mult_scalar_I2.o \
	dbg_cmp_neq_mult_scalar_I4.o \
	dbg_cmp_neq_mult_scalar_I8.o \
	dbg_cmp_eq_mult_scalar_I1.o \
	dbg_cmp_eq_mult_scalar_I2.o \
	dbg_cmp_eq_mult_scalar_I4.o \
	dbg_cmp_eq_mult_scalar_I8.o \
	opt_cmp_eq_mult_scalar_I1.o \
	opt_cmp_eq_mult_scalar_I2.o \
	opt_cmp_eq_mult_scalar_I4.o \
	opt_cmp_eq_mult_scalar_I8.o \
	add_scalar_I1.o \
	sub_scalar_I1.o \
	mul_scalar_I1.o \
	div_scalar_I1.o \
	rem_scalar_I1.o \
	add_scalar_I2.o \
	sub_scalar_I2.o \
	mul_scalar_I2.o \
	div_scalar_I2.o \
	rem_scalar_I2.o \
	add_scalar_I4.o \
	sub_scalar_I4.o \
	mul_scalar_I4.o \
	div_scalar_I4.o \
	rem_scalar_I4.o \
	add_scalar_I8.o  \
	sub_scalar_I8.o \
	mul_scalar_I8.o \
	div_scalar_I8.o \
	rem_scalar_I8.o \
	add_scalar_F4.o  \
	sub_scalar_F4.o \
	mul_scalar_F4.o \
	div_scalar_F4.o \
	add_scalar_F8.o  \
	sub_scalar_F8.o \
	mul_scalar_F8.o \
	div_scalar_F8.o \
	and_scalar_I1.o \
	or_scalar_I1.o \
	bwise_and_scalar_I4.o \
	bwise_not_and_scalar_I8.o \
	bwise_not_or_scalar_I8.o \
	bwise_and_scalar_I8.o \
	bwise_and_scalar_I1.o \
	bwise_or_scalar_I4.o \
	bwise_or_scalar_I8.o \
	bwise_or_scalar_I1.o \
	bwise_xor_scalar_I4.o \
	bwise_xor_scalar_I8.o \
	bwise_xor_scalar_I1.o \
	cmp_le_scalar_I4.o \
	cmp_ge_scalar_I4.o  \
	cmp_eq_scalar_I4.o \
	cmp_ne_scalar_I4.o \
	cmp_gt_scalar_I4.o \
	cmp_lt_scalar_I4.o \
	cmp_le_scalar_I8.o \
	cmp_ge_scalar_I8.o \
	cmp_eq_scalar_I8.o \
	cmp_ne_scalar_I8.o \
	cmp_lt_scalar_I8.o \
	cmp_gt_scalar_I8.o \
	cmp_le_scalar_F4.o  \
	cmp_ge_scalar_F4.o \
	cmp_eq_scalar_F4.o \
	cmp_ne_scalar_F4.o \
	cmp_lt_scalar_F4.o \
	cmp_gt_scalar_F4.o \
	cmp_le_scalar_F8.o  \
	cmp_ge_scalar_F8.o \
	cmp_eq_scalar_F8.o \
	cmp_ne_scalar_F8.o \
	cmp_lt_scalar_F8.o \
	cmp_gt_scalar_F8.o \
	cmp_le_scalar_I1.o \
	cmp_ge_scalar_I1.o \
	cmp_eq_scalar_I1.o \
	cmp_ne_scalar_I1.o \
	cmp_lt_scalar_I1.o \
	cmp_gt_scalar_I1.o \
	cmp_le_scalar_I2.o \
	cmp_ge_scalar_I2.o \
	cmp_eq_scalar_I2.o \
	cmp_ne_scalar_I2.o \
	cmp_lt_scalar_I2.o \
	cmp_gt_scalar_I2.o \
	shift_left_scalar_I4.o \
	shift_left_scalar_I8.o \
	shift_right_scalar_UI4.o \
	shift_right_scalar_UI8.o \
	conv_I1_to_B.o  \
	conv_B_to_I1.o  \
	conv_F8_to_I4.o  \
	conv_F8_to_I8.o  \
	conv_F8_to_F4.o  \
	conv_I4_to_I1.o  \
	conv_I4_to_I2.o  \
	conv_I4_to_I8.o  \
	conv_I4_to_F4.o  \
	conv_I4_to_F8.o  \
	conv_I8_to_I1.o  \
	conv_I8_to_I2.o  \
	conv_I8_to_I4.o  \
	conv_I8_to_F4.o  \
	conv_I8_to_F8.o  \
	conv_I1_to_I4.o  \
	conv_I1_to_I8.o  \
	conv_F4_to_I4.o  \
	conv_F4_to_I8.o  \
	conv_F4_to_F8.o  \
	nn_conv_F8_to_I4.o  \
	nn_conv_F8_to_I8.o  \
	nn_conv_F8_to_F4.o  \
	nn_conv_I4_to_I1.o  \
	nn_conv_I4_to_I2.o  \
	nn_conv_I4_to_I8.o  \
	nn_conv_I4_to_F4.o  \
	nn_conv_I4_to_F8.o  \
	nn_conv_I8_to_I1.o  \
	nn_conv_I8_to_I2.o  \
	nn_conv_I8_to_I4.o  \
	nn_conv_I8_to_F4.o  \
	nn_conv_I8_to_F8.o  \
	nn_conv_I1_to_I4.o  \
	nn_conv_I1_to_I8.o  \
	nn_conv_F4_to_I4.o  \
	nn_conv_F4_to_I8.o  \
	nn_conv_F4_to_F8.o  \
	not_I4.o  \
	ones_complement_I4.o  \
	ones_complement_I8.o  \
	ones_complement_I1.o  \
	not_I8.o  \
	not_I1.o  \
	incr_I4.o  \
	decr_I4.o  \
	incr_I8.o  \
	decr_I8.o \
	cum_I4_to_I4.o \
	cum_I4_to_I8.o \
	cum_I8_to_I4.o \
	cum_I8_to_I8.o \
	cum_I1_to_I4.o \
	cum_I1_to_I8.o \
	cum_I2_to_I4.o \
	cum_I2_to_I8.o \
	is_s_in_f_seq_I1.o \
	is_s_in_f_seq_I2.o \
	is_s_in_f_seq_I4.o \
	is_s_in_f_seq_I8.o \
	srt_uniform_I4.o  \
	srt_uniform_I8.o  \
	hash_I4.o  \
	hash_I8.o  \
	bitcount_I4.o  \
	bitcount_I8.o  \
        crc32_I4.o \
        crc32_I8.o \
	vec_abs_I4.o \
	vec_abs_F4.o \
	vec_abs_F8.o \
	vec_sqrt_F4.o \
	vec_sqrt_F8.o \
	vec_reciprocal_F4.o \
	vec_reciprocal_F8.o \
	t1f1t2f2opt3f3.o \
	bin_search_I1.o \
	bin_search_I2.o \
	bin_search_I4.o \
	bin_search_UI4.o \
	bin_search_I8.o \
	bin_search_UI8.o \
	which_bin_I4.o \
	which_bin_I8.o \
	countf_I1.o \
	countf_I2.o \
	countf_I4.o \
	countf_I8.o \
	countf_nn_I1.o \
	countf_nn_I2.o \
	countf_nn_I4.o \
	countf_nn_I8.o \
	count_I1.o \
	count_I2.o \
	count_I4.o \
	count_I8.o \
	par_count_I1.o \
	par_count_I2.o \
	par_count_cfld_I1.o \
	par_count_cfld_I2.o \
	par_countf_I1.o \
	par_countf_I2.o \
	par_countf_cfld_I1.o \
	par_countf_cfld_I2.o \
	count_nn_I1.o \
	count_nn_I2.o \
	count_nn_I4.o \
	count_nn_I8.o \
	concat_I2_I2_to_I4.o \
	concat_I4_I4_to_I8.o \
	add2_I2.o \
	sub2_I2.o \
	mul2_I2.o \
	div2_I2.o \
	rem2_I2.o \
	add2_I4.o \
	sub2_I4.o \
	mul2_I4.o \
	div2_I4.o \
	rem2_I4.o \
	shiftleft2_I4.o \
	shiftright2_UI4.o \
	add2_I8.o \
	sub2_I8.o \
	mul2_I8.o \
	div2_I8.o \
	rem2_I8.o \
	shiftleft2_I8.o \
	shiftright2_UI8.o \
	add2_F4.o \
	sub2_F4.o \
	mul2_F4.o \
	div2_F4.o \
	add2_F8.o \
	sub2_F8.o \
	mul2_F8.o \
	div2_F8.o \
	and2_I1.o \
	or2_I1.o \
	a_and_not_b_I1.o \
	bwise_a_and_not_b_I8.o \
	bwise_and2_I4.o \
	bwise_and2_I8.o \
	bwise_and2_I1.o \
	bwise_or2_I4.o \
	bwise_or2_I8.o \
	bwise_or2_I1.o \
	bwise_xor2_I4.o \
	bwise_xor2_I8.o \
	bwise_xor2_I1.o \
	cmp_ge_I1.o \
	cmp_le_I1.o \
	cmp_eq_I1.o \
	cmp_ne_I1.o \
	cmp_gt_I1.o \
	cmp_lt_I1.o \
	cmp_ge_I2.o \
	cmp_le_I2.o \
	cmp_eq_I2.o \
	cmp_ne_I2.o \
	cmp_gt_I2.o \
	cmp_lt_I2.o \
	cmp_ge_I4.o \
	cmp_le_I4.o \
	cmp_eq_I4.o \
	cmp_ne_I4.o \
	cmp_gt_I4.o \
	cmp_lt_I4.o \
	cmp_ge_F4.o \
	cmp_le_F4.o \
	cmp_eq_F4.o \
	cmp_ne_F4.o \
	cmp_gt_F4.o \
	cmp_lt_F4.o \
	cmp_ge_F8.o \
	cmp_le_F8.o \
	cmp_eq_F8.o \
	cmp_ne_F8.o \
	cmp_gt_F8.o \
	cmp_lt_F8.o \
	cmp_ge_I8.o \
	cmp_le_I8.o \
	cmp_eq_I8.o \
	cmp_ne_I8.o \
	cmp_gt_I8.o \
	cmp_lt_I8.o \
	uniq_I4.o  \
	uniq_I8.o  \
	uniq_cnt_I4.o  \
	uniq_cnt_I8.o  \
	uniq_alldef_I4.o  \
	uniq_alldef_I8.o \
	uniq_cnt_alldef_I4.o  \
	uniq_cnt_alldef_I8.o \
	core_wisifxthenyelsez_I4.o \
	core_wisifxthenyelsez_I8.o \
	core_wisifxthenyelsez_I1.o \
	core_wisifxthenyelsez_I2.o \
	core_wisifxthenyelsez_F4.o \
	union_I4.o  \
	union_I8.o  \
	a_minus_b_I4.o  \
	a_minus_b_I8.o  \
	par_sort_with_bins_I4.o  \
	par_sort_with_bins_I8.o  \
	intersection_I4.o  \
	intersection_I8.o 


qhttpd: qhttpd.o $(COREQ) $(RD_META_Q)
	$(LINKER) $(GCCFLAGS) -o $@ $^ -ldl -lm -L$(HOME)/local/lib -lcurl

DEPS = $(HEADER_DIR)/qtypes.h $(HEADER_DIR)/constants.h $(HEADER_DIR)/macros.h

.c.o: $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< 

qwrap.o: qwrap.c
q_core.o: q_core.c
q_init.o: q_init.c
q_batch.o: q_batch.c
q.o: q.c

q: qwrap.o $(COREQ) $(RD_META_Q)
	$(LINKER) $(GCCFLAGS) -o $@ $^ -ldl -lm \
	-fopenmp -lgomp -L$(HOME)/local/lib -lcurl



#	-fopenmp -lgomp -lcurl 

ut_mk_dict: ut_mk_dict.o mk_dict.o MurmurHash3.o \
	auxil.o mmap.o mix.o
	$(CC) $(CFLAGS) -o $@ $^ -ldl -lm -lpthread $(LDFLAGS)  

ut_webhdfs.o : ut_webhdfs.c 
	$(CC) $(CFLAGS) -c ut_webhdfs.c  -I/home/subramon/local/include

ut_webhdfs: ut_webhdfs.o  auxil.o mmap.o assign_I1.o 
	$(CC) $(CFLAGS) -o $@ $^ -ldl -lm -lpthread -L$(HOME)/local/lib -lcurl $(LDFLAGS)  -L/home/subramon/local/lib 

ut_rd_dict: ut_rd_dict.o rd_dict.o MurmurHash3.o \
	auxil.o mmap.o mix.o bin_search_UI8.o 
	$(CC) $(CFLAGS) -o $@ $^ -ldl -lm -lpthread $(LDFLAGS)  

mk_dict.o: mk_dict.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c mk_dict.c

rd_dict.o: rd_dict.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c rd_dict.c


qtils: qtilswrap.o qtils.o time1.o replace_char.o \
	extract_S.o \
	date_to_I4.o \
	tab_split.o \
	aux_meta.o \
	is_tbl.o \
	is_fld.o \
	dbauxil.o \
	auxil.o  mmap.o behead.o qhead.o chk_ascii.o \
	esc_for_latex.o hash_string.o md5c.o mddriver.o \
	hdfs_get.o \
	aux_hdfs.o \
	mk_file.o \
	url.o \
	assign_I1.o \
	asc2bin.o bin2asc.o txt_sub.o sortbindmp.o \
	mix.o \
	extract_I4.o \
	qsort_dsc_I8.o \
	qsort_asc_I8.o \
	mk_hashes_I1.o \
	assign_I1.o \
	assign_I2.o \
	assign_I4.o \
	assign_I8.o \
	mk_hashes_I2.o \
	mk_hashes_I4.o \
	mk_hashes_I8.o \
	qsort_asc_I4.o \
	qsort_dsc_I4.o \
	sort_asc_I4.o \
	sort_asc_I8.o \
	sort_asc_F8.o \
	sort_dsc_I4.o \
	sort2_asc_I4.o \
	sort2_dsc_I4.o \
	sort2_asc_I8.o \
	sort2_dsc_I8.o \
	sort2_asc_F4.o \
	sort2_dsc_F4.o \
	sort3_asc_I4.o \
	sort3_dsc_I4.o \
	sort3_asc_I8.o \
	sort3_dsc_I8.o \
	sort4_asc_I8.o \
	sort4_dsc_I8.o \
	sort3_asc_F4.o \
	sort3_dsc_F4.o 
	$(LINKER) -o $@ $^ -ldl -lm -fopenmp -lgomp -L$(HOME)/local/lib -lcurl

orig_meta_globals.c: orig_meta_globals.h
	cp orig_meta_globals.h orig_meta_globals.c

verbatim_include: verbatim_include.o  mmap.o open_file_in_dir.o
	$(CC) $(CFLAGS) -o $@ $^ 

test_driver_qsort: test_driver_qsort.o \
	qsort_with_idx.o \
	qsort_with_idx_int.o \
	qsort_with_idx_longlong.o \
	qsort_dsc_I4.o  \
	qsort_asc_I4.o  \
	qsort_dsc_I8.o  \
	qsort_asc_I8.o  \
	sort_asc_I4.o sort_dsc_I4.o  \
	sort_asc_I8.o sort_dsc_I8.o  \
	qsort_asc_val_I4_idx_I4.o \
	qsort_asc_val_I4_idx_I8.o \
	qsort_asc_val_I8_idx_I4.o \
	qsort_asc_val_I8_idx_I8.o \
	qsort_dsc_val_I4_idx_I4.o \
	qsort_dsc_val_I4_idx_I8.o \
	qsort_dsc_val_I8_idx_I4.o \
	qsort_dsc_val_I8_idx_I8.o 
	$(CC) $(CFLAGS) -o $@ $^ 


#
#
# DO NOT include 3rd party headers for your source
# DO     include your own headers
#
DEPS = qtypes.h constants.h macros.h
%.o:  %.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c  $< 

set_val.o: set_val.c $(HEADER_DIR)/set_val.h $(INC1) \
	incl_set_val_I1.c \
	incl_set_val_I2.c \
	incl_set_val_I4.c \
	incl_set_val_I8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c set_val.c

# is_A_in_b.o: is_A_in_b.c is_A_in_b.h $(INC1) \
# 	incl_is_A_in_b_I4.c  incl_is_A_in_b_I8.c 
# 	$(CC) $(GCCFLAGS) $(INCLUDES) -c is_A_in_b.c

#---------------------------------------------------------
xfer.o:	xfer.c $(HEADER_DIR)/xfer.h $(INC1) \
	incl_xfer_I1.c  \
	incl_xfer_I2.c  \
	incl_xfer_I4.c  \
	incl_xfer_I8.c  \
	incl_xfer_F4.c  \
	incl_xfer_F8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c xfer.c

incl_xfer_I1.c : tmpl_xfer_incl_1.c
	sed s'/SRC/I1/'g tmpl_xfer_incl_1.c > incl_xfer_I1.c
incl_xfer_I2.c : tmpl_xfer_incl_1.c
	sed s'/SRC/I2/'g tmpl_xfer_incl_1.c > incl_xfer_I2.c
incl_xfer_I4.c : tmpl_xfer_incl_1.c
	sed s'/SRC/I4/'g tmpl_xfer_incl_1.c > incl_xfer_I4.c
incl_xfer_I8.c : tmpl_xfer_incl_1.c
	sed s'/SRC/I8/'g tmpl_xfer_incl_1.c > incl_xfer_I8.c
incl_xfer_F4.c : tmpl_xfer_incl_1.c
	sed s'/SRC/F4/'g tmpl_xfer_incl_1.c > incl_xfer_F4.c
incl_xfer_F8.c : tmpl_xfer_incl_1.c
	sed s'/SRC/F8/'g tmpl_xfer_incl_1.c > incl_xfer_F8.c
#---------------------------------------------------------
vec_f_to_s.o: vec_f_to_s.c $(HEADER_DIR)/vec_f_to_s.h $(INC1) \
	incl_f_to_s_max.c incl_f_to_s_min.c incl_f_to_s_sum.c
	$(CC) $(CFLAGS) $(INCLUDES) -c vec_f_to_s.c

incl_f_to_s_max.c : tmpl_incl_f_to_s.c
	sed s'/XXX/max/'g tmpl_incl_f_to_s.c > incl_f_to_s_max.c
incl_f_to_s_min.c : tmpl_incl_f_to_s.c
	sed s'/XXX/min/'g tmpl_incl_f_to_s.c > incl_f_to_s_min.c
incl_f_to_s_sum.c : tmpl_incl_f_to_s.c
	sed s'/XXX/sum/'g tmpl_incl_f_to_s.c > incl_f_to_s_sum.c

incl_is_A_in_b_I4.c : tmpl_incl_is_A_in_b.c
	sed s'/__XTYPE__/I4/'g tmpl_incl_is_A_in_b.c | \
	sed s'/__ITYPE__/int/'g > incl_is_A_in_b_I4.c 
incl_is_A_in_b_I8.c : tmpl_incl_is_A_in_b.c
	sed s'/__XTYPE__/I8/'g tmpl_incl_is_A_in_b.c | \
	sed s'/__ITYPE__/int/'g > incl_is_A_in_b_I8.c 

#--------------------------------------------------------
xfer_I1_I4.o :	$(AUTOGEN_SRC_DIR)/xfer_I1_I4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_I1_I4.c 
xfer_I2_I4.o :	$(AUTOGEN_SRC_DIR)/xfer_I2_I4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_I2_I4.c 
xfer_I4_I4.o :	$(AUTOGEN_SRC_DIR)/xfer_I4_I4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_I4_I4.c 
xfer_I8_I4.o :	$(AUTOGEN_SRC_DIR)/xfer_I8_I4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_I8_I4.c 
xfer_F4_I4.o :	$(AUTOGEN_SRC_DIR)/xfer_F4_I4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_F4_I4.c 
xfer_F8_I4.o :	$(AUTOGEN_SRC_DIR)/xfer_F8_I4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_F8_I4.c 
xfer_I1_I8.o :	$(AUTOGEN_SRC_DIR)/xfer_I1_I8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_I1_I8.c 
xfer_I2_I8.o :	$(AUTOGEN_SRC_DIR)/xfer_I2_I8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_I2_I8.c 
xfer_I4_I8.o :	$(AUTOGEN_SRC_DIR)/xfer_I4_I8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_I4_I8.c 
xfer_I8_I8.o :	$(AUTOGEN_SRC_DIR)/xfer_I8_I8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_I8_I8.c 
xfer_F4_I8.o :	$(AUTOGEN_SRC_DIR)/xfer_F4_I8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_F4_I8.c 
xfer_F8_I8.o :	$(AUTOGEN_SRC_DIR)/xfer_F8_I8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/xfer_F8_I8.c 
#--------------------------------------------------------
#--------------------------------------------------------
f_to_s_min_I1.o :	$(AUTOGEN_SRC_DIR)/f_to_s_min_I1.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_min_I1.c 
f_to_s_min_I2.o :	$(AUTOGEN_SRC_DIR)/f_to_s_min_I2.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_min_I2.c 
f_to_s_min_I4.o :	$(AUTOGEN_SRC_DIR)/f_to_s_min_I4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_min_I4.c 
f_to_s_min_I8.o :	$(AUTOGEN_SRC_DIR)/f_to_s_min_I8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_min_I8.c 
f_to_s_min_F4.o :	$(AUTOGEN_SRC_DIR)/f_to_s_min_F4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_min_F4.c 
f_to_s_min_F8.o :	$(AUTOGEN_SRC_DIR)/f_to_s_min_F8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_min_F8.c 
nn_f_to_s_min_I1.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_min_I1.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_min_I1.c 
nn_f_to_s_min_I2.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_min_I2.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_min_I2.c 
nn_f_to_s_min_I4.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_min_I4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_min_I4.c 
nn_f_to_s_min_I8.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_min_I8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_min_I8.c 
nn_f_to_s_min_F4.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_min_F4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_min_F4.c 
nn_f_to_s_min_F8.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_min_F8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_min_F8.c 
#--------------------------------------------------------
f_to_s_max_I1.o :	$(AUTOGEN_SRC_DIR)/f_to_s_max_I1.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_max_I1.c 
f_to_s_max_I2.o :	$(AUTOGEN_SRC_DIR)/f_to_s_max_I2.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_max_I2.c 
f_to_s_max_I4.o :	$(AUTOGEN_SRC_DIR)/f_to_s_max_I4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_max_I4.c 
f_to_s_max_I8.o :	$(AUTOGEN_SRC_DIR)/f_to_s_max_I8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_max_I8.c 
f_to_s_max_F4.o :	$(AUTOGEN_SRC_DIR)/f_to_s_max_F4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_max_F4.c 
f_to_s_max_F8.o :	$(AUTOGEN_SRC_DIR)/f_to_s_max_F8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_max_F8.c 
nn_f_to_s_max_I1.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_max_I1.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_max_I1.c 
nn_f_to_s_max_I2.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_max_I2.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_max_I2.c 
nn_f_to_s_max_I4.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_max_I4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_max_I4.c 
nn_f_to_s_max_I8.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_max_I8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_max_I8.c 
nn_f_to_s_max_F4.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_max_F4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_max_F4.c 
nn_f_to_s_max_F8.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_max_F8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_max_F8.c 
#--------------------------------------------------------
f_to_s_sum_B.o :	f_to_s_sum_B.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c f_to_s_sum_B.c 
f_to_s_sum_I1.o :	$(AUTOGEN_SRC_DIR)/f_to_s_sum_I1.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_sum_I1.c 
f_to_s_sum_I2.o :	$(AUTOGEN_SRC_DIR)/f_to_s_sum_I2.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_sum_I2.c 
f_to_s_sum_I4.o :	$(AUTOGEN_SRC_DIR)/f_to_s_sum_I4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_sum_I4.c 
f_to_s_sum_I8.o :	$(AUTOGEN_SRC_DIR)/f_to_s_sum_I8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_sum_I8.c 
f_to_s_sum_F4.o :	$(AUTOGEN_SRC_DIR)/f_to_s_sum_F4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_sum_F4.c 
f_to_s_sum_F8.o :	$(AUTOGEN_SRC_DIR)/f_to_s_sum_F8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/f_to_s_sum_F8.c 
nn_f_to_s_sum_I1.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_I1.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_I1.c 
nn_f_to_s_sum_I2.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_I2.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_I2.c 
nn_f_to_s_sum_I4.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_I4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_I4.c 
nn_f_to_s_sum_I8.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_I8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_I8.c 
nn_f_to_s_sum_F4.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_F4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_F4.c 
nn_f_to_s_sum_F8.o :	$(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_F8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_f_to_s_sum_F8.c 
#--------------------------------------------------------
pr_fld_I1.o :	$(AUTOGEN_SRC_DIR)/pr_fld_I1.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/pr_fld_I1.c 
pr_fld_I2.o :	$(AUTOGEN_SRC_DIR)/pr_fld_I2.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/pr_fld_I2.c 
pr_fld_I4.o :	$(AUTOGEN_SRC_DIR)/pr_fld_I4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/pr_fld_I4.c 
pr_fld_I8.o :	$(AUTOGEN_SRC_DIR)/pr_fld_I8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/pr_fld_I8.c 
pr_fld_F4.o :	$(AUTOGEN_SRC_DIR)/pr_fld_F4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/pr_fld_F4.c 
pr_fld_F8.o :	$(AUTOGEN_SRC_DIR)/pr_fld_F8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/pr_fld_F8.c 
#--------------------------------------------------------
extract_I1.o :	$(AUTOGEN_SRC_DIR)/extract_I1.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/extract_I1.c 
extract_I2.o :	$(AUTOGEN_SRC_DIR)/extract_I2.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/extract_I2.c 
extract_I4.o :	$(AUTOGEN_SRC_DIR)/extract_I4.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/extract_I4.c 
extract_I8.o :	$(AUTOGEN_SRC_DIR)/extract_I8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/extract_I8.c 
extract_UI8.o :	$(AUTOGEN_SRC_DIR)/extract_UI8.c 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/extract_UI8.c 
#--------------------------------------------------------
s_to_f_const_I1.o :	$(AUTOGEN_SRC_DIR)/s_to_f_const_I1.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/s_to_f_const_I1.c 
s_to_f_const_I2.o :	$(AUTOGEN_SRC_DIR)/s_to_f_const_I2.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/s_to_f_const_I2.c 
s_to_f_const_I4.o :	$(AUTOGEN_SRC_DIR)/s_to_f_const_I4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/s_to_f_const_I4.c 
s_to_f_const_I8.o :	$(AUTOGEN_SRC_DIR)/s_to_f_const_I8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/s_to_f_const_I8.c 
s_to_f_const_F4.o :	$(AUTOGEN_SRC_DIR)/s_to_f_const_F4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/s_to_f_const_F4.c 
#--------------------------------------------------------
s_to_f_random_I4.o :	$(AUTOGEN_SRC_DIR)/s_to_f_random_I4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/s_to_f_random_I4.c 
s_to_f_random_I8.o :	$(AUTOGEN_SRC_DIR)/s_to_f_random_I8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/s_to_f_random_I8.c 
#--------------------------------------------------------
s_to_f_seq_I1.o :	$(AUTOGEN_SRC_DIR)/s_to_f_seq_I1.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/s_to_f_seq_I1.c 
s_to_f_seq_I2.o :	$(AUTOGEN_SRC_DIR)/s_to_f_seq_I2.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/s_to_f_seq_I2.c 
s_to_f_seq_I4.o :	$(AUTOGEN_SRC_DIR)/s_to_f_seq_I4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/s_to_f_seq_I4.c 
s_to_f_seq_I8.o :	$(AUTOGEN_SRC_DIR)/s_to_f_seq_I8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/s_to_f_seq_I8.c 
#--------------------------------------------------------
mk_hashes_I1.o : $(AUTOGEN_SRC_DIR)/mk_hashes_I1.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mk_hashes_I1.c 
mk_hashes_I2.o : $(AUTOGEN_SRC_DIR)/mk_hashes_I2.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mk_hashes_I2.c 
mk_hashes_I4.o : $(AUTOGEN_SRC_DIR)/mk_hashes_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mk_hashes_I4.c 
mk_hashes_I8.o : $(AUTOGEN_SRC_DIR)/mk_hashes_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mk_hashes_I8.c 
#--------------------------------------------------------
permute_I4.o : $(AUTOGEN_SRC_DIR)/permute_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/permute_I4.c 
permute_I8.o : $(AUTOGEN_SRC_DIR)/permute_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/permute_I8.c 
#--------------------------------------------------------
saturate_I1.o : $(AUTOGEN_SRC_DIR)/saturate_I1.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/saturate_I1.c 
saturate_I2.o : $(AUTOGEN_SRC_DIR)/saturate_I2.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/saturate_I2.c 
saturate_I4.o : $(AUTOGEN_SRC_DIR)/saturate_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/saturate_I4.c 
saturate_I8.o : $(AUTOGEN_SRC_DIR)/saturate_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/saturate_I8.c 
#--------------------------------------------------------
assign_I1.o :	$(AUTOGEN_SRC_DIR)/assign_I1.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/assign_I1.c 
assign_I2.o :	$(AUTOGEN_SRC_DIR)/assign_I2.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/assign_I2.c 
assign_I4.o :	$(AUTOGEN_SRC_DIR)/assign_I4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/assign_I4.c 
assign_I8.o :	$(AUTOGEN_SRC_DIR)/assign_I8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/assign_I8.c 
assign_F4.o :	$(AUTOGEN_SRC_DIR)/assign_F4.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/assign_F4.c 
assign_F8.o :	$(AUTOGEN_SRC_DIR)/assign_F8.c 
	$(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/assign_F8.c 

add2_I2.o : $(AUTOGEN_SRC_DIR)/add2_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/add2_I2.c 
sub2_I2.o : $(AUTOGEN_SRC_DIR)/sub2_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sub2_I2.c 
mul2_I2.o : $(AUTOGEN_SRC_DIR)/mul2_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mul2_I2.c 
div2_I2.o : $(AUTOGEN_SRC_DIR)/div2_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/div2_I2.c 
rem2_I2.o : $(AUTOGEN_SRC_DIR)/rem2_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/rem2_I2.c 
add2_I4.o : $(AUTOGEN_SRC_DIR)/add2_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/add2_I4.c 
sub2_I4.o : $(AUTOGEN_SRC_DIR)/sub2_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sub2_I4.c 
mul2_I4.o : $(AUTOGEN_SRC_DIR)/mul2_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mul2_I4.c 
div2_I4.o : $(AUTOGEN_SRC_DIR)/div2_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/div2_I4.c 
rem2_I4.o : $(AUTOGEN_SRC_DIR)/rem2_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/rem2_I4.c 
shiftleft2_I4.o : $(AUTOGEN_SRC_DIR)/shiftleft2_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/shiftleft2_I4.c 
shiftright2_UI4.o : $(AUTOGEN_SRC_DIR)/shiftright2_UI4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/shiftright2_UI4.c 
add2_I8.o : $(AUTOGEN_SRC_DIR)/add2_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/add2_I8.c 
sub2_I8.o : $(AUTOGEN_SRC_DIR)/sub2_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sub2_I8.c 
mul2_I8.o : $(AUTOGEN_SRC_DIR)/mul2_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mul2_I8.c 
div2_I8.o : $(AUTOGEN_SRC_DIR)/div2_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/div2_I8.c 
rem2_I8.o : $(AUTOGEN_SRC_DIR)/rem2_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/rem2_I8.c 
shiftleft2_I8.o : $(AUTOGEN_SRC_DIR)/shiftleft2_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/shiftleft2_I8.c 
shiftright2_UI8.o : $(AUTOGEN_SRC_DIR)/shiftright2_UI8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/shiftright2_UI8.c 
add2_F8.o : $(AUTOGEN_SRC_DIR)/add2_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/add2_F8.c 
sub2_F8.o : $(AUTOGEN_SRC_DIR)/sub2_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sub2_F8.c 
mul2_F8.o : $(AUTOGEN_SRC_DIR)/mul2_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mul2_F8.c 
div2_F8.o : $(AUTOGEN_SRC_DIR)/div2_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/div2_F8.c 
add2_F4.o : $(AUTOGEN_SRC_DIR)/add2_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/add2_F4.c 
sub2_F4.o : $(AUTOGEN_SRC_DIR)/sub2_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sub2_F4.c 
mul2_F4.o : $(AUTOGEN_SRC_DIR)/mul2_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mul2_F4.c 
div2_F4.o : $(AUTOGEN_SRC_DIR)/div2_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/div2_F4.c 
and2_I1.o : $(AUTOGEN_SRC_DIR)/and2_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/and2_I1.c 
or2_I1.o : $(AUTOGEN_SRC_DIR)/or2_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/or2_I1.c 
bwise_and2_I1.o : $(AUTOGEN_SRC_DIR)/bwise_and2_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_and2_I1.c 
bwise_and2_I8.o : $(AUTOGEN_SRC_DIR)/bwise_and2_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_and2_I8.c 
bwise_and2_I4.o : $(AUTOGEN_SRC_DIR)/bwise_and2_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_and2_I4.c 
bwise_or2_I1.o : $(AUTOGEN_SRC_DIR)/bwise_or2_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_or2_I1.c 
bwise_or2_I8.o : $(AUTOGEN_SRC_DIR)/bwise_or2_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_or2_I8.c 
bwise_or2_I4.o : $(AUTOGEN_SRC_DIR)/bwise_or2_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_or2_I4.c 
bwise_xor2_I1.o : $(AUTOGEN_SRC_DIR)/bwise_xor2_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_xor2_I1.c 
bwise_xor2_I8.o : $(AUTOGEN_SRC_DIR)/bwise_xor2_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_xor2_I8.c 
bwise_xor2_I4.o : $(AUTOGEN_SRC_DIR)/bwise_xor2_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_xor2_I4.c 
#---------------------------------------------
cmp_ge_I1.o : $(AUTOGEN_SRC_DIR)/cmp_ge_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_I1.c 
cmp_le_I1.o : $(AUTOGEN_SRC_DIR)/cmp_le_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_I1.c 
cmp_eq_I1.o : $(AUTOGEN_SRC_DIR)/cmp_eq_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_I1.c 
cmp_ne_I1.o : $(AUTOGEN_SRC_DIR)/cmp_ne_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_I1.c 
cmp_gt_I1.o : $(AUTOGEN_SRC_DIR)/cmp_gt_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_I1.c 
cmp_lt_I1.o : $(AUTOGEN_SRC_DIR)/cmp_lt_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_I1.c 
#---------------------------------------------
cmp_ge_I2.o : $(AUTOGEN_SRC_DIR)/cmp_ge_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_I2.c 
cmp_le_I2.o : $(AUTOGEN_SRC_DIR)/cmp_le_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_I2.c 
cmp_eq_I2.o : $(AUTOGEN_SRC_DIR)/cmp_eq_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_I2.c 
cmp_ne_I2.o : $(AUTOGEN_SRC_DIR)/cmp_ne_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_I2.c 
cmp_gt_I2.o : $(AUTOGEN_SRC_DIR)/cmp_gt_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_I2.c 
cmp_lt_I2.o : $(AUTOGEN_SRC_DIR)/cmp_lt_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_I2.c 
#---------------------------------------------
cmp_ge_I4.o : $(AUTOGEN_SRC_DIR)/cmp_ge_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_I4.c 
cmp_le_I4.o : $(AUTOGEN_SRC_DIR)/cmp_le_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_I4.c 
cmp_eq_I4.o : $(AUTOGEN_SRC_DIR)/cmp_eq_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_I4.c 
cmp_ne_I4.o : $(AUTOGEN_SRC_DIR)/cmp_ne_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_I4.c 
cmp_gt_I4.o : $(AUTOGEN_SRC_DIR)/cmp_gt_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_I4.c 
cmp_lt_I4.o : $(AUTOGEN_SRC_DIR)/cmp_lt_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_I4.c 
#---------------------------------------------
cmp_ge_F4.o : $(AUTOGEN_SRC_DIR)/cmp_ge_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_F4.c 
cmp_le_F4.o : $(AUTOGEN_SRC_DIR)/cmp_le_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_F4.c 
cmp_eq_F4.o : $(AUTOGEN_SRC_DIR)/cmp_eq_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_F4.c 
cmp_ne_F4.o : $(AUTOGEN_SRC_DIR)/cmp_ne_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_F4.c 
cmp_gt_F4.o : $(AUTOGEN_SRC_DIR)/cmp_gt_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_F4.c 
cmp_lt_F4.o : $(AUTOGEN_SRC_DIR)/cmp_lt_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_F4.c 
#---------------------------------------------
cmp_ge_F8.o : $(AUTOGEN_SRC_DIR)/cmp_ge_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_F8.c 
cmp_le_F8.o : $(AUTOGEN_SRC_DIR)/cmp_le_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_F8.c 
cmp_eq_F8.o : $(AUTOGEN_SRC_DIR)/cmp_eq_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_F8.c 
cmp_ne_F8.o : $(AUTOGEN_SRC_DIR)/cmp_ne_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_F8.c 
cmp_gt_F8.o : $(AUTOGEN_SRC_DIR)/cmp_gt_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_F8.c 
cmp_lt_F8.o : $(AUTOGEN_SRC_DIR)/cmp_lt_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_F8.c 
#---------------------------------------------
cmp_ge_I8.o : $(AUTOGEN_SRC_DIR)/cmp_ge_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_I8.c 
cmp_le_I8.o : $(AUTOGEN_SRC_DIR)/cmp_le_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_I8.c 
cmp_eq_I8.o : $(AUTOGEN_SRC_DIR)/cmp_eq_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_I8.c 
cmp_ne_I8.o : $(AUTOGEN_SRC_DIR)/cmp_ne_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_I8.c 
cmp_gt_I8.o : $(AUTOGEN_SRC_DIR)/cmp_gt_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_I8.c 
cmp_lt_I8.o : $(AUTOGEN_SRC_DIR)/cmp_lt_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_I8.c 
#---------------------------------------------
cmp_lt_or_gt_I1.o : $(AUTOGEN_SRC_DIR)/cmp_lt_or_gt_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_or_gt_I1.c 
cmp_le_or_ge_I1.o : $(AUTOGEN_SRC_DIR)/cmp_le_or_ge_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_or_ge_I1.c 
cmp_ge_and_le_I1.o : $(AUTOGEN_SRC_DIR)/cmp_ge_and_le_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_and_le_I1.c
cmp_gt_and_lt_I1.o : $(AUTOGEN_SRC_DIR)/cmp_gt_and_lt_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_and_lt_I1.c
cmp_lt_or_gt_I2.o : $(AUTOGEN_SRC_DIR)/cmp_lt_or_gt_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_or_gt_I2.c 
cmp_le_or_ge_I2.o : $(AUTOGEN_SRC_DIR)/cmp_le_or_ge_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_or_ge_I2.c 
cmp_ge_and_le_I2.o : $(AUTOGEN_SRC_DIR)/cmp_ge_and_le_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_and_le_I2.c
cmp_gt_and_lt_I2.o : $(AUTOGEN_SRC_DIR)/cmp_gt_and_lt_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_and_lt_I2.c
cmp_lt_or_gt_I4.o : $(AUTOGEN_SRC_DIR)/cmp_lt_or_gt_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_or_gt_I4.c 
cmp_le_or_ge_I4.o : $(AUTOGEN_SRC_DIR)/cmp_le_or_ge_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_or_ge_I4.c 
cmp_ge_and_le_I4.o : $(AUTOGEN_SRC_DIR)/cmp_ge_and_le_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_and_le_I4.c
cmp_gt_and_lt_I4.o : $(AUTOGEN_SRC_DIR)/cmp_gt_and_lt_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_and_lt_I4.c
#---------------------------------------------
dbg_cmp_neq_mult_scalar_I1.o : $(AUTOGEN_SRC_DIR)/dbg_cmp_neq_mult_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/dbg_cmp_neq_mult_scalar_I1.c 
dbg_cmp_neq_mult_scalar_I2.o : $(AUTOGEN_SRC_DIR)/dbg_cmp_neq_mult_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/dbg_cmp_neq_mult_scalar_I2.c 
dbg_cmp_neq_mult_scalar_I4.o : $(AUTOGEN_SRC_DIR)/dbg_cmp_neq_mult_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/dbg_cmp_neq_mult_scalar_I4.c 
dbg_cmp_neq_mult_scalar_I8.o : $(AUTOGEN_SRC_DIR)/dbg_cmp_neq_mult_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/dbg_cmp_neq_mult_scalar_I8.c 
dbg_cmp_eq_mult_scalar_I1.o : $(AUTOGEN_SRC_DIR)/dbg_cmp_eq_mult_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/dbg_cmp_eq_mult_scalar_I1.c 
dbg_cmp_eq_mult_scalar_I2.o : $(AUTOGEN_SRC_DIR)/dbg_cmp_eq_mult_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/dbg_cmp_eq_mult_scalar_I2.c 
dbg_cmp_eq_mult_scalar_I4.o : $(AUTOGEN_SRC_DIR)/dbg_cmp_eq_mult_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/dbg_cmp_eq_mult_scalar_I4.c 
dbg_cmp_eq_mult_scalar_I8.o : $(AUTOGEN_SRC_DIR)/dbg_cmp_eq_mult_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/dbg_cmp_eq_mult_scalar_I8.c 
opt_cmp_eq_mult_scalar_I1.o : $(AUTOGEN_SRC_DIR)/opt_cmp_eq_mult_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/opt_cmp_eq_mult_scalar_I1.c 
opt_cmp_eq_mult_scalar_I2.o : $(AUTOGEN_SRC_DIR)/opt_cmp_eq_mult_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/opt_cmp_eq_mult_scalar_I2.c 
opt_cmp_eq_mult_scalar_I4.o : $(AUTOGEN_SRC_DIR)/opt_cmp_eq_mult_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/opt_cmp_eq_mult_scalar_I4.c 
opt_cmp_eq_mult_scalar_I8.o : $(AUTOGEN_SRC_DIR)/opt_cmp_eq_mult_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/opt_cmp_eq_mult_scalar_I8.c 
cmp_eq_mult_scalar_I1.o : $(AUTOGEN_SRC_DIR)/cmp_eq_mult_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_mult_scalar_I1.c 
cmp_eq_mult_scalar_I2.o : $(AUTOGEN_SRC_DIR)/cmp_eq_mult_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_mult_scalar_I2.c 
cmp_eq_mult_scalar_I4.o : $(AUTOGEN_SRC_DIR)/cmp_eq_mult_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_mult_scalar_I4.c 
cmp_eq_mult_scalar_I8.o : $(AUTOGEN_SRC_DIR)/cmp_eq_mult_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_mult_scalar_I8.c 
add_scalar_I1.o : $(AUTOGEN_SRC_DIR)/add_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/add_scalar_I1.c 
sub_scalar_I1.o : $(AUTOGEN_SRC_DIR)/sub_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sub_scalar_I1.c 
mul_scalar_I1.o : $(AUTOGEN_SRC_DIR)/mul_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mul_scalar_I1.c 
div_scalar_I1.o : $(AUTOGEN_SRC_DIR)/div_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/div_scalar_I1.c 
rem_scalar_I1.o : $(AUTOGEN_SRC_DIR)/rem_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/rem_scalar_I1.c 
add_scalar_I2.o : $(AUTOGEN_SRC_DIR)/add_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/add_scalar_I2.c 
sub_scalar_I2.o : $(AUTOGEN_SRC_DIR)/sub_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sub_scalar_I2.c 
mul_scalar_I2.o : $(AUTOGEN_SRC_DIR)/mul_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mul_scalar_I2.c 
div_scalar_I2.o : $(AUTOGEN_SRC_DIR)/div_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/div_scalar_I2.c 
rem_scalar_I2.o : $(AUTOGEN_SRC_DIR)/rem_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/rem_scalar_I2.c 
add_scalar_I4.o : $(AUTOGEN_SRC_DIR)/add_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/add_scalar_I4.c 
sub_scalar_I4.o : $(AUTOGEN_SRC_DIR)/sub_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sub_scalar_I4.c 
mul_scalar_I4.o : $(AUTOGEN_SRC_DIR)/mul_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mul_scalar_I4.c 
div_scalar_I4.o : $(AUTOGEN_SRC_DIR)/div_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/div_scalar_I4.c 
rem_scalar_I4.o : $(AUTOGEN_SRC_DIR)/rem_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/rem_scalar_I4.c 
add_scalar_I8.o : $(AUTOGEN_SRC_DIR)/add_scalar_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/add_scalar_I8.c  
sub_scalar_I8.o : $(AUTOGEN_SRC_DIR)/sub_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sub_scalar_I8.c 
mul_scalar_I8.o : $(AUTOGEN_SRC_DIR)/mul_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mul_scalar_I8.c 
div_scalar_I8.o : $(AUTOGEN_SRC_DIR)/div_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/div_scalar_I8.c 
rem_scalar_I8.o : $(AUTOGEN_SRC_DIR)/rem_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/rem_scalar_I8.c 
add_scalar_F8.o : $(AUTOGEN_SRC_DIR)/add_scalar_F8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/add_scalar_F8.c  
sub_scalar_F8.o : $(AUTOGEN_SRC_DIR)/sub_scalar_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sub_scalar_F8.c 
mul_scalar_F8.o : $(AUTOGEN_SRC_DIR)/mul_scalar_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mul_scalar_F8.c 
div_scalar_F8.o : $(AUTOGEN_SRC_DIR)/div_scalar_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/div_scalar_F8.c 
add_scalar_F4.o : $(AUTOGEN_SRC_DIR)/add_scalar_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/add_scalar_F4.c  
sub_scalar_F4.o : $(AUTOGEN_SRC_DIR)/sub_scalar_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sub_scalar_F4.c 
mul_scalar_F4.o : $(AUTOGEN_SRC_DIR)/mul_scalar_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/mul_scalar_F4.c 
div_scalar_F4.o : $(AUTOGEN_SRC_DIR)/div_scalar_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/div_scalar_F4.c 
and_scalar_I1.o : $(AUTOGEN_SRC_DIR)/and_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/and_scalar_I1.c 
or_scalar_I1.o : $(AUTOGEN_SRC_DIR)/or_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/or_scalar_I1.c 
a_and_not_b_I1.o : a_and_not_b_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c a_and_not_b_I1.c 
bwise_a_and_not_b.o : bwise_a_and_not_b.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c bwise_a_and_not_b.c 
bwise_and_scalar_I4.o : $(AUTOGEN_SRC_DIR)/bwise_and_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_and_scalar_I4.c 
bwise_not_or_scalar_I8.o : bwise_not_or_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c bwise_not_or_scalar_I8.c 
bwise_not_and_scalar_I8.o : bwise_not_and_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c bwise_not_and_scalar_I8.c 
bwise_and_scalar_I8.o : $(AUTOGEN_SRC_DIR)/bwise_and_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_and_scalar_I8.c 
bwise_and_scalar_I1.o : $(AUTOGEN_SRC_DIR)/bwise_and_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_and_scalar_I1.c 
shift_left_scalar_I4.o : $(AUTOGEN_SRC_DIR)/shift_left_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/shift_left_scalar_I4.c 
shift_left_scalar_I8.o : $(AUTOGEN_SRC_DIR)/shift_left_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/shift_left_scalar_I8.c 
shift_right_scalar_UI4.o : $(AUTOGEN_SRC_DIR)/shift_right_scalar_UI4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/shift_right_scalar_UI4.c 
shift_right_scalar_UI8.o : $(AUTOGEN_SRC_DIR)/shift_right_scalar_UI8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/shift_right_scalar_UI8.c 
bwise_or_scalar_I4.o : $(AUTOGEN_SRC_DIR)/bwise_or_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_or_scalar_I4.c 
bwise_or_scalar_I8.o : $(AUTOGEN_SRC_DIR)/bwise_or_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_or_scalar_I8.c 
bwise_or_scalar_I1.o : $(AUTOGEN_SRC_DIR)/bwise_or_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_or_scalar_I1.c 
bwise_xor_scalar_I4.o : $(AUTOGEN_SRC_DIR)/bwise_xor_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_xor_scalar_I4.c 
bwise_xor_scalar_I8.o : $(AUTOGEN_SRC_DIR)/bwise_xor_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_xor_scalar_I8.c 
bwise_xor_scalar_I1.o : $(AUTOGEN_SRC_DIR)/bwise_xor_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bwise_xor_scalar_I1.c 
cmp_le_scalar_I4.o : $(AUTOGEN_SRC_DIR)/cmp_le_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_scalar_I4.c 
cmp_ge_scalar_I4.o : $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_scalar_I4.c 
cmp_ne_scalar_I4.o : $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_I4.c 
cmp_gt_scalar_I4.o : $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_I4.c 
cmp_lt_scalar_I4.o : $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_I4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_I4.c 
cmp_le_scalar_I8.o : $(AUTOGEN_SRC_DIR)/cmp_le_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_scalar_I8.c 
cmp_ge_scalar_I8.o : $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_I8.c 
cmp_eq_scalar_I8.o : $(AUTOGEN_SRC_DIR)/cmp_eq_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_scalar_I8.c 
cmp_ne_scalar_I8.o : $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_I8.c 
cmp_lt_scalar_I8.o : $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_I8.c 
cmp_gt_scalar_I8.o : $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_I8.c 
cmp_le_scalar_F4.o : $(AUTOGEN_SRC_DIR)/cmp_le_scalar_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_scalar_F4.c  
cmp_ge_scalar_F4.o : $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_F4.c 
cmp_eq_scalar_F4.o : $(AUTOGEN_SRC_DIR)/cmp_eq_scalar_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_scalar_F4.c 
cmp_ne_scalar_F4.o : $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_F4.c 
cmp_lt_scalar_F4.o : $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_F4.c 
cmp_gt_scalar_F4.o : $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_F4.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_F4.c 
cmp_le_scalar_F8.o : $(AUTOGEN_SRC_DIR)/cmp_le_scalar_F8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_scalar_F8.c  
cmp_ge_scalar_F8.o : $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_F8.c 
cmp_eq_scalar_F8.o : $(AUTOGEN_SRC_DIR)/cmp_eq_scalar_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_scalar_F8.c 
cmp_ne_scalar_F8.o : $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_F8.c 
cmp_lt_scalar_F8.o : $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_F8.c 
cmp_gt_scalar_F8.o : $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_F8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_F8.c 
cmp_le_scalar_I1.o : $(AUTOGEN_SRC_DIR)/cmp_le_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_scalar_I1.c 
cmp_ge_scalar_I1.o : $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_I1.c 
cmp_eq_scalar_I1.o : $(AUTOGEN_SRC_DIR)/cmp_eq_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_scalar_I1.c 
cmp_ne_scalar_I1.o : $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_I1.c 
cmp_lt_scalar_I1.o : $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_I1.c 
cmp_gt_scalar_I1.o : $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_I1.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_I1.c 
cmp_le_scalar_I2.o : $(AUTOGEN_SRC_DIR)/cmp_le_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_le_scalar_I2.c 
cmp_ge_scalar_I2.o : $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ge_scalar_I2.c 
cmp_eq_scalar_I2.o : $(AUTOGEN_SRC_DIR)/cmp_eq_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_eq_scalar_I2.c 
cmp_ne_scalar_I2.o : $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_ne_scalar_I2.c 
cmp_lt_scalar_I2.o : $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_lt_scalar_I2.c 
cmp_gt_scalar_I2.o : $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_I2.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cmp_gt_scalar_I2.c 
conv_I1_to_B.o : conv_I1_to_B.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c conv_I1_to_B.c 

conv_F8_to_I4.o : $(AUTOGEN_SRC_DIR)/conv_F8_to_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_F8_to_I4.c 
conv_F8_to_I8.o : $(AUTOGEN_SRC_DIR)/conv_F8_to_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_F8_to_I8.c  
conv_F8_to_F4.o : $(AUTOGEN_SRC_DIR)/conv_F8_to_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_F8_to_F4.c  
conv_I4_to_I1.o : $(AUTOGEN_SRC_DIR)/conv_I4_to_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I4_to_I1.c  
conv_I4_to_I2.o : $(AUTOGEN_SRC_DIR)/conv_I4_to_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I4_to_I2.c  
conv_I4_to_I8.o : $(AUTOGEN_SRC_DIR)/conv_I4_to_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I4_to_I8.c  
conv_I4_to_F4.o : $(AUTOGEN_SRC_DIR)/conv_I4_to_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I4_to_F4.c  
conv_I4_to_F8.o : $(AUTOGEN_SRC_DIR)/conv_I4_to_F8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I4_to_F8.c  
conv_I8_to_I1.o : $(AUTOGEN_SRC_DIR)/conv_I8_to_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I8_to_I1.c  
conv_I8_to_I2.o : $(AUTOGEN_SRC_DIR)/conv_I8_to_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I8_to_I2.c  
conv_I8_to_I4.o : $(AUTOGEN_SRC_DIR)/conv_I8_to_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I8_to_I4.c  
conv_I8_to_F4.o : $(AUTOGEN_SRC_DIR)/conv_I8_to_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I8_to_F4.c  
conv_I8_to_F8.o : $(AUTOGEN_SRC_DIR)/conv_I8_to_F8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I8_to_F8.c  
conv_I1_to_I4.o : $(AUTOGEN_SRC_DIR)/conv_I1_to_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I1_to_I4.c  
conv_I1_to_I8.o : $(AUTOGEN_SRC_DIR)/conv_I1_to_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_I1_to_I8.c  
conv_F4_to_I4.o : $(AUTOGEN_SRC_DIR)/conv_F4_to_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_F4_to_I4.c  
conv_F4_to_I8.o : $(AUTOGEN_SRC_DIR)/conv_F4_to_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_F4_to_I8.c  
conv_F4_to_F8.o : $(AUTOGEN_SRC_DIR)/conv_F4_to_F8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/conv_F4_to_F8.c  
#--------------------------------------------------------------------
nn_conv_F8_to_I4.o : $(AUTOGEN_SRC_DIR)/nn_conv_F8_to_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_F8_to_I4.c 
nn_conv_F8_to_I8.o : $(AUTOGEN_SRC_DIR)/nn_conv_F8_to_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_F8_to_I8.c  
nn_conv_F8_to_F4.o : $(AUTOGEN_SRC_DIR)/nn_conv_F8_to_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_F8_to_F4.c  
nn_conv_I4_to_I1.o : $(AUTOGEN_SRC_DIR)/nn_conv_I4_to_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I4_to_I1.c  
nn_conv_I4_to_I2.o : $(AUTOGEN_SRC_DIR)/nn_conv_I4_to_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I4_to_I2.c  
nn_conv_I4_to_I8.o : $(AUTOGEN_SRC_DIR)/nn_conv_I4_to_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I4_to_I8.c  
nn_conv_I4_to_F4.o : $(AUTOGEN_SRC_DIR)/nn_conv_I4_to_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I4_to_F4.c  
nn_conv_I4_to_F8.o : $(AUTOGEN_SRC_DIR)/nn_conv_I4_to_F8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I4_to_F8.c  
nn_conv_I8_to_I1.o : $(AUTOGEN_SRC_DIR)/nn_conv_I8_to_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I8_to_I1.c  
nn_conv_I8_to_I2.o : $(AUTOGEN_SRC_DIR)/nn_conv_I8_to_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I8_to_I2.c  
nn_conv_I8_to_I4.o : $(AUTOGEN_SRC_DIR)/nn_conv_I8_to_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I8_to_I4.c  
nn_conv_I8_to_F4.o : $(AUTOGEN_SRC_DIR)/nn_conv_I8_to_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I8_to_F4.c  
nn_conv_I8_to_F8.o : $(AUTOGEN_SRC_DIR)/nn_conv_I8_to_F8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I8_to_F8.c  
nn_conv_I1_to_I4.o : $(AUTOGEN_SRC_DIR)/nn_conv_I1_to_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I1_to_I4.c  
nn_conv_I1_to_I8.o : $(AUTOGEN_SRC_DIR)/nn_conv_I1_to_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_I1_to_I8.c  
nn_conv_F4_to_I4.o : $(AUTOGEN_SRC_DIR)/nn_conv_F4_to_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_F4_to_I4.c  
nn_conv_F4_to_I8.o : $(AUTOGEN_SRC_DIR)/nn_conv_F4_to_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_F4_to_I8.c  
nn_conv_F4_to_F8.o : $(AUTOGEN_SRC_DIR)/nn_conv_F4_to_F8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/nn_conv_F4_to_F8.c  
#--------------------------------------------------------------------
ones_complement_I4.o : $(AUTOGEN_SRC_DIR)/ones_complement_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/ones_complement_I4.c  
not_I4.o : $(AUTOGEN_SRC_DIR)/not_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/not_I4.c  
ones_complement_I8.o : $(AUTOGEN_SRC_DIR)/ones_complement_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/ones_complement_I8.c  
not_I8.o : $(AUTOGEN_SRC_DIR)/not_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/not_I8.c  
ones_complement_I1.o : $(AUTOGEN_SRC_DIR)/ones_complement_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/ones_complement_I1.c  
not_I1.o : $(AUTOGEN_SRC_DIR)/not_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/not_I1.c  
incr_I4.o : $(AUTOGEN_SRC_DIR)/incr_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/incr_I4.c  
decr_I4.o : $(AUTOGEN_SRC_DIR)/decr_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/decr_I4.c  
incr_I8.o : $(AUTOGEN_SRC_DIR)/incr_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/incr_I8.c  
decr_I8.o : $(AUTOGEN_SRC_DIR)/decr_I8.c 
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/decr_I8.c 
cum_I4_to_I4.o : $(AUTOGEN_SRC_DIR)/cum_I4_to_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cum_I4_to_I4.c 
cum_I4_to_I8.o : $(AUTOGEN_SRC_DIR)/cum_I4_to_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cum_I4_to_I8.c 
cum_I8_to_I4.o : $(AUTOGEN_SRC_DIR)/cum_I8_to_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cum_I8_to_I4.c 
cum_I8_to_I8.o : $(AUTOGEN_SRC_DIR)/cum_I8_to_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cum_I8_to_I8.c 
cum_I2_to_I4.o : $(AUTOGEN_SRC_DIR)/cum_I2_to_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cum_I2_to_I4.c 
cum_I2_to_I8.o : $(AUTOGEN_SRC_DIR)/cum_I2_to_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cum_I2_to_I8.c 
cum_I1_to_I4.o : $(AUTOGEN_SRC_DIR)/cum_I1_to_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cum_I1_to_I4.c 
cum_I1_to_I8.o : $(AUTOGEN_SRC_DIR)/cum_I1_to_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/cum_I1_to_I8.c 
sort_asc_I4.o : $(AUTOGEN_SRC_DIR)/sort_asc_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort_asc_I4.c 
sort_dsc_I4.o : $(AUTOGEN_SRC_DIR)/sort_dsc_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort_dsc_I4.c 
sort_asc_I8.o : $(AUTOGEN_SRC_DIR)/sort_asc_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort_asc_I8.c 
sort_dsc_I8.o : $(AUTOGEN_SRC_DIR)/sort_dsc_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort_dsc_I8.c 
sort2_dsc_F4.o : $(AUTOGEN_SRC_DIR)/sort2_dsc_F4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort2_dsc_F4.c 
sort2_asc_F4.o : $(AUTOGEN_SRC_DIR)/sort2_asc_F4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort2_asc_F4.c 
sort_asc_F4.o : $(AUTOGEN_SRC_DIR)/sort_asc_F4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort_asc_F4.c 
sort_dsc_F4.o : $(AUTOGEN_SRC_DIR)/sort_dsc_F4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort_dsc_F4.c 
sort_asc_F8.o : $(AUTOGEN_SRC_DIR)/sort_asc_F8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort_asc_F8.c 
sort_dsc_F8.o : $(AUTOGEN_SRC_DIR)/sort_dsc_F8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort_dsc_F8.c 
sort2_asc_I4.o : $(AUTOGEN_SRC_DIR)/sort2_asc_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort2_asc_I4.c 
sort2_dsc_I4.o : $(AUTOGEN_SRC_DIR)/sort2_dsc_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort2_dsc_I4.c 
sort2_asc_I8.o : $(AUTOGEN_SRC_DIR)/sort2_asc_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort2_asc_I8.c 
sort2_dsc_I8.o : $(AUTOGEN_SRC_DIR)/sort2_dsc_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort2_dsc_I8.c 
sort2_asc_float.o : $(AUTOGEN_SRC_DIR)/sort2_asc_float.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort2_asc_float.c 
sort2_dsc_float.o : $(AUTOGEN_SRC_DIR)/sort2_dsc_float.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort2_dsc_float.c 
sort3_asc_I4.o : $(AUTOGEN_SRC_DIR)/sort3_asc_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort3_asc_I4.c 
sort3_dsc_I4.o : $(AUTOGEN_SRC_DIR)/sort3_dsc_I4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort3_dsc_I4.c 
sort3_asc_I8.o : $(AUTOGEN_SRC_DIR)/sort3_asc_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort3_asc_I8.c 
sort3_dsc_I8.o : $(AUTOGEN_SRC_DIR)/sort3_dsc_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort3_dsc_I8.c 
sort4_asc_I8.o : $(AUTOGEN_SRC_DIR)/sort4_asc_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort4_asc_I8.c 
sort4_dsc_I8.o : $(AUTOGEN_SRC_DIR)/sort4_dsc_I8.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort4_dsc_I8.c 
sort3_asc_F4.o : $(AUTOGEN_SRC_DIR)/sort3_asc_F4.c 
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort3_asc_F4.c 
sort3_dsc_F4.o : $(AUTOGEN_SRC_DIR)/sort3_dsc_F4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/sort3_dsc_F4.c  
uniq_I4.o : $(AUTOGEN_SRC_DIR)/uniq_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/uniq_I4.c  
uniq_I8.o : $(AUTOGEN_SRC_DIR)/uniq_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/uniq_I8.c  
uniq_cnt_I4.o : $(AUTOGEN_SRC_DIR)/uniq_cnt_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/uniq_cnt_I4.c  
uniq_cnt_I8.o : $(AUTOGEN_SRC_DIR)/uniq_cnt_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/uniq_cnt_I8.c  
uniq_alldef_I4.o : $(AUTOGEN_SRC_DIR)/uniq_alldef_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/uniq_alldef_I4.c  
uniq_alldef_I8.o : $(AUTOGEN_SRC_DIR)/uniq_alldef_I8.c
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/uniq_alldef_I8.c
uniq_cnt_alldef_I4.o : $(AUTOGEN_SRC_DIR)/uniq_cnt_alldef_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/uniq_cnt_alldef_I4.c 
uniq_cnt_alldef_I8.o : $(AUTOGEN_SRC_DIR)/uniq_cnt_alldef_I8.c
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/uniq_cnt_alldef_I8.c
crc32_I4.o : $(AUTOGEN_SRC_DIR)/crc32_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/crc32_I4.c  
crc32_I8.o : $(AUTOGEN_SRC_DIR)/crc32_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/crc32_I8.c  
bitcount_I4.o : $(AUTOGEN_SRC_DIR)/bitcount_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bitcount_I4.c  
bitcount_I8.o : $(AUTOGEN_SRC_DIR)/bitcount_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bitcount_I8.c  
is_s_in_f_seq_I1.o : $(AUTOGEN_SRC_DIR)/is_s_in_f_seq_I1.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/is_s_in_f_seq_I1.c  
is_s_in_f_seq_I2.o : $(AUTOGEN_SRC_DIR)/is_s_in_f_seq_I2.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/is_s_in_f_seq_I2.c  
is_s_in_f_seq_I4.o : $(AUTOGEN_SRC_DIR)/is_s_in_f_seq_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/is_s_in_f_seq_I4.c  
is_s_in_f_seq_I8.o : $(AUTOGEN_SRC_DIR)/is_s_in_f_seq_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/is_s_in_f_seq_I8.c  
srt_uniform_I4.o : $(AUTOGEN_SRC_DIR)/srt_uniform_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/srt_uniform_I4.c  
srt_uniform_I8.o : $(AUTOGEN_SRC_DIR)/srt_uniform_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/srt_uniform_I8.c  
hash_I4.o : $(AUTOGEN_SRC_DIR)/hash_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/hash_I4.c  
hash_I8.o : $(AUTOGEN_SRC_DIR)/hash_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/hash_I8.c  

find_largest_leq_I4.o : $(AUTOGEN_SRC_DIR)/find_largest_leq_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/find_largest_leq_I4.c  
find_largest_leq_I8.o : $(AUTOGEN_SRC_DIR)/find_largest_leq_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/find_largest_leq_I8.c  

find_smallest_geq_I4.o : $(AUTOGEN_SRC_DIR)/find_smallest_geq_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/find_smallest_geq_I4.c  
find_smallest_geq_I8.o : $(AUTOGEN_SRC_DIR)/find_smallest_geq_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/find_smallest_geq_I8.c  

qsort_asc_I1.o : $(AUTOGEN_SRC_DIR)/qsort_asc_I1.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_asc_I1.c  
qsort_asc_I4.o : $(AUTOGEN_SRC_DIR)/qsort_asc_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_asc_I4.c  
qsort_asc_I8.o : $(AUTOGEN_SRC_DIR)/qsort_asc_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_asc_I8.c  
qsort_dsc_I4.o : $(AUTOGEN_SRC_DIR)/qsort_dsc_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_dsc_I4.c  
qsort_dsc_I8.o : $(AUTOGEN_SRC_DIR)/qsort_dsc_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_dsc_I8.c  

qsort_with_idx_int.o : $(AUTOGEN_SRC_DIR)/qsort_with_idx_int.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_with_idx_int.c  
qsort_with_idx_longlong.o : $(AUTOGEN_SRC_DIR)/qsort_with_idx_longlong.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_with_idx_longlong.c  
#------------------------------------------------------------
qsort_asc_val_I4_idx_I4.o : $(AUTOGEN_SRC_DIR)/qsort_asc_val_I4_idx_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_asc_val_I4_idx_I4.c  
qsort_asc_val_I4_idx_I8.o : $(AUTOGEN_SRC_DIR)/qsort_asc_val_I4_idx_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_asc_val_I4_idx_I8.c  
qsort_asc_val_I8_idx_I4.o : $(AUTOGEN_SRC_DIR)/qsort_asc_val_I8_idx_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_asc_val_I8_idx_I4.c  
qsort_asc_val_I8_idx_I8.o : $(AUTOGEN_SRC_DIR)/qsort_asc_val_I8_idx_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_asc_val_I8_idx_I8.c  
#--------------------------------------------------------------------------
qsort_dsc_val_I4_idx_I4.o : $(AUTOGEN_SRC_DIR)/qsort_dsc_val_I4_idx_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_dsc_val_I4_idx_I4.c  
qsort_dsc_val_I4_idx_I8.o : $(AUTOGEN_SRC_DIR)/qsort_dsc_val_I4_idx_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_dsc_val_I4_idx_I8.c  
qsort_dsc_val_I8_idx_I4.o : $(AUTOGEN_SRC_DIR)/qsort_dsc_val_I8_idx_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_dsc_val_I8_idx_I4.c  
qsort_dsc_val_I8_idx_I8.o : $(AUTOGEN_SRC_DIR)/qsort_dsc_val_I8_idx_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/qsort_dsc_val_I8_idx_I8.c  
#--------------------------------------------------------------------------
core_srt_join_I4_I4_I4.o : $(AUTOGEN_SRC_DIR)/core_srt_join_I4_I4_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_srt_join_I4_I4_I4.c  
core_srt_join_I4_I4_I8.o : $(AUTOGEN_SRC_DIR)/core_srt_join_I4_I4_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_srt_join_I4_I4_I8.c  
core_srt_join_I8_I4_I4.o : $(AUTOGEN_SRC_DIR)/core_srt_join_I8_I4_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_srt_join_I8_I4_I4.c  
core_srt_join_I8_I4_I8.o : $(AUTOGEN_SRC_DIR)/core_srt_join_I8_I4_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_srt_join_I8_I4_I8.c  
core_srt_join_I4_I8_I4.o : $(AUTOGEN_SRC_DIR)/core_srt_join_I4_I8_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_srt_join_I4_I8_I4.c  
core_srt_join_I4_I8_I8.o : $(AUTOGEN_SRC_DIR)/core_srt_join_I4_I8_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_srt_join_I4_I8_I8.c  
core_srt_join_I8_I8_I4.o : $(AUTOGEN_SRC_DIR)/core_srt_join_I8_I8_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_srt_join_I8_I8_I4.c  
core_srt_join_I8_I8_I8.o : $(AUTOGEN_SRC_DIR)/core_srt_join_I8_I8_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_srt_join_I8_I8_I8.c  
#--------------------------------------------------------------------------
vec_abs_I4.o : vec_abs_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c vec_abs_I4.c  
vec_abs_F4.o : vec_abs_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c vec_abs_F4.c  
vec_abs_F8.o : vec_abs_F8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c vec_abs_F8.c  
vec_sqrt_F4.o : vec_sqrt_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c vec_sqrt_F4.c  
vec_sqrt_F8.o : vec_sqrt_F8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c vec_sqrt_F8.c  
vec_reciprocal_F4.o : vec_reciprocal_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c vec_reciprocal_F4.c  
vec_reciprocal_F8.o : vec_reciprocal_F8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c vec_reciprocal_F8.c  
#--------------------------------------------------------------------------
core_wisifxthenyelsez_I4.o : $(AUTOGEN_SRC_DIR)/core_wisifxthenyelsez_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_wisifxthenyelsez_I4.c  
core_wisifxthenyelsez_I8.o : $(AUTOGEN_SRC_DIR)/core_wisifxthenyelsez_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_wisifxthenyelsez_I8.c  
core_wisifxthenyelsez_I1.o : $(AUTOGEN_SRC_DIR)/core_wisifxthenyelsez_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_wisifxthenyelsez_I1.c  
core_wisifxthenyelsez_I2.o : $(AUTOGEN_SRC_DIR)/core_wisifxthenyelsez_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_wisifxthenyelsez_I2.c  
core_wisifxthenyelsez_F4.o : $(AUTOGEN_SRC_DIR)/core_wisifxthenyelsez_F4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/core_wisifxthenyelsez_F4.c  
#--------------------------------------------------------------------------
is_sorted_alldef_I1.o : $(AUTOGEN_SRC_DIR)/is_sorted_alldef_I1.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/is_sorted_alldef_I1.c  
is_sorted_alldef_I2.o : $(AUTOGEN_SRC_DIR)/is_sorted_alldef_I2.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/is_sorted_alldef_I2.c  
is_sorted_alldef_I4.o : $(AUTOGEN_SRC_DIR)/is_sorted_alldef_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/is_sorted_alldef_I4.c  
is_sorted_alldef_I8.o : $(AUTOGEN_SRC_DIR)/is_sorted_alldef_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/is_sorted_alldef_I8.c  
#--------------------------------------------------------------------------
bin_search_I1.o : $(AUTOGEN_SRC_DIR)/bin_search_I1.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bin_search_I1.c  
bin_search_I2.o : $(AUTOGEN_SRC_DIR)/bin_search_I2.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bin_search_I2.c  
bin_search_I4.o : $(AUTOGEN_SRC_DIR)/bin_search_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bin_search_I4.c  
bin_search_I8.o : $(AUTOGEN_SRC_DIR)/bin_search_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bin_search_I8.c  
bin_search_UI4.o : $(AUTOGEN_SRC_DIR)/bin_search_UI4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bin_search_UI4.c  
bin_search_UI8.o : $(AUTOGEN_SRC_DIR)/bin_search_UI8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/bin_search_UI8.c  
#--------------------------------------------------------------------------
countf_nn_I1.o : $(AUTOGEN_SRC_DIR)/countf_nn_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/countf_nn_I1.c  
countf_nn_I2.o : $(AUTOGEN_SRC_DIR)/countf_nn_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/countf_nn_I2.c  
countf_nn_I4.o : $(AUTOGEN_SRC_DIR)/countf_nn_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/countf_nn_I4.c  
countf_nn_I8.o : $(AUTOGEN_SRC_DIR)/countf_nn_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/countf_nn_I8.c  
#--------------------------------------------------------------------------
countf_I1.o : $(AUTOGEN_SRC_DIR)/countf_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/countf_I1.c  
countf_I2.o : $(AUTOGEN_SRC_DIR)/countf_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/countf_I2.c  
countf_I4.o : $(AUTOGEN_SRC_DIR)/countf_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/countf_I4.c  
countf_I8.o : $(AUTOGEN_SRC_DIR)/countf_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/countf_I8.c  
#--------------------------------------------------------------------------

par_count_I1.o : $(AUTOGEN_SRC_DIR)/par_count_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/par_count_I1.c  
par_count_I2.o : $(AUTOGEN_SRC_DIR)/par_count_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/par_count_I2.c  
#--------------------------------------------------------------------------
par_count_cfld_I1.o : $(AUTOGEN_SRC_DIR)/par_count_cfld_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/par_count_cfld_I1.c  
par_count_cfld_I2.o : $(AUTOGEN_SRC_DIR)/par_count_cfld_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/par_count_cfld_I2.c  
#--------------------------------------------------------------------------
par_countf_I1.o : $(AUTOGEN_SRC_DIR)/par_countf_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/par_countf_I1.c  
par_countf_I2.o : $(AUTOGEN_SRC_DIR)/par_countf_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/par_countf_I2.c  
#--------------------------------------------------------------------------
par_countf_cfld_I1.o : $(AUTOGEN_SRC_DIR)/par_countf_cfld_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/par_countf_cfld_I1.c  
par_countf_cfld_I2.o : $(AUTOGEN_SRC_DIR)/par_countf_cfld_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/par_countf_cfld_I2.c  
#--------------------------------------------------------------------------
count_nn_I1.o : $(AUTOGEN_SRC_DIR)/count_nn_I1.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/count_nn_I1.c  
count_nn_I2.o : $(AUTOGEN_SRC_DIR)/count_nn_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/count_nn_I2.c  
count_nn_I4.o : $(AUTOGEN_SRC_DIR)/count_nn_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/count_nn_I4.c  
count_nn_I8.o : $(AUTOGEN_SRC_DIR)/count_nn_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/count_nn_I8.c  
#--------------------------------------------------------------------------
count_I1.o : $(AUTOGEN_SRC_DIR)/count_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/count_I1.c  
count_I2.o : $(AUTOGEN_SRC_DIR)/count_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/count_I2.c  
count_I4.o : $(AUTOGEN_SRC_DIR)/count_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/count_I4.c  
count_I8.o : $(AUTOGEN_SRC_DIR)/count_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/count_I8.c  
#--------------------------------------------------------------------------
which_bin_I4.o : $(AUTOGEN_SRC_DIR)/which_bin_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/which_bin_I4.c  
which_bin_I8.o : $(AUTOGEN_SRC_DIR)/which_bin_I8.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/which_bin_I8.c  
#--------------------------------------------------------------------------
patmatch_I1.o : $(AUTOGEN_SRC_DIR)/patmatch_I1.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/patmatch_I1.c  
patmatch_I2.o : $(AUTOGEN_SRC_DIR)/patmatch_I2.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/patmatch_I2.c  
patmatch_I4.o : $(AUTOGEN_SRC_DIR)/patmatch_I4.c  
	 $(CC) $(GCCFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/patmatch_I4.c  
#--------------------------------------------------------------------------
union_I4.o : $(AUTOGEN_SRC_DIR)/union_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/union_I4.c  
union_I8.o : $(AUTOGEN_SRC_DIR)/union_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/union_I8.c  
intersection_I4.o : $(AUTOGEN_SRC_DIR)/intersection_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/intersection_I4.c  
intersection_I8.o : $(AUTOGEN_SRC_DIR)/intersection_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/intersection_I8.c  
a_minus_b_I4.o : $(AUTOGEN_SRC_DIR)/a_minus_b_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/a_minus_b_I4.c  
a_minus_b_I8.o : $(AUTOGEN_SRC_DIR)/a_minus_b_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/a_minus_b_I8.c  
#--------------------------------------------------------------------------
par_sort_with_bins_I4.o : $(AUTOGEN_SRC_DIR)/par_sort_with_bins_I4.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/par_sort_with_bins_I4.c  
par_sort_with_bins_I8.o : $(AUTOGEN_SRC_DIR)/par_sort_with_bins_I8.c  
	 $(CC) $(CFLAGS) $(INCLUDES) -c $(AUTOGEN_SRC_DIR)/par_sort_with_bins_I8.c  
