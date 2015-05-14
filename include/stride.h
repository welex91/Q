extern int
stride_I4(
    int *f1,
    long long nR1,
    long long start, 
    long long stride, 
    int *f2,
    long long nR2
    )
;
//----------------------------
extern int
stride_I8(
    long long *f1,
    long long nR1,
    long long start, 
    long long stride, 
    long long *f2,
    long long nR2
    )
;
//----------------------------
extern int 
ext_stride(
	   const char *t1,
	   const char *f1,
	   char *str_start,
	   char *str_stride,
	   const char *t2,
	   const char *f2,
	   char *str_nR2
    )
;
//----------------------------
