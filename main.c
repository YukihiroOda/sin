#include <stdio.h>
#include "sin.h"

void main(void){
  double x;
  int i;
  x = -Pi;
  for(i=0;i <= Pi*1100;i++) {
    printf("%.12f %.12f\n",x,sin(x));
    x+=0.001;
  }
  printf("0.000000000000 %.12f\n",sin(0.0));
  x = Pi;
  for(i=0;i <= Pi*1000;i++) {
    printf("%.12f %.12f\n",x,sin(x));
    x-=0.001;
  }
}
