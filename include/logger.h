extern int lock_log_file(
    )
;
//----------------------------
extern int unlock_log_file(
    )
;
//----------------------------
extern void log_request(
    int argc,
    char **argv,
    unsigned long long *ptr_t_before
    )
;
//----------------------------
extern void
log_response(
    int status,
    unsigned long long t_before
    )
;
//----------------------------
