#include <stdio.h>
#include "sin.h"

double Pi = 3.14159265;

/* sin (x) = x - 1/3! x^3 + 1/5! x^5 - 1/7! x^7 + ...... */
/* a_n * var_n =  (-1) * a_{n-1}  * (1/(2n*(2n+1))) * var_{n-1} * x^2   */

double sin(double x) {
  double sum, sgn, coefficient, xx, var;
  int count;
  while ( !( (-1 * Pi) <= x && x < Pi ) ) {
    if ( Pi <= x ) x -= Pi;
    else x += Pi;
  }
  xx = x*x; var = x;
  sum = x; sgn = 1.0; coefficient = 1.0;
  for(count = 1 ; count < 100; count++) {
    sgn *= ( -1.0 );
    var *= xx;
    coefficient *= 1.0 / ( (2 * count) * (2 * count + 1) ); // 1/(2n+1)! = 1/(2n-1)! * 1/(2n*(2n+1))
    sum += (sgn * coefficient * var );
  }
  return sum;
}

