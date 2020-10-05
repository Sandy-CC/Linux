#include <errno.h>
#include <stdlib.h> 
#define err_exit(MESSAGE) (                \
    perror(MESSAGE),                       \
    exit(1)                                \
)    
