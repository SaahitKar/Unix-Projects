#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define LINESIZE 16

//use one command line argument
int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s <textstring>\n", argv[0]);
		return -1;
	}
	
// int main() {
//     char input[] = "Funny!";

	//create a file so that 16 rows of empty will appear with od -c command
	int fd = open("diagonal.out", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	char space = ' ';
	for(int line=0; line<LINESIZE; line++)
		for(int column=0; column<LINESIZE; column++)
			write(fd, &space, 1);

	//Each line of od outputs 16 characters 
	//So, to make the output diagonal, we will use 0, 17, 34, ....
	
	for(int j = 0; j < argc; j++) {
	    int n = strlen(argv[j]);
	    for(int i=0; i<n; i++) {
    		lseek(fd, (LINESIZE+1)*i, SEEK_SET);
    		write(fd, &argv[j][i], 1);
	    }
	    //SEEK_SET = SEEK_SET + 400;
	}
	close(fd);
	puts("diagonal.out has been created. Use od -c diagonal.out to see the contents.");
}

