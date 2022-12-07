#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void error(char *msg) {
	fprintf(stderr, "%s:%s\n", msg, strerror(errno));
	exit(1);
}

int main(int argc, char *argv[]) {
	char *my_env[] = {"USER=ECS501U", NULL};
	if (execle("changeUser", "changeUser", NULL, my_env) == -1) {
		error("Cannot run changeUser.c");
	}
}















