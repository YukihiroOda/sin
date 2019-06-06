#include <stdio.h>
#include "sin.h"

void main(void){
  double x, output;
  scanf("%lf",&x);
  output = sin(x);
  printf("%lf\n",output);
}
