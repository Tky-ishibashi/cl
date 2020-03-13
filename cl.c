/*
 * calculator program
 */
#include <stdio.h>
#include "cl_cal.h"

int
main(int argc, char *argv[])
{
	long result;
	int *error;

	result = cal(argc, argv, error);
	if (*error == 0) {
		printf("%ld\n", result);
	} else if (*error == 1) {
		printf("ERROR\n");
		return (1);
	}
	return (0);
}
