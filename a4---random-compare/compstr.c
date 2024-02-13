#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void remove_space(char *first, const char *second){
    for(;*second;++second){
        if(*second != ' ')
            *first++ = *second;
    }
    *first = *second;
}

int main (void) {
    char secuencia[100];
    char secuencia2[100] = "";
    printf("Enter String #1: ");
    fgets(secuencia, 100, stdin);
    printf("Enter String #2: ");
    fgets(secuencia2, 100, stdin);
    int n = strlen(secuencia);
    int n2 = strlen(secuencia2);
    remove_space(secuencia, secuencia);
    remove_space(secuencia2, secuencia2);
    int i = 0,j = 0,k = 0;
    while(i < n) {
        secuencia[i] = tolower(secuencia[i]);
        i++;
    }
    while(j < n2) {
        secuencia2[i] = tolower(secuencia2[i]);
        j++;
    }
    n = strlen(secuencia);
    n2 = strlen(secuencia2);
    int result = 0;
    if(n != n2) {
        result = 1;
    } else {
        while (k < n) {
            if(secuencia[i] != secuencia2[i]) {
                result = 1;
                break;
            }
            k++;
        }
    }
    if(result == 0) {
        printf("\nTrue");
    } else {
        printf("\nFalse");
    }
  return 0;
}