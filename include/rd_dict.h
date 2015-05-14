extern int
rd_dict(
    const unsigned long long *hashvals, /* input dictionary. Part 1 */
    int n_hashvals, /* size of input dictionary */
    const unsigned long long *len_offsets, /* input dictionary. Part 2 */
    const char *rawdata, /* concatenated strings */
    unsigned long long ulhash, /* value for which string is to be found */
    char *buffer, /* where output is stored if found */
    int sz_buffer, 
    unsigned int *ptr_len /* length of output */
    )
;
//----------------------------
