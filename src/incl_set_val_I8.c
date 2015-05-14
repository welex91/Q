/* DO NOT AUTO GENERATE HEADER FILE  */
// XTYPE I4
// ITYPE int
// NBITS 32
      long long *I8ptr = (long long*)X; I8ptr += lb;
#ifdef IPP
      ippsSet_64s(I8val, I8ptr, nX);
#else
      assign_const_I8(I8ptr, nX, I8val);
#endif
      break;
