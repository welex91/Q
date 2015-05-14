/* DO NOT AUTO GENERATE HEADER FILE  */
// XTYPE I4
// ITYPE int
// NBITS 32
      short *I2ptr = (short*)X; I2ptr += lb;
#ifdef IPP
      ippsSet_16s(I2val, I2ptr, nX);
#else
      assign_const_I2(I2ptr, nX, I2val);
#endif
      break;
