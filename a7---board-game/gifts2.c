// #include <fcntl.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// //let us assume that there will not be more than 100 players
// #define MAXPLAYERS 100
// //let us assume that max length for any name is 100 characters
// #define MAXLEN 100

// //arrays to store the player names and balances
// char names[MAXPLAYERS][MAXLEN];
// double balances[MAXPLAYERS];
// int numPlayers = 0; //set when actual player data is loaded

// //search the player names array and return the index if specified name is found
// //return -1 otherwise.
// int findIndex(char *name) {
//         for(int i=0; i<numPlayers; i++)
//             if(strcmp(name, names[i]) == 0)
//               return i;

//         return -1;
// }

// void updateBal(char** argv, int argc) {
//     fd =  open("gifts2.dat", O_CREAT | O_RDONLY);
// 	int play = 0;
// 	read(fd, &play, sizeof(int));
// 	numPlayers = play;
// 	int length = 0;
// 	for(int i = 0; i < numPlayers; i++) {
// 		read(fd, &length, sizeof(int));
// 		read(fd, names[i], length);
// 		read(fd, &balances[i], sizeof(double));
// 		printf("%lf", balances[i]);
// 	}
// 	printf("%d", play);
// 	close(fd);
// 	//printf("%d", index);
// 	numPlayers=index;
// 	int giver = findIndex(argv[1]);
// 	double amountGive = atof(argv[2]);
// 	balances[giver] = balances[giver] - amountGive;
// 	//printf("%lf", balances[giver]);
//     double divided = amountGive / (argc-3);
// 	for(int i = 3; i < argc; i++) {
// 		int mathDex = findIndex(argv[i]);
// 		printf("%d: %s", mathDex, names[mathDex]);
// 		balances[mathDex] = balances[mathDex] + divided;
// 	}
// 	//printf("# of Players: %d\n", numPlayers);
// }

// void calcBalance(int index, char** argv, int argc) {
// 	printf("%s: %s\n", argv[0], argv[1]);
// 	if(strcmp(argv[1],"new") == 0) {
// 		int temp = 0;
// 		//printf("%s: %s\n", argv[0], argv[1]);
// 		for(int i = 2; i < argc; i += 2) {
// 			//printf("%s: %s\n", argv[i], argv[i+1]);
// 			strcpy(names[temp], argv[i]);
// 			balances[temp] = atof(argv[i+1]);
// 			temp++;
// 		}
// 		numPlayers=temp;	
// 	}
// }

// // use binary data file gifts2.dat to read and store the results.

// int main(int argc, char *argv[]) {
// 	//code here!
// int index = 0;
// 	int fullLength = argc;
//      //char* letts[] = argv;
// 	  char**command = argv;
//       //for(int i = 1; i < argc; ++i)
//       //{
//         // command[i-1] = malloc(strlen(argv[i])+1);
//       // strcpy(command[i-1], argv[i]);
//         //printf("%s ,", command[i-1]);
//      //}
     
//      if(strcmp(argv[1],"new") == 0) {
//         calcBalance(index, command, fullLength);
// 	} else {
// 	    updateBal(command, fullLength);
// 	}
//     //calcBalance(index, command, fullLength);
// 	int fd = open("gifts2.dat", O_CREAT | O_WRONLY);
// 	//write(fd, &names, sizeof(float));
// 	//write(fd, balances, sizeof(double));
// 	write(fd, &numPlayers, sizeof(int));
// 	for(int i = 0; i < numPlayers; i++) {
// 	//	write(fd, &numPlayers, sizeof(int));
// 		int len = strlen(names[i]);
// 		write(fd, &len, sizeof(int));
// 		write(fd, names[i], strlen(names[i]));
// 		write(fd, &balances[i], sizeof(double));
// 		printf("%s: %lf\n",names[i], balances[i]);
// 	}
// 	close(fd);
// }