//SSK190013
//CS3377.005

#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000000];
    fgets(input, 1000000, stdin);
    int ans = 0, backCount = 0;
    
    for(int i = 0; i < (sizeof input / sizeof input[0])-1; i++) {
        for(int j = i+2; j > i; j--) {
            if((input[i] == ')') && (input[i+1] == ')')) {
                ans += backCount;
            } else if((input[i] == '(') && (input[i+1] == '(')) {
                backCount++;
            }
        }
    }
//236676
//236676
    printf("%d\n", ans/4);
    //
    char c = getchar(), prevChar = ' ';
    int ans2 = 0, backCount2 = 0;
     while (c != '\n' && c != EOF) {
        prevChar = c;
        c=getchar();
        if(prevChar == ')' && c == ')') {
            ans2 += backCount2;
        } else  if(prevChar == '(' && c == '(') {
            backCount2++;
        }
        // printf("%c - %c\n", prevChar, c);
    }
     printf("%d", ans2);
    return 0;
}



