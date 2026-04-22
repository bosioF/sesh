#include <stdio.h>
#include <string.h>

#include "../include/helpers.h"
#include "../include/config.h"
#include "../include/types.h"

void add_envr_var(char buf[], const char *eq, const int idx) {
	strncpy(e_vars[idx].name, buf, MAX_ENVR_VARS_NAME - 1);
	strncpy(e_vars[idx].value, eq + 1, MAX_ENVR_VARS_VALUE - 1);
}

void print_envr_vars(const int len) {
	for (int i = 0; i < len; i++) {
		const int LEN = strlen(e_vars[i].name);
		char temp[LEN + 1];
		int k = 0;

		for (int j = 0; j < LEN; j++) {
			if (e_vars[i].name[j] != '$') {
				temp[k++] = e_vars[i].name[j];
			}
		}
		temp[k] = '\0';

		strncpy(e_vars[i].name, temp, LEN + 1);
		printf("%s=%s\n", e_vars[i].name, e_vars[i].value);
	}
}