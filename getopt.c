#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int getopt(int argc
    , char * const argv[]
    , const char * optstring);

extern char *optarg;
extern int optind, opterr, optopt;
void print_help() {
    printf("./getopt: hd:x:o:c:s: '\n'");
}

int main(int argc, char *argv[]) {
    int opt;
    char *endptr;
    long int decimal;
    char character;
    char *string;

    while ((opt = getopt(argc, argv, "hd:x:o:c:s:")) != -1) {
        switch (opt) {
            case 'h':
                print_help();
                return 0;
            case 'd':
                decimal = strtol(optarg, &endptr, 10);
                printf("value = %ld   0x%lx   0%lo\n", decimal, decimal, decimal);
                break;
            case 'x':
                decimal = strtol(optarg, &endptr, 16);
                printf("value = %ld   0x%lx   0%lo\n", decimal, decimal, decimal);
                break;
            case 'o':
                decimal = strtol(optarg, &endptr, 8);
                printf("value = %ld   0x%lx  0%lo\n", decimal, decimal, decimal);
                break;
            case 'c':
                character = optarg[0];
                printf("char = %c   %d   0x%x  0%o\n", character, character, character, character);
                break;
            case 's':
                string = optarg;
                printf("char = %s\n", string);
                printf("  ");
                for (int i = 0; string[i] != '\0'; i++) {
                    printf("0x%x  ", string[i]);
                }
                printf("\n");
                break;
            default:
                fprintf(stderr, "./getopt: invalid option -- '%c'\n", optopt);
                fprintf(stderr, "Unrecognized command line option\n");
                return 1;
        }
    }

    return 0;
}

