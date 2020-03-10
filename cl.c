#include <stdio.h>
#include "cl_cal.h"

int main(int argc, char* argv[]){
  /*  int i;
  for(i=1;i<argc;i++){
    printf("%s\n",argv[i]);
  }  */
  int result;
  result = cal(argc,argv);
  printf("%d\n", result);
  return (0);
}
