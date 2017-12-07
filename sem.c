#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#define KEY 91800

int main(int argc, char* argv[]) {
  //printf("%d", argc);
  int sem_test;
  if (argc == 3) {
    if (!strcmp(argv[1], "-c")) {
      sem_test = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0600);
      if (!(sem_test == -1)) {
	printf("semaphore created\n");
	semctl(sem_test, 0, SETVAL, atoi(argv[2]));//saw someone use atoi in class on wednesday and adopted it into my code, hope thats alright :)
	printf("value set to %d\n", atoi(argv[2]));
      }
      else {
	printf("semaphore already exists\n");
      }
    }
  }
  else if(argc == 2) {
    if (!strcmp(argv[1], "-v")) {
      //code for viewing current state
      sem_test = semget(KEY, 1, 0600);
      printf("Value of semaphore: %d\n", semctl( sem_test, 0,GETVAL));
    }
    else if(!strcmp(argv[1], "-r")) {
      //code for removing semaphore
      sem_test = semget(KEY, 1, 0600);
      printf("Removing Semaphore: %d\n", semctl(sem_test, 0, IPC_RMID));
    }
  }
  else printf("INVALID INPUT");
  return 0;
}
