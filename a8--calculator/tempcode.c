#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAXQUOTES 10000
#define MAXLEN 1000

char *commands[100];
int fds[100][2];
int numPipes = 1;

void runCommand(char *command) {
	char *arguments[MAXLEN];
    char *cmd = strtok(command, " \n");

    arguments[0] = cmd;
    int i = 1;
    while ((arguments[i] = strtok(NULL, " \n")) != NULL)
    {
        i++;
    }
    execvp(cmd, arguments);
    fputs("I hope you don't see me!\n", stderr);
}

void child(int i) {
	if(i > 0) {
    	close(0);
    	dup(fds[i-1][0]);
	}
	if(i < numPipes) {
    	close(1);
    	dup(fds[i][1]);
	}
	for(int j = 0; j < numPipes; j++) {
		close(fds[j][1]);
		close(fds[j][0]);
	}
	runCommand(commands[i]);
}

void processLine(char *line) {
	char *pipePtr = strchr(line, '|');
	char *equalPtr = strchr(line, '=');
    	if (pipePtr) { //not NULL
		numPipes = 1;
	    commands[0] = strtok(line, "|\n");
	    while (commands[numPipes] = strtok(NULL, "|\n"))
	    {
	         numPipes++;
	    }
	    numPipes--;
        for(int i = 0; i < numPipes; i++) {
                pipe(fds[i]);
        }
		for(int i = 1; i <= numPipes; i++) {
			if(fork() == 0)
				child(i);
		}
		child(0);
    	} else if (equalPtr) {
			commands[0] = line;
			*equalPtr = 0;
			commands[1] = equalPtr+1;
    		//command has = operator, so 2 commands --> 2 processes
    		pipe(fds[0]);
    		pipe(fds[1]);

			if(fork() == 0) {
				close(1);
				dup(fds[0][1]);
				close(0);
				dup(fds[1][0]);
				//close(fds[0][1]);
				runCommand(commands[1]);
			} else {
				close(0);
				dup(fds[0][0]);
				close(1);
				dup(fds[1][1]);
				runCommand(commands[0]);
			}
        } else  {
    		runCommand(line);
        }
}

int main() {
    char *quotes[MAXQUOTES];
    int numQuotes = 0;
    char line[MAXLEN];

	FILE *fp = fopen("quotes.txt", "r");
	int i=0;

	while (fgets(line, MAXLEN, fp)) {
		quotes[i] = (char *) malloc(strlen(line)+1);
		strcpy(quotes[i], line);
		i++;
	}
	numQuotes = i;
	while(1) {
	    srand(time(NULL)); 
	    printf(quotes[rand()%numQuotes]);
		fprintf(stderr, "# ");
		fgets(line, 1000, stdin);

		if (fork() == 0) 
			processLine(line);
		int x=0;
		wait(&x);
	}
}