#include <stdio.h>
#include "sin.h"

double epsilon = 1.0e-12;

int testpi(double x){
  double check;
  check = sin( Pi - x ) - sin(x);
  if(check < 0) check = -check; //absolute
  if ( !(check <= epsilon) ) return 1;
  else return 0;
}

int test2pi(double x){
  double check;
  check = sin( x + 2*Pi ) - sin(x);
  if(check < 0) check = -check; //absolute
  if ( !( check <= epsilon ) ) return 1;
  else return 0;
}

double cos(double x){
  return sin(Pi/2 - x);
}

int testAddThm1(double x, double y){
  double check;
  check = sin( x + y ) - (sin(x)*cos(y) + cos(x)*sin(y));
  if(check < 0) check = -check; //absolute
  if ( !(check <= epsilon) ) return 1;
    else return 0;
}

int testAddThm2(double x, double y){
  double check;
  check = cos( x + y ) - (cos(x)*cos(y) - sin(x)*sin(y));
  if(check < 0) check = -check; //absolute
  if ( !(check <= epsilon) ) return 1;
  else return 0;
}

int main(void){
  int i, j;
  double x, y;
  x = -Pi;
  for(i = 0 ; i < 4000  ; i++ ) {
    if( testpi(x) ) {
      printf("failed:testpi x=%.32f\n",x);
      printf("sin(Pi-x) = %.32f , sin(x) = %.32f ,  sin(Pi-x)-sin(x) = %.32f \n",sin(Pi-x),sin(x), sin(Pi-x)-sin(x));
    }
    if( test2pi(x)){
      printf("failed:test2pi x=%.32f\n",x);
      printf("sin(x+2*Pi) = %.32f , sin(x) = %.32f , sin(x+2*Pi)-sin(x) = %.32f \n",sin(x+2*Pi),sin(x),sin(x+2*Pi) - sin(x));
    }
    for(j = 0 ; j < 4000  ; j++ ) {
      y = -Pi/2;
      if( testAddThm1(x,y) ) {
	printf("failed:testAddThm1 x = %.32f y = %.32f\n",x,y);
	printf(" sin(x+y) = %.32f , sin(x) = %.32f , cos(y) = %.32f , cos(x) = %.32f , sin(y) = %.32f , sin( x + y ) - (sin(x)*cos(y) + cos(x)*sin(y)) = %.32f\n ",sin(x+y),sin(x),cos(y),cos(x), sin(y),sin( x + y ) - (sin(x)*cos(y) + cos(x)*sin(y)));
      }
      if( testAddThm2(x,y) ) {
	printf("failed:testAddThm2 x = %.32f y = %.32f\n",x,y);
	printf(" cos(x+y) = %.32f , cos(x) = %.32f , cos(y) = %.32f , sin(x) = %.32f , sin(y) = %.32f , cos(x + y) - (cos(x)*cos(y) - sin(x)*sin(y)) = %.32f\n ",cos(x+y),cos(x),cos(y),sin(x), sin(y),cos( x + y ) - (cos(x)*cos(y) - sin(x)*sin(y)));
      }
      y += 0.001;
    }
    x += 0.001;
  }
  printf("This sin function may be well-defined.\n");
  return 0;
}
