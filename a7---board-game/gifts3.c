#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//let us assume that there will not be more than 100 players
#define MAXPLAYERS 100
//let us assume that max length for any name is 100 characters
#define MAXLEN 100

struct Player {
	char name[MAXLEN];
	double balance;
};

//struct is like class - we can use an array of struct (we can use like an array of objects).
struct Player players[MAXPLAYERS];
int numPlayers = 0; //set when actual player data is loaded

//search the player names array and return the index if specified name is found
//return -1 otherwise.
int findIndex(char *name) {
        for(int i=0; i<numPlayers; i++)
            if(strcmp(name, players[i].name) == 0)
              return i;

        return -1;
}

void updateBal(char** argv, int argc) {
    FILE *fd = fopen("gifts3.dat", "r");
	int play = 0;
	int length = 0;
	struct Player plays;
	while(fread(&plays, sizeof(struct Player), 1, fd)) {
	    players[play] = plays;
	    play++;
	}
	printf("%d", play);
	fclose(fd);
	numPlayers=play;
	int giver = findIndex(argv[1]);
	double amountGive = atof(argv[2]);
	players[giver].balance = players[giver].balance - amountGive;
	//balances[giver] = balances[giver] - amountGive;
    double divided = amountGive / (argc-3);
	for(int i = 3; i < argc; i++) {
	    int mathDex = findIndex(argv[i]);
	    players[mathDex].balance = players[mathDex].balance + divided;
// 		int mathDex = findIndex(argv[i]);
// 		printf("%d: %s", mathDex, names[mathDex]);
// 		balances[mathDex] = balances[mathDex] + divided;
	}
	//printf("# of Players: %d\n", numPlayers);
}

void calcBalance(int index, char** argv, int argc) {
	if(strcmp(argv[1],"new") == 0) {
		int temp = 0;
		for(int i = 2; i < argc; i += 2) {
            struct Player play;
			strcpy(play.name, argv[i]);
			play.balance = atof(argv[i+1]);
			players[temp] = play;
			temp++;
			//printf("%s", play.name);
		}
		numPlayers=temp;	
	}
}

// use binary data file gifts2.dat to read and store the results.

int main(int argc, char *argv[]) {
	int index = 0;
	int fullLength = argc;
	char**command = argv;
	if(strcmp(argv[1],"new") == 0) {
        calcBalance(index, command, fullLength);
	} else {
	    updateBal(command, fullLength);
	}
	FILE *filep = fopen("gifts3.dat", "wb");
	int n = 5; //let us assume players
	fwrite(players, sizeof(struct Player), numPlayers, filep);
	for(int i = 0; i < numPlayers; i++) {
	    printf("%10s: %5.2lf\n",players[i].name, players[i].balance);
	}
	fclose(filep);
}
