// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXQUOTES 1000000
#define MAXLEN 1000

char *quotes[MAXQUOTES];
int numQuotes=0;

// structure for message queue
struct mesg_buffer {
    long mesg_type;
    char mesg_text[100];
} message;
  
int main()
{
	key_t key;
	int msgid;

    // ftok to generate unique key - main server
    key = ftok(getenv("HOME"), 1);
  
  	int counter=0;

    	// msgget creates a message queue and returns identifier
    	msgid = msgget(key, 0666 | IPC_CREAT);
  		printf("Key %d Msgid %d\n", key, msgid);
  	char line[MAXLEN];

	FILE *fp = fopen("dictionary.txt", "r");
	if (!fp) {
		puts("quotes.txt cannot be opened for reading.");
		exit(1);
	}
	int i=0;
  	while (fgets(line, MAXLEN, fp)) {
		quotes[i] = (char *) malloc (strlen(line)+1);
		strcpy(quotes[i], line);
		i++;
	}
	numQuotes = i;
	printf("%d quotes were read.\n", numQuotes);

	while (1) {
        char solution[MAXLEN];
      	srand(getpid() + time(NULL) + getuid());
    	int word = rand() % numQuotes;
      	strcpy(solution, quotes[word]);
    	// msgrcv to receive message
    	msgrcv(msgid, &message, sizeof(message), 1, 0);
    	// to destroy the message queue
    	msgctl(msgid, IPC_RMID, NULL);
		counter++;

//   		if (fork())  //parent goes to while loop
// 			continue;

    	// display the message
    	printf("Data Received is : %s \n", message.mesg_text);
		int clientPid = atoi(message.mesg_text);

		//use clientPid to come up with key & msgid to respond
		int key2 = ftok(getenv("HOME"), clientPid);
    	int msgid2 = msgget(key2, 0666 | IPC_CREAT);
		sprintf(message.mesg_text, "%s", solution);
    	msgsnd(msgid2, &message, sizeof(message), 0);
    	printf("Data Sent is : %s\n", message.mesg_text);
    	msgrcv(msgid2, &message, sizeof(message), 1, 0);
    	msgid = msgget(key, 0666 | IPC_CREAT);
        msgrcv(msgid, &message, sizeof(message), 1, 0);
            // printf("%s", message.mesg_text);
        char temp = message.mesg_text[0];
        printf("(Guess) ENTER LETTER >>> %c", temp);
        msgctl(msgid, IPC_RMID, NULL);
// 		exit(0); //child server exits, after the work.
  	} 
  
    return 0;
}