/* DO NOT AUTO GENERATE HEADER FILE  */
// XTYPE I4
// ITYPE int
// NBITS 32
      int *I4ptr = (int*)X; I4ptr += lb;
#ifdef IPP
      ippsSet_32s(I4val, I4ptr, nX);
#else
      assign_const_I4(I4ptr, nX, I4val);
#endif
      break;
