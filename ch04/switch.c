#include <stdio.h>
#include <stdlib.h>

int main(void){
    /* 
     switch ( expression ) {
         case constant-expression:
     }
     
     expression 的结果必须是整型值，注意 char 是整型 
     constant-expression 是在编译期间求值的表达式
     */
    char option = 'H';
    switch (option) {
        case 'A':
        case 'H':
            printf("Hi\n");
        case 'G':
            printf("Happy New Year!\n");
            break;
    }

    return EXIT_SUCCESS;
}
