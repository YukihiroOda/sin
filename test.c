#include <stdio.h>
#include <float.h>
#include "sin.h"


int test1(double x){
    if ( !(sin( Pi - x ) - sin(x) <= DBL_EPSILON ) ) return 1;
    else if ( !(sin( x + 2*Pi ) - sin(x) <= DBL_EPSILON ) ) return 2;
    else return 0;
}

int test2(double x, double y){
  if ( !(sin( x + y ) - (sin(x)*sin(Pi/2 - y) + sin(Pi/2 - x)*sin(y)) <= DBL_EPSILON) ) return 3;
    else return 0;
}

int main(void){
  int i, j;
  double x, y;
  x = -Pi/2;
  for(i = 0 ; i < 40000  ; i++ ) {
    if( test1(x) ) {
      printf("error:%d x=%lf\n",test1(x),x);
      if(test1(x)==1) printf("sin(Pi-x) = %lf sin(x) = %lf \n",sin(Pi-x),sin(x));
      else if(test1(x)==2) printf("sin(x+2*Pi) = %lf sin(x) = %lf \n",sin(x+2*Pi),sin(x));
      return 0;
    }
    for(j = 0 ; j < 40000  ; j++ ) {
      y = -Pi/2;
      if( test2(x,y) ) {
	printf("error:%d x = %lf y = %lf\n",test2(x,y),x,y);
	printf(" sin(x+y) = %lf sin(x) = %lf  sin(Pi/2-y) = %lf sin(Pi/2-x) = %lf sin(y) = %lf\n",sin(x+y),sin(x),sin(Pi/2-y),sin(Pi/2-x), sin(y));
	return 0;
      }
      y += 0.0001;
    }
    x += 0.0001;
  }
  printf("This sin function is well-defined.\n"); 
  return 0;
}
