// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <time.h>
// #include <sys/types.h>
// #include <unistd.h>
// #include <sys/stat.h>
// #include <sys/wait.h>

// // read all the quotes from quotes.txt
// // when client asks for a motivational quote, select one randomly and send it out.
// //runCommand() 
// //  strtok to populate args
// //  execvp(args[0], args)
// //main(): 
// //  create one pipe 
// //  fork():
// //      configure pipe for cmd #2
// //      child: runCommand(argv[2])
// //  configure pipe for cmd #2
// //  parent: runCommand(argv[1])

// #define MAXQUOTES 10000
// #define MAXLEN 1000

// char *quotes[MAXQUOTES];
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
//     commands[0] = strtok(line, "|\n");
//     numPipes = 1;
//     while (commands[numPipes] = strtok(NULL, "|\n"))
//     {
//         numPipes++;
//     }
//     numPipes--;
//     pipe(fds[0]);
//     for(int i = 0; i < numPipes; i++) {
//         if (fork() == 0) {
//             close(0);
//             dup(fds[0][0]);
//             close(fds[0][1]);
//             runCommand(commands[0]);
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
// }

// int main()
// {
//     char line[MAXLEN];
//     // srand(getpid() + time(NULL) + getuid());
//     // read the input line
//     while (1)
//     {
//     //     srand(getpid() + time(NULL) + getuid());
//     //     int quoteNumber = rand() % numQuotes;
// 	   // printf("%s", quotes[quoteNumber]);
//         fprintf(stderr, "# ");
//         fgets(line, 1000, stdin);

//         // spawn a child for taking care of it
//         if (fork() == 0)
//             processLine(line);
//         int x = 0;
//         wait(&x);
//     }
// }
