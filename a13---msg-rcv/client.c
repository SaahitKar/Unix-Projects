// // C Program for Message Queue (Writer Process)
// #include <stdio.h>
// #include <sys/ipc.h>
// #include <sys/msg.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX 100
  
// // structure for message queue
// struct mesg_buffer {
//     long mesg_type;
//     char mesg_text[100];
// } message;
  
// int main(int argc, char *argv[])
// {
//     key_t key;
//     int msgid;
  
//     // ftok to generate unique key
//     key = ftok(getenv("HOME"), 1);
  
//   	//fill the data in struct before sending
//     message.mesg_type = 1;
// 	message.mesg_text[0] = NULL;
// 	for(int i=1; i<argc; i++) 
// 		strcat(message.mesg_text, argv[i]);
  	
//     // msgget creates a message queue
//     // and returns identifier
//     int counter = 0;
//     int msgid2 = 0;
//     while(counter < 10) {
//         msgid = msgget(key, 0666 | IPC_CREAT);
    
//     	int key2 = ftok(getenv("HOME"), 2);
//         msgid2 = msgget(key2, 0666 | IPC_CREAT);
//       	printf("Recv Key %d Msgid %d\n", key2, msgid2);
    
//         msgrcv(msgid2, &message, sizeof(message), 1, 0);
//         printf("Data Received is : %s \n", message.mesg_text);
        
//         printf("Send Key %d Msgid %d\n", key, msgid);
    
//         // msgsnd to send message
//         char text[MAX];
//         fgets(text,stdin,MAX);
//         // message.mesg_text = text;
//         msgsnd(msgid, &message, sizeof(message), 0);
//         // display the message
//         printf("Data send is : %s\n", message.mesg_text);
//         counter++;
//     }
//     msgctl(msgid2, IPC_RMID, NULL);
//     return 0;
// }