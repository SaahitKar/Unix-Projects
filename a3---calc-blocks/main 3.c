#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#define SIBLOCKS 2048L
#define DIBLOCKS (2048L*2048L)
#define TIBLOCKS (2048L*2048L*2048L)

long computeOverheadBlocks(long diskblocks) {
    if(diskblocks < 12) {
        return 0;
    } else if(diskblocks <= (SIBLOCKS+12)) {
	    return 1;
	} else if(diskblocks > (SIBLOCKS+12) && diskblocks <= (DIBLOCKS + SIBLOCKS + 12)) {
	    long tempDisk = diskblocks - 2048;
	    tempDisk = (tempDisk) / 2048;
	    int count = 3;
	   for(int i = 0; i < tempDisk; i++) {
    	    count++;
    	}
    	return count;
	} else if(diskblocks > (DIBLOCKS + SIBLOCKS + 12) && diskblocks <= (TIBLOCKS + DIBLOCKS + SIBLOCKS + 12)) {
	    long tempDisk = diskblocks - 2048;
	    tempDisk = tempDisk / 2048;
	   // printf("TEMPDISK: %ld\n", tempDisk);
	   // printf("TEMPDISK: %ld\n", tempDisk/2048);
	    int count = 4 + ((tempDisk / 2048));
	   for(int i = 0; i < tempDisk; i++) {
    	    count++;
    	}
    	return count;
	} else if(diskblocks > (TIBLOCKS + DIBLOCKS + SIBLOCKS + 12)) {
	    return -1;
	}
	return 0;
}

// int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: diskblocks <file size in KBs>\n");
		return -1;
	}
	long filesize = atol(argv[1]);
int main() {
    long filesize = 33570912;
	long diskblocks = filesize / 8;
	if (filesize % 8) 
		diskblocks++;

	printf("%ld %ld\n", diskblocks, computeOverheadBlocks(diskblocks));
}




