#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "../include/config.h"
#include "../include/types.h"

int main() {
	char buf[BUF_SIZE];
	char *args[MAX_ARGS + 1];
	// ReSharper disable once CppTooWideScope (ignore this comment)
	struct ENVR_VARS e_vars[MAX_ENVR_VARS];
	int idx = 0;

	while (1) {
		printf("sesh> ");
		fflush(stdout);

		if (!fgets(buf, sizeof(buf), stdin)) break;

		buf[strcspn(buf, "\n")] = '\0';

		if (!strcmp(buf, "exit")) break;

		if (strchr(buf, '=') != NULL && strchr(buf, ' ') == NULL) {
			char *eq = strchr(buf, '=');
			*eq = '\0';

			strncpy(e_vars[idx].name, buf, MAX_ENVR_VARS_NAME - 1);
			strncpy(e_vars[idx].value, eq + 1, MAX_ENVR_VARS_VALUE - 1);

			idx++;
			continue;
		}

		int argc = 0;
		args[0] = strtok(buf, " ");
		while (args[argc] && argc < MAX_ARGS) {
			args[++argc] = strtok(NULL, " ");
		}
		args[argc] = NULL;

		if (!args[0]) continue;

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

	return 0;
}