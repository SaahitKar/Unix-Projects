#include <stdio.h>     
#include <stdlib.h>   
#include <stdint.h>  
#include <inttypes.h>  
#include <errno.h>     // for EINTR
#include <fcntl.h>     
#include <unistd.h>    
#include <sys/types.h>
#include <pthread.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>

// Print out the usage of the program and exit.
// block size
#define BLOCK_SIZE 4096
int numThreads;
uint32_t n,m, blocksPerThread;
FILE *fp;
char *buffer;

uint64_t fileSize;

uint32_t places(uint32_t num) {
    uint32_t counter = 0;
    
    while(num > 0) {
        counter += 1;
        num /= 10;
    }
    return counter;
}

uint32_t jenkins_one_at_a_time_hash(const uint8_t* key, uint64_t length) 
{
  uint64_t i = 0;
  uint32_t hash = 0;

  while (i != length) {
    hash += key[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  return hash;
}


void usage(char* s) 
{
  fprintf(stderr, "Usage: %s filename num_threads \n", s);
  exit(EXIT_FAILURE);
}

void *hash(void *ptr) {
    int i = (int) ptr;
    
    int left = 2*i+1;
    int right = left+1;
    pthread_t thread1, thread2;
    if(left < m) {
        if(pthread_create(&thread1, NULL, hash, (void *) left) != 0) {
            printf("thread can't be created");
        }
    }
    if(right < m) {
        if(pthread_create(&thread2, NULL, hash, (void *) right) != 0) {
            printf("thread can't be created");
        }
    }
    size_t bytesPerThread = blocksPerThread*BLOCK_SIZE;
    uint8_t *key = malloc(bytesPerThread);
    
    fseek(fp, i * bytesPerThread, SEEK_SET);
    fread(key, 1, bytesPerThread, fp);
    uint32_t h = jenkins_one_at_a_time_hash(key, bytesPerThread);
    char *H = malloc(places(h) + 1);
    sprintf(H, "%zu", h);
    
    if(left >= m && right >= m) {
        return (void *) h;
    }
    uint32_t *lh, rh;
    char *leftH = "";
    char *rightH ="";
    if (left < m) {
        pthread_join(thread1, &lh);
        // printf("thread %d %zu", left, (uint32_t) lh);
        leftH = malloc(places((uint32_t) lh) + 1);
        sprintf(leftH, "%zu", (uint32_t) lh);
    }
    int temp = 0;
    for(int i = 0; i < numThreads; i++) {
        temp++;
    }
    
    if (right < m) {
        pthread_join(thread2, &rh);
        // printf("thread %d %zu", right, (uint32_t) rh);
        rightH = malloc(places((uint32_t) rh) + 1);
        sprintf(rightH, "%zu", (uint32_t) rh);
    }
    
    char *conc = malloc(strlen(H) + strlen(leftH) + strlen(rightH) + 1);
    strcpy(conc, H);
    strcat(conc, leftH);
    strcat(conc, rightH);
    
    h = jenkins_one_at_a_time_hash(conc, strlen(conc));
    return (void *) h;
}

int main(int argc, char** argv) 
{
  pthread_t thread1, thread2;
  uint32_t nblocks;
  numThreads = atoi(argv[2]); 
  
  // input checking 
  if (argc != 3)
    usage(argv[0]);

  // open input file
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("open failed");
    exit(1);
  }
  
  struct stat st;
  int fd = fileno(fp);
  fstat(fd, &st);
  size_t size = st.st_size;

  n = size/BLOCK_SIZE;
  m = atoi(argv[2]);
  blocksPerThread = n / m;
  printf("\nnumThreads: %d\nBlocksPerThread: %d \n", m, blocksPerThread);
  pthread_t thr;
  pthread_create (&thr, NULL, hash, (void *) 0);
  
  uint32_t *h;
  pthread_join(thr, &h);
  
  printf("hash value: %zu\n", (uint32_t) h);
  
  return 0;
}
