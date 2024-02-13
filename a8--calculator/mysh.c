// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>
// #include <stdlib.h>
// #include <time.h>
// #include <sys/types.h>
// #include <unistd.h>
// #include <sys/stat.h>
// #include <sys/wait.h>

// // read all the quotes from quotes.txt
// // when client asks for a motivational quote, select one randomly and send it out.

// #define MAXQUOTES 10000
// #define MAXLEN 1000

// char *commands[100];
// int fds[100][2];
// int numPipes = 1;

// // runs a simple command
// void runCommand(char *command)
// {
//     char *arguments[MAXLEN];
//     char *cmd = strtok(command, " \n");

//     arguments[0] = cmd;
//     int i = 1;
//     while ((arguments[i] = strtok(NULL, " \n")) != NULL)
//     {
//         i++;
//     }
//     execvp(cmd, arguments);
//     fputs("I hope you don't see me!\n", stderr);
// }

// void processLine(char *line)
// {
//     /*b
//     create children and communicate between them using pipes
//     */
// //     char *pipePtr = strchr(line, '|');
// // 	char *equalPtr = strchr(line, '=');
// // 	if (pipePtr) { //not NULL
// // 		command has several sub-commands connected with pipes
// // 		setup commands array
// // 		setup pipes array
// // 		create children --> invoke child(i) in a loop
// // 		//cmd0 | cmd1 | cmd2 | cmd3 | cmd4 
// // 	} else if (equalPtr) {
// // 		command has = operator, so 2 commands --> 2 processes
		
// //     } else 
// // 		//it is a simple command, no pipe or = character
// // 		runCommand(line);
// //     }
//     commands[0] = strtok(line, "|\n");
// 	bool equal = false;
//     numPipes = 1;
//     while (commands[numPipes] = strtok(NULL, "|\n"))
//     {
//         numPipes++;
// 		if(commands[numPipes] == "=") {
// 			equal = true;	
// 		}
//     }
//     numPipes--;
// 	if(equal) {
// 		close(0);
// 		dup(fds[0][0]);
// 		close(fds[0][1]);
// 		runCommand(commands[0]);
// 		close(1);
// 		dup(fds[0][1]);
// 		close(fds[0][0]);
// 		runCommand(commands[0]);
// 		//runCommand(commands[0]);
		
// 		//fputs("========");
// 		//fprintf(stderr, "++++++++====");
// 	}
//     pipe(fds[0]);
//     for(int i = 0; i < numPipes; i++) {
//         if (fork() == 0) {
//             close(0);
//             dup(fds[0][0]);
//             close(fds[0][1]);
//             runCommand(commands[0]);
// 			//wait(-1);
//         }
//     }
//     // if (fork() == 0)
//     // {
//     //     close(0);
//     //     dup(fds[0][0]);
//     //     close(fds[0][1]);
//     //     runCommand(commands[1]);
//     // }
//     close(1);
//     dup(fds[0][1]);
//     close(fds[0][0]);
//     runCommand(commands[0]);
// 	//wait(-1);
// }

// int main()
// {
//     char line[MAXLEN];
//     // srand(getpid() + time(NULL) + getuid());
//     // int numQuotes = 
//     // read the input line
//     while (1)
//     {
// // 		fprintf(quotes[rand()%numQuotes], stderr);
//         fprintf(stderr, "# ");
//         fgets(line, 1000, stdin);

//         // spawn a child for taking care of it
//         if (fork() == 0)
//             processLine(line);
//         int x = 0;
//         wait(&x);
//     }
// }