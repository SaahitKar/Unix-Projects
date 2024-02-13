// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>

// int fds[100][2];
// #define MAXLEN 1000

// int child(char operators, int index, int numOperators) {
// 	close(0);     
// 	if(!index) {
// 	    dup(fds[0][0]);
// 	} else {
// 		dup(fds[index*2][0]);
// 	}
// 	//setup FD 3 for reading 2nd parameter
// 	close(3);
// 	dup(fds[index*2+1][0]);
// 	//setup FD 1 for outputing the result
// 	close(1);
// 	dup(fds[index*2+2][1]);
//  	for(int i = 0; i < 2*numOperators; i++) {
// 		close(fds[i][0]);
//         close(fds[i][1]);
//  	}
// 	 switch(operators) {
//             case '+':
//             execl("./add", "add", NULL);
//             break;
//             case '-':
// 			execl("./subtract", "subtract", NULL);
//             break;
//             case '*':
//             execl("./multiply", "multiply", NULL);
//             break;
//             case '/':
//             execl("./divide", "divide", NULL);
//             break;
//     }
//     exit(1);
// }

// int main(int argc, char *argv[]) {
//     char line[1000];
//     int numOperators = 0;
//     char operators[100];
// 	FILE *filep = fopen(argv[1], "r");
// 	fgets(line, MAXLEN, filep);
// 	strtok(line, " \n");
//     char *cptr;
//     int inpu = 0;
//     while(cptr = strtok(NULL, " \n")) {
//         operators[numOperators++] = *cptr;
//         strtok(NULL, " \n");
//     }
//     for(int i = 0; i < 2*numOperators+1; i++) {
//         pipe(fds[i]);
//     }
//     for(int i = 0; i < numOperators; i++) {
// 		if (!fork()) {
//         	child(operators[i], i, numOperators);
// 		}
//     }
// 	int input = 0;
// 	while(fscanf(filep, "%d", &input) > 0) {
// 		write(fds[0][1], &input, sizeof(int));
// 		for(int i = 0; i < numOperators; i++) {
//     		//write y to second pipe
// 			fscanf(filep, "%d", &input);
//     		write(fds[i*2+1][1], &input, sizeof(int));
// 		}
// 		read(fds[2*numOperators][0], &input, sizeof(int));
// 		printf("%d \n", input);
// 	}
// 	fclose(filep);
// }