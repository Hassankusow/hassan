#include <studio.h>

struct option {
        const char *name;
        int         has_arg;
        int        *flag;
        int         val;
};

