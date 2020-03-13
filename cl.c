/*
calculator program
 */
#include <stdio.h>
#include "cl_cal.h"

int main(int argc, char* argv[]){
  /*  int i;
  for(i=1;i<argc;i++){
    printf("%s\n",argv[i]);
  }  */
  int result,*error;
  result = cal(argc,argv,error);
  if(*error==0){
  printf("%d\n", result);
  } else if(*error==1){
    printf("ERROR\n");
  }
  return (0);
}
