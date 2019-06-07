#include <stdio.h>
#include "sin.h"

/* sin (x) = x - 1/3! x^3 + 1/5! x^5 - 1/7! x^7 + ...... */
/* a_n * var_n =  (-1) * a_{n-1}  * (1/(2n*(2n+1))) * var_{n-1} * x^2   */

double sin(double x) {
  double sum, sgn, coefficient, xx, var;
  int count;
  xx = x*x; var = x;
  sum = x; sgn = 1.0; coefficient = 1.0;
  for(count = 1 ; count < 100; count++) {
    sgn *= ( -1.0 );
    coefficient *= 1.0 / ( (2 * count) * (2 * count + 1) ); // 1/(2n+1)! = 1/(2n-1)! * 1/(2n*(2n+1))
    var *= xx;
    sum += (sgn * coefficient * var);
  }
  return sum;
}

