#include <stdlib.h>
#include <stdio.h>
#define TRUE 1

void process_standard_input(void) {
}
void process_file(char *file_name) {
    puts(file_name);
}

int option_a, option_b;

int
main(int argc, char **argv)
{
    while(*++argv != NULL && **argv == '-'){
        switch(*++*argv){
            case 'a':
                option_a = TRUE;
                break;
            case 'b':
                option_b = TRUE;
                break;
        }
    }

    printf("%d %d\n", option_a, option_b);

    if(*argv == NULL)
        process_standard_input();
    else {
        do {
            process_file(*argv);
        } while(*++argv != NULL);
    }

    return EXIT_SUCCESS;
}
