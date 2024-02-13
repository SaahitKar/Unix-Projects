// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <time.h>
// #include <string.h>

// int main()
// {
//     srand(time(NULL));
//     // char *mini = argv[1], *maxi = argv[2], *minL = argv[3], *minU = argv[4], *minD = argv[5], *minS = argv[6];
//     // int min = atoi(mini), max = atoi(maxi), minLower = atoi(minL), minUpper = atoi(minU), minDigits = atoi(minD), minSpecial = atoi(minS); 
//     int min = 0, max = 0, minLower = 0, minUpper = 0, minDigits = 0, minSpecial = 0; 

//     char passwd[1000] = {};
//     scanf("%d %d %d %d %d %d", &min, &max, &minLower, &minUpper, &minDigits, &minSpecial);
//     int randomizer = 0;
//     int i = 0;
//     while (minLower > 0  || minUpper > 0 || minDigits > 0 || minSpecial > 0) {
//         randomizer = rand() % 4;
//         if (randomizer == 0 && minLower > 0) {
//             char lalphaChars[] = "abcdefghijklmnopqrstuvwxyz";
//             char randomletter2 = lalphaChars[rand() % (sizeof(lalphaChars) - 1)];
//             passwd[i] = randomletter2;
//             minLower--;
//             i++;
//         }
//         else if (randomizer == 1 && minUpper > 0) {
//             char ualphaChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//             char randomletter1 = ualphaChars[rand() % (sizeof(ualphaChars) - 1)];
//             passwd[i] = randomletter1;
//             minUpper--;
//             i++;
//         }
//         else if (randomizer == 2 && minDigits > 0) {
//             char numberChars[] = "1234567890";
//             char randomletter3 = numberChars[rand() % (sizeof(numberChars) - 1)];
//             passwd[i] = randomletter3;
//             minDigits--;
//             i++;
//         } 
//         else if (randomizer == 3 && minSpecial > 0) {
//             char specialChars[] = "@#$%^&*+:;";
//             char randomSpecial = specialChars[rand() % (sizeof(specialChars) - 1)];
//             passwd[i] = randomSpecial;
//             minSpecial--;
//         i++;
//         }
//     }
//     printf("%s", passwd);
//     return 0;
// }


