#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#define KEY 12

int main() {
  while(1) {
    if (fork() == 0) {
      char * in;
      //gets a seg fault for some reason sort that out
      fgets (in, 5, stdin);
      printf("success");
      printf ("%s", in);
      
      if (!(strcmp(in[1], "c"))) {
	  int n = 3;
	  char * val;
	  while (in[n]) {
	    val += in[n];
	    n++;
	  }
	  semget(KEY, (int) val, IPC_CREAT | IPC_EXCL);
	  
	    
      }
      if (!(strcmp(in[1], "v"))) {
	
    }
    
  }
}
