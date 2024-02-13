// // C Program for Message Queue (Reader Process)
// #include <stdio.h>
// #include <sys/ipc.h>
// #include <sys/msg.h>
// #include <stdlib.h>
// #include <signal.h>

// #define MAXQUOTES 1000000
// #define MAXLEN 1000

// char *quotes[MAXQUOTES];
// int numQuotes=0;

// // structure for message queue
// struct mesg_buffer {
//     long mesg_type;
//     char mesg_text[100];
// } message;

// int main()
// {
// 	key_t key;
// 	int msgid;

//     // ftok to generate unique key
//     key = ftok(getenv("HOME"), 1);
  
//   	int counter=3;
  	
//   	char line[MAXLEN];

// 	FILE *fp = fopen("dictionary.txt", "r");
// 	if (!fp) {
// 		puts("quotes.txt cannot be opened for reading.");
// 		exit(1);
// 	}
// 	int i=0;
//   	while (fgets(line, MAXLEN, fp)) {
// 		quotes[i] = (char *) malloc (strlen(line)+1);
// 		strcpy(quotes[i], line);
// 		i++;
// 	}
// 	numQuotes = i;
// 	printf("%d quotes were read.\n", numQuotes);
  	
//   	char solution[MAXLEN];
//   	srand(getpid() + time(NULL) + getuid());
// 	int word = rand() % numQuotes;
//   	strcpy(solution, quotes[word]);
//   	char guess[MAXLEN];
// 	strcpy(guess, solution);
// 	for(int i = 0; i < strlen(solution) - 1; i++) {
//         guess[i] = '*';
//     }

// 	while (1) {
//         	// msgget creates a message queue and returns identifier
//         	msgid = msgget(key, 0666 | IPC_CREAT);
//       		printf("Key %d Msgid %d\n", key, msgid);
    
//         	// msgrcv to receive message
//         	msgrcv(msgid, &message, sizeof(message), 1, 0);
//         	// to destroy the message queue
//         	//msgctl(msgid, IPC_RMID, NULL);
      
//         	// display the message
//         	if(strlen(message.mesg_text) > 1) {
//     			printf("NOT CHAR ENTERED. Please Enter Char. \n");
//     		} else {
//     		    printf("%c", message.mesg_text[0]);
//     		}
//     		char input = message.mesg_text[0];
//         	printf("Data Received is : %s \n", message.mesg_text);
    
//     		//assign dedicated project #s for communication to client
//     		int key2 = ftok(getenv("HOME"), 2);
//         	int msgid2 = msgget(key2, 0666 | IPC_CREAT);
//     		sprintf(message.mesg_text, "%s %s", solution, guess);
//         	msgsnd(msgid2, &message, sizeof(message), 0);
//         	printf("Data Sent is : %s\n", message.mesg_text);
    
//     		counter += 2;
//   	} 
  
//     return 0;
// }