#include <stdio.h>
#include <math.h>

#include "headers/analysis_data.h"

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

double linear_equation(double *radioactivity, double *time, int n) {
  double sum_t_squared = 0.0;
  double sum_t_times_diff = 0.0;
  
  for (int i = 0; i < n; i++) {
      sum_t_squared += time[i] * time[i];
      sum_t_times_diff += time[i] * (1.0 - radioactivity[i]);
  }
  
  return sum_t_squared / sum_t_times_diff;
}
