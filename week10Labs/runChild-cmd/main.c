#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int runChild() 
{ 
 execlp("ls","ls","-aF"); //outputs all the file names in the current directory 
 return 0;
}

int main()
{
 if (fork() == 0)
 {
    runChild();
    exit(5); //the process never reaches 
 } else
 {
    int stat;
    wait(&stat);
    printf("Status %d \n",WEXITSTATUS(stat)); 
 }
    return 0;
}
