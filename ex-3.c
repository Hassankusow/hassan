#include <stdio.h>

int main() {
    char blank = ' ';
    char newline = '\n';
    char tab = '\t';

    char input;

    int blanks = 0;
    int newlines = 0;
    int tabs = 0;

    while((scanf("%c", &input) != EOF)){
        if (input == blank) ++blanks;
        else if (input == tab) ++tabs;
        else if (input == newline) ++newlines;
	if (input == '1') {
            break;
        }
        
    }

    if (feof(stdin)) {
        printf("End of input reached.\n");
    } else {
        printf("Error reading input.\n");
    }

    printf("Number of tabs:\t\t%d\n", tabs);
    printf("Number of blanks:\t%d\n", blanks);
    printf("Number of newlines:\t%d\n", newlines);

    return 0;
}

