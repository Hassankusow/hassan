#include <studio.h>

struct option {
        const char *name;
        int         has_arg;
        int        *flag;
        int         val;
};

void float_to_hex(float value);
void double_to_hex(double value);
void hex_to_float(const char *hex_string);
void hex_to_double(const char *hex_string);
void print_double(double value);
