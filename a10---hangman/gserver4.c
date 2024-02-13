#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdbool.h>

//read all the quotes from quotes.txt
//when client asks for a motivational quote, select one randomly and send it out.

#define MAXQUOTES 1000000
#define MAXLEN 1000

char *quotes[MAXQUOTES];
int numQuotes=0;

int main() {
	char line[MAXLEN];

	FILE *fp = fopen("dictionary.txt", "r");
	if (!fp) {
		puts("quotes.txt cannot be opened for reading.");
		exit(1);
	}
	int i=0;

	//read one line at a time, allocate memory, then copy the line into array
	while (fgets(line, MAXLEN, fp)) {
		quotes[i] = (char *) malloc (strlen(line)+1);
		strcpy(quotes[i], line);
		i++;
	}
	numQuotes = i;
	printf("%d quotes were read.\n", numQuotes);

	
	//create a named pipes to read client's requests
	char filename[MAXLEN];
	sprintf(filename, "/tmp/8234", getenv("USER"), getpid());
	mkfifo(filename, 0600);
	chmod(filename, 0622);
// 	printf("Send your requests to %s\n", filename);

	while (1) {
		FILE *fp = fopen(filename, "r");
		if(!fp) {
		  //  printf("FIFO %s cannot be opened for reading\n", filename);
            exit(2);
		}
// 		printf("Opened %s to read ... \n", filename);
		//wait for clients' requests
		while (fgets(line, MAXLEN, fp)) {

			char *cptr = strchr(line, '\n');
			if (cptr)  {
				*cptr = '\0';
			}
			char solution[MAXLEN];
	        srand(getpid() + time(NULL) + getuid());
	        int word = rand() % numQuotes;
	        strcpy(solution, quotes[word]);
			//create a child to work with this client
			if (fork() == 0) {
				FILE *clientfp = fopen(line, "w");
				char serverfifo[MAXLEN];
				sprintf(serverfifo, "/tmp/%s-%d", getenv("USER"), getpid());
				mkfifo(serverfifo, 0600);
				chmod(serverfifo, 0622);

				fprintf(clientfp, "%s\n", serverfifo);
				fflush(clientfp);

				FILE *serverfp = fopen(serverfifo, "r");
				char guess[MAXLEN];
				strcpy(guess, solution);
				for(int i = 0; i < strlen(solution) - 1; i++) {
                        guess[i] = '*';
                }
                fprintf(clientfp, "(Guess) Enter a letter in word %s > \n", guess);
                fflush(clientfp);
                printf("Started new game\n");
                int misses = 0;
                char curGuess[MAXLEN];
                int numGuess = 0;
                while((strcmp(solution, guess) != 0)  && fgets(line, MAXLEN, serverfp)) {
                    char g;
                    sscanf(line, "%c\n", &g);
                    fgets(line, MAXLEN, serverfp);
                    
                    int isInWord = 0;
                    for (int i = 0; i < numGuess; i++) {
                        if(curGuess[i] == g) {
                            isInWord = 1;
                            break;
                        }
                    }
                    
                    if(isInWord != 0) {
                        fprintf(clientfp, "\n%c is already in the word\n", g);
                        fflush(clientfp);
                        fprintf(clientfp, "%s\n", guess);
                        fflush(clientfp);
                        misses++;
                        continue;
                    } else {
                        curGuess[numGuess] = g;
                        numGuess++;
                    }
                    
                    int available = 0;
                    for(int i = 0; i < strlen(solution); i++) {
                        if(solution[i] == g) {
                            guess[i] = g;
                            available++;
                        }
                    }
                    if(available == 0) {
                        fprintf(clientfp, "\n%c is not in the word\n", g);
                        fflush(clientfp);
                        misses++;
                    }
                    //
                    if(strcmp(guess, solution) == 0) {
                        fprintf(clientfp, "%c\n", 7);
                        for(int i = 0; i < strlen(solution); i++) {
                            if(solution[i] == '\n') {
                                solution[i] = 0;
                                break;
                            }
                        }
                        char end = ' ';
                        if(misses > 1) {
                            end = 's';
                        }
                        fprintf(clientfp, "The word is %s. You missed %d time%c\n", solution, misses, end);
                        fflush(clientfp);
                        break;
                    } else {
                        fprintf(clientfp, "%s\n", guess);
                        fflush(clientfp);
                    }
                }
				exit(0);
			}
		}
		fclose(fp);
	}
}