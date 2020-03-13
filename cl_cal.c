#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cl_cal.h"

int cal(int argc, char* argv[], int* error){
  int i;
  int id= -1, status, result;
  int* stack_cal;
  stack_cal = (int*)malloc(sizeof(int)*(argc/2));
  *error = 0;
  for(i=1; i<argc; i++){
    if(id <1 && (argv[i][0]=='+' || argv[i][0]=='-' || argv[i][0]=='x' || argv[i][0]=='/')){
      *error = 1;
      break;
    } else if(argv[i][0]=='+'){
      result = stack_cal[id-1] + stack_cal[id];
      stack_cal[--id] = result;
    } else if(argv[i][0]=='-'){
      result = stack_cal[id-1] - stack_cal[id];
      stack_cal[--id] = result;
    } else if(argv[i][0]=='x'){
      result = stack_cal[id-1] * stack_cal[id];
      stack_cal[--id] = result;
    } else if(argv[i][0]=='/'){
	if(stack_cal[id]==0){
	  *error = 1;
	  break;
	} else {
	  result = stack_cal[id-1] / stack_cal[id];
	  stack_cal[--id] = result;
	}
    } else {
	stack_cal[++id] = atoi(argv[i]);
    }
  }
  free(stack_cal);
  return result;
}
