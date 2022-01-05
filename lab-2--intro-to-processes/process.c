#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_COUNT 2

void main(int argc, char *argv[]){

  int pid[MAX_COUNT];
  int status;
  int i;
  int j;
  int k;
  time_t t;

  for (i=0; i<MAX_COUNT; i++){
    pid[MAX_COUNT] = fork();

    switch(pid[MAX_COUNT]){
      case 0:
        srand((unsigned) time(&t));
        for (k=0; k<rand()%30; k++){
          printf("Child %d is awake, Parent: %d\n", getpid(), getpid());
        }
        exit(0);
        break;
      
      case -1:
        break;

      default:
        break;
    }
  }

  for (j=0; j<MAX_COUNT; j++){
    wait(&status);
    printf("Child has completed...\n");
  }

  printf("Parent Terminating. Child Status: %d\n", status);
}

