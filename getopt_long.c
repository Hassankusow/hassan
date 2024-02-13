#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>

int getopt_long(int argc, char * const argv[],
                const char *optstring, const struct option *longopts,
                int *longindex);


const int MAX_STRING_LENGTH = 256;
void print_help() {
    printf("This is a help message:\n");
    printf("\t--float <float value>\n");
    printf("\t--int <int value>\n");
    printf("\t--str <string value>\n");
    printf("\t--rand\n");
    printf("\t--help\n");
}

int main(int argc, char *argv[]) {
    int opt;
    char *endptr;
    long int decimal;
    char str[MAX_STRING_LENGTH];

    struct option long_options[] = {
        {"float", required_argument, 0, 'f'},
        {"int", required_argument, 0, 'i'},
        {"str", required_argument, 0, 's'},
        {"rand", no_argument, 0, 'r'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "f:i:s:rh", long_options, NULL)) != -1) {
        switch (opt) {
            case 'f':
                decimal = strtol(optarg, &endptr, 10);
                printf("float value / 10: %.6f\n", (float)decimal / 10);
                break;
            case 'i':
                decimal = strtol(optarg, &endptr, 10);
                printf("int value + 100: %ld\n", decimal + 100);
                break;
            case 's':
                strncpy(str, optarg, MAX_STRING_LENGTH);
                printf("orig: >%s<  upcase: >", str);
                for (int i = 0; str[i] != '\0'; i++) {
                    printf("%c", toupper(str[i]));
                }
                printf("<\n");
                break;
            case 'r':
                printf("random value = %d\n", rand());
                break;
            case 'h':
                print_help();
                return 0;
            default:
                fprintf(stderr, "Unrecognized command line option\n");
                return 1;
        }
    }

    return 0;
}
