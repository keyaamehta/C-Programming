#include <stdio.h>
#include <unistd.h>

int runChild() 
{ 
 printf("\n I am the child! My pid is %d\n",getpid()); 
 return 0;
}

int main()
{
 if (fork() == 0)
 {
    runChild();
 } else
 {
    sleep(5);
    printf("I am still here!"); 
 }
    return 0;
}


