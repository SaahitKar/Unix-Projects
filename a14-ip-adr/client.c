#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

int main(int argc, char *argv[])
{
    int sockfd = 0, n = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr; 

    if(argc != 3)
    {
        printf("\n Usage: %s <ip of server> <port #> \n",argv[0]);
        return 1;
    } 

    memset(recvBuff, '0',sizeof(recvBuff));
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    } 

    memset(&serv_addr, '0', sizeof(serv_addr)); 

    serv_addr.sin_family = AF_INET;
	int port = atoi(argv[2]);
    serv_addr.sin_port = htons(port); 

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
    {
        printf("\n inet_pton error occured\n");
        return 1;
    } 

    if( connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
       printf("\n Error : Connect Failed \n");
       return 1;
    } 

	//read a line from the user and send it to the server
	//read a line from the server and display it
	while (fgets(recvBuff, sizeof(recvBuff), stdin) > 0) {
		write(sockfd, recvBuff, strlen(recvBuff)+1);
		if ((n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0) {
            printf("%c", recvBuff[0]);
            // puts(arr);
// 			puts(recvBuff);
		} else
			break;
	}
	/*
    while ( (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
        recvBuff[n] = 0;
        if(fputs(recvBuff, stdout) == EOF)
        {
            printf("\n Error : Fputs error\n");
        }
    } 

    if(n < 0)
    {
        printf("\n Read error \n");
    } 
	*/

    return 0;
}

// 	int len = sizeof(recvBuff)/sizeof(recvBuff[0]);
        // 	char arr[1024];
        // 	for(int i = 0; i < 1024; i++) {
        // 	    arr[i] = (int) recvBuff[i];
        // 	}
        // // 	int cet = (int) recvBuff[n];
        // // 	printf("CET: %d", cet);
        // 	recvBuff[n] = 0;
        // 	int arret[5];
        // 	int count = 0;
        //     for(int i = 0; i < 1024; i++) {
        // 	    if(recvBuff[i] != 48) {
        // 	        printf("%d", recvBuff[0]);
        // 	        arret[count] = recvBuff[i];
        // 	       // printf("%d", arret[count]);
        // 	        count++;
        // 	    }
        // 	}