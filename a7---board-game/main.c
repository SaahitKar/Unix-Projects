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
// 	//char tempName[100];
// 		//double tempBalance = 0;
// 		////int mathIndex = findIndex(argv[1]);
// 		//printf("%s %d", argv[1], numPlayers);
// 		//for(int i = 0; i < index; i++) {
// 		//	fscanf(filep, "%s %f",tempName,tempBalance);
// 		//	if(strcmp(argv[1],tempName)) {
// 		//		break;
// 		//	}
// 		//}
// 		//fscanf(filep, "%s %f",tempName,tempBalance);
// 		////printf("%d %s %lf",mathIndex, names[mathIndex], balances[mathIndex]);

//  int findIndex(char *name) {
//         for(int i=0; i<numPlayers; i++) {
// //			printf("FullName: %s\n", names[i]);
//         	if(strcmp(name, names[i]) == 0) {
// 				return i;
// 			}
// 		}
// 		return -1;
// }

// void updateBal(char** argv, int argc) {
//     FILE *filep = fopen("gifts1.txt", "r");
// 	char buf[1000];
// 	double f1 = 0;
// 	int index = 0;
//   	while(fscanf(filep, "%s %lf",buf,&f1) > 0) {
// 	//while(fscanf(filep, "%s",buf) > 0) {  
// 	//  	printf("%lf", f1);
// 	//	printf("%s", buf);
// //		names[index] = buf;
// 		strcpy(names[index], buf);
// 		balances[index] = f1;
// 		index++;
// 	}
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
// 	if(strcmp(argv[1],"new") == 0) {
// 		int temp = 0;
// 		for(int i = 2; i < argc; i += 2) {
// 			strcpy(names[temp], argv[i]);
// 			balances[temp] = atof(argv[i+1]);
// 			temp++;
// 		}
// 		numPlayers=temp;	
// 	}
// }

// int main(int argc, char **argv) {
// 	//if (argc < 2) {
// 		//printf("Usage: diskblocks <file size in KBs>\n");
// 		//return -1;
// 	//}
// 	int index = 0;
// 	int fullLength = argc;
//      //char* letts[] = argv;
// 	char**command = argv;
// 	if(strcmp(argv[1],"new") == 0) {
//         calcBalance(index, command, fullLength);
// 	} else {
// 	    updateBal(command, fullLength);
// 	}
	  
// 	FILE *filep = fopen("gifts1.txt", "w+");
// 	int n = 5; //let us assume players

// 	int length = sizeof(balances) / sizeof(double);
// 	for(int i = 0; i < numPlayers; i++) {
//   		printf("%10s: %5.2lf\n", names[i], balances[i]);
// 		fprintf(filep,"%s %lf\n", names[i], balances[i]);
// 	}
//     fclose(filep);
// }
