#ifndef TYPES_H
#define TYPES_H

#include "config.h"

struct ENVR_VARS {
	char name[MAX_ENVR_VARS_NAME];
	char value[MAX_ENVR_VARS_VALUE];
};

#endif