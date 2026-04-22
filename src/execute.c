#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../include/execute.h"

void exec(char *args[]) {
	const pid_t pid = fork();
	if (pid == 0) {
		execvp(args[0], args);
		perror("execvp");
		exit(1);
	} else if (pid > 0) {
		waitpid(pid, NULL, 0);
	} else {
		perror("fork");
	}
}
