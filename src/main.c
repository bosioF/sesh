#include <stdio.h>

#include "../include/config.h"
#include "../include/parsing.h"
#include "../include/execute.h"

int main() {
	char buf[BUF_SIZE];
	char *args[MAX_ARGS + 1];

	while (1) {
		printf("sesh> ");
		fflush(stdout);

		if (!fgets(buf, sizeof(buf), stdin)) break;

		const int err = parse(buf, args);
		if (err == 1) {
			break;
		}
		if (err == -1) {
			continue;
		}

		exec(args);
	}

	return 0;
}