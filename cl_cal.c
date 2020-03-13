#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "cl_cal.h"


long
cal(int argc, char *argv[], int *error)
{
	int i;
	int id;
	char *ep;
	long result;
	long *stack_cal;

	id = 0;
	*error = 0;

	stack_cal = malloc(sizeof(*stack_cal) * argc);
	if (stack_cal == NULL) {
		*error = 1;
		return (0);
	}
	memset(stack_cal, 0, sizeof(*stack_cal) * argc);

	for (i = 1; i < argc; i++) {
		result = strtol(argv[i], &ep, 10);
		if (ep != NULL && *ep == '\0') {
			printf("(%d) Push %ld\n", id, result);
			stack_cal[id++] = result;
			continue;
		}

		if (id < 2) {
			*error = 1;
			break;
		}

		if (strlen(argv[i]) != 1) {
			*error = 1;
			break;
		}
		if (argv[i][0] == '+') {
			result = stack_cal[id - 2] + stack_cal[id - 1];
#ifdef DEBUG
			printf("(%ld + %ld) -> %ld\n",
			    stack_cal[id - 2], stack_cal[id - 1], result);
#endif
		} else if (argv[i][0] == '-') {
			result = stack_cal[id - 2] - stack_cal[id - 1];
#ifdef DEBUG
			printf("(%ld + %ld) -> %ld\n",
			    stack_cal[id - 2], stack_cal[id - 1], result);
#endif
		} else if (argv[i][0] == 'x') {
			result = stack_cal[id - 2] * stack_cal[id - 1];
#ifdef DEBUG
			printf("(%ld + %ld) -> %ld\n",
			    stack_cal[id - 2], stack_cal[id - 1], result);
#endif
		} else if (argv[i][0] == '/') {
			if (stack_cal[id - 1] == 0) {
				*error = 1;
				break;
			} else {
				result = stack_cal[id - 2] / stack_cal[id - 1];
#ifdef DEBUG
			printf("(%ld + %ld) -> %ld\n",
			    stack_cal[id - 2], stack_cal[id - 1], result);
#endif
			}
		} else {
			*error = 1;
			break;
		}
		stack_cal[id - 2] = result;
		id = id - 1;

	}
	free(stack_cal);
	if (id != 1){
		*error = 1;
	}	   
	return (result);
}
