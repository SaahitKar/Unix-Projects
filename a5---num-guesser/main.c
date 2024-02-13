// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// void guess(int number)
// {
// 	int guess, numberOfGuesses = 0, N = 100;
// 	do {
// 	    printf("Enter your guess: ");
// 		scanf("%d", &guess);
// 		if (guess > number) {
// 			printf("Go lower!\n");
// 			numberOfGuesses++;
// 		}
// 		else if (guess < number) {
// 			printf("Go higher!\n");
// 			numberOfGuesses++;
// 		}
// 		else {
// 			printf("You guessed the number in %d attempts!\n", numberOfGuesses);
// 		}
// 	} while (guess != number);
// }

// int main() {
// 	srand(time(NULL));
// 	int number = rand() % 100 + 1;
// 	printf("Ok, I am ready!\n");
// 	printf("%d\n", number);
// 	guess(number);

// 	return 0;
// }
