#include <stdio.h>
#include <math.h>

#include "headers/analyses_data.h"

double nonlinear_equation (double *radioactivity, double *time, int n, double precision) {
  double interval1 = 0, interval2 = 0;
  scanf("%lf%lf", &interval1, &interval2);

  double middle = (interval1 + interval2) / 2;
  while (interval2 - interval1 >= precision) {
    if (model(radioactivity, time, n, middle) == 0) {
      return middle;
    }
    else if (model(radioactivity, time, n, interval1) * model(radioactivity, time, n, middle) < 0) {
      interval2 = middle;
      middle = (interval1 + interval2) / 2;
    }
    else {
      interval1 = middle;
      middle = (interval1 + interval2) / 2;
    }
  }
  return middle;
}

double model(double *radioactivity, double *time, int n, double point) {
  double res = 0;
  for (size_t i = 0; i < n; i++) {
    res += time[i] * exp(-time[i] / point) * (radioactivity[i] - exp(-time[i] / point));
  }
  return res;
}
