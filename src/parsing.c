#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../include/parsing.h"
#include "../include/config.h"
#include "../include/helpers.h"

int idx = 0;
int parse(char buf[], char *args[]) {
	buf[strcspn(buf, "\n")] = '\0';

	if (!strcmp(buf, "exit")) return 1;
	if (!strcmp(buf, "envr")) {
		if (idx>0) print_envr_vars(idx); else printf("No environment variables set.\n");
		return -1;
	}

	if (strchr(buf, '=') != NULL && strchr(buf, ' ') == NULL) {
		char *eq = strchr(buf, '=');
		*eq = '\0';

		add_envr_var(buf, eq, idx);

		idx++;
		return -1;
	}

	int argc = 0;
	args[0] = strtok(buf, " ");
	while (args[argc] && argc < MAX_ARGS) {
		args[++argc] = strtok(NULL, " ");
	}
	args[argc] = NULL;

	if (!args[0]) return -1;

	return 0;
}