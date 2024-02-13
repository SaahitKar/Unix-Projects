#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int ground(double guessValue) {
    if(guessValue < 0) {
        return guessValue - .1;
    } else {
        return guessValue + .5;
    }
}

int main() {
    double guess = 50;
    double guessValue = 50;
    int display = 0;
    char input = '\n';
    while(input != '=') {
        display = guess;
        printf("How about %d? (<,=,>) ", display);
        scanf(" %c", &input);
        if(input == '<') {
            guessValue = guessValue / 2;
            guess = guess - ground(guessValue);
            display = guess;
        }
        if(input == '>') {
            guessValue = guessValue / 2;
            guess = guess + ground(guessValue);
            display = guess;
        }
    }
    printf("It was a good game!");
    return 0;
}