//Usage: quoteclient <server-fifo-filename>
//
//create own named pipe (fifo) and set permissions
//send this fifo name to server
//open own named pipe
//read the quote and display

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAXLEN 1000

int main(int argc, char *argv[]) {

    char clientfifo[MAXLEN];
	sprintf(clientfifo, "/tmp/%s-%d", getenv("USER"), getpid());
	mkfifo(clientfifo, 0600);
	chmod(clientfifo, 0622);
	
	char temp[MAXLEN];
	strcpy(temp, "/tmp/8234");
	FILE *fp = fopen(temp, "w");
	fprintf(fp, "%s\n", clientfifo);
	fclose(fp);

	FILE *clientfp = fopen(clientfifo, "r");
	char serverfifo[MAXLEN];
	fscanf(clientfp, "%s", serverfifo);
	char line[MAXLEN];
	fgets(line, MAXLEN, clientfp); 

	FILE *serverfp = fopen(serverfifo, "w");
	pid_t childPID = fork();
	if(childPID) {
    	while (1) {
    	    fgets(line, MAXLEN, clientfp);
    	    char *cptr = strchr(line, '\n');
    	    if (cptr)
    	        *cptr = '\0';
    	    if(strlen(line) < 20)
    	        printf("\n");
    	    printf("%s", line);
    	    fflush(stdout);
    	    
    	    if(strstr(line, "You") != NULL) {
    	        printf("\n");
    	        break;
    	    }
    	}
	} else 
	    while(1) {
	        fgets(line, MAXLEN, stdin);
	           
	       fprintf(serverfp, "%s\n", line);
	       fflush(serverfp);
	    }
	    
	fclose(clientfp);
	unlink(clientfifo);
}