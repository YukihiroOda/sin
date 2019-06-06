#include <stdio.h>
#include "sin.h"

double sin(double x) {
  double sum, sgn, coefficient, xx, count, var;
  xx = x*x; var = x;
  sum = x; sgn = 1.0; coefficient = 1.0;
  for(count = 1.0 ; count < 100.0; count += 1.00) {
    sgn *= ( -1.0 );
    coefficient *= 1 / ( (2.0 * count) * (2.0 * count + 1.0) );
    var *= xx;
    sum += (sgn * coefficient * var);
  }
  return sum;
}
