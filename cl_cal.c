#include <stdio.h>
#include "cl_cal.h"

int cal(int argc, char* argv[]){
  int i;
  for(i=1; i < argc; i++){
    printf("%s\n" ,argv[i]);
  }
  return (0);
}
