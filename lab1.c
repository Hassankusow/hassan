#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>

void float_to_hex(float value);
void double_to_hex(double value);
void hex_to_float(const char *hex_string);
void hex_to_double(const char *hex_string);
void print_double(double value);

int getopt_long(int argc, char * const argv[],
                const char *optstring, const struct option *longopts,
                int *longindex);

const int MAX_STRING_LENGTH = 256;
void print_help() {
    printf("./lab1 [options]\n");
    printf("Options:\n");
    printf("  --hex-float <value>   \n");
    printf("  --hex-double <value>  \n");
    printf("  --float-hex <value>   \n");
    printf("  --float-double <value>\n");
    printf("  --print <value>       \n");
    printf("  -h, --help            Print help message\n");

}

int main(int argc, char *argv[]) {
    int opt;
struct option long_options[] = {
        {"hex-float", required_argument, 0, 'x'},
        {"hex-double", required_argument, 0, 'X'},
        {"float-hex", required_argument, 0, 'f'},
        {"float-double", required_argument, 0, 'd'},
        {"print", required_argument, 0, 'p'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

while ( (opt = getopt_long(argc, argv, "x:X:f:d:p:h", long_options, NULL)) != -1) {
        switch (opt) {
            case 'x':
                hex_to_float(optarg);
                break;
            case 'X':
                hex_to_double(optarg);
                break;
            case 'f':
                float_to_hex(atof(optarg));
                break;
            case 'd':
                double_to_hex(atof(optarg));
                break;
            case 'p':
                print_double(atof(optarg));
                break;
            case 'h':
                print_help();
                break;
            default:
                print_help();
                return 1;
        }
    }

    return 0;    
}


void float_to_hex(float value) {
    unsigned int hex = *(unsigned int *)&value;
    printf("Hex representation of %.6f (single precision): 0x%x\n", value, hex);
}


void double_to_hex(double value) {
    unsigned long long hex = *(unsigned long long *)&value;
    printf("Hex representation of %.6f (double precision): 0x%llx\n", value, hex);
}

void hex_to_float(const char *hex_string) {
    unsigned int hex;
    sscanf(hex_string, "%x", &hex);
    float value = *(float *)&hex;
    printf("Floating point value of 0x%s (single precision): %.6f\n", hex_string, value);
}


void hex_to_double(const char *hex_string) {
    unsigned long long hex;
    sscanf(hex_string, "%llx", &hex);
    double value = *(double *)&hex;
    printf("Floating point value of 0x%s (double precision): %.6f\n", hex_string, value);
}


void print_double(double value) {
    
    char *str = (char *)&value;
    printf("String interpretation: %s\n", str);

    
    float *float_ptr = (float *)&value;
    printf("Two consecutive floating point values: %.6f, %.6f\n", float_ptr[0], float_ptr[1]);

    
    unsigned long long hex = *(unsigned long long *)&value;
    printf("Hex representation: 0x%llx\n", hex);

   
    int *int_ptr = (int *)&value;
    printf("Two 32-bit signed integers (little-endian): %d, %d\n", int_ptr[0], int_ptr[1]);
    printf("Two 32-bit signed integers (big-endian): %d, %d\n", int_ptr[1], int_ptr[0]);

    
    unsigned int *uint_ptr = (unsigned int *)&value;
    printf("Two 32-bit unsigned integers (little-endian): %u, %u\n", uint_ptr[0], uint_ptr[1]);
    printf("Two 32-bit unsigned integers (big-endian): %u, %u\n", uint_ptr[1], uint_ptr[0]);

   
    long long *long_ptr = (long long *)&value;
    printf("One 64-bit signed integer (little-endian): %lld\n", *long_ptr);
    printf("One 64-bit signed integer (big-endian): %lld\n", *long_ptr);

    unsigned long long *ulong_ptr = (unsigned long long *)&value;
    printf("One 64-bit unsigned integer (little-endian): %llu\n", *ulong_ptr);
    printf("One 64-bit unsigned integer (big-endian): %llu\n", *ulong_ptr);
}
