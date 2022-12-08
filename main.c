#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void runChild(void) {
	printf("I am the child! My pid is %d\n", getpid());
	sleep(5);

}

int main() {
	pid_t parent;
	int status;

	parent = fork(); 

	if (parent == 0) {  // child process
		runChild();
	} else if ((parent = wait(&status)) > 0) {  // waits for child process
		printf("I'm still here. getpid = %d. getppid = %d\n", getpid(), getppid());
	}
	
	return 0;

}


























