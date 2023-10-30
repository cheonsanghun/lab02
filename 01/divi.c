#include <stdio.h>

int divi(int a, int b){
  if (b != 0)  {
    int result = a/b;
    return result;
  }
  else 
     printf("계산 불가");
}
