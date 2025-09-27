#include <math.h>

#include "headers/accuracy_analysis_data.h"
#include "headers/analysis_data.h"

double precision_analysis(double *radioactivity, double *time, int n,
                          double precision, double interval1,  double interval2) {
  double time_differences = time[n - 1] - time[0];

  for (int m = 10; m <= n; ++m) {
      double decay_time = nonlinear_equation(radioactivity, time, m, precision, interval1, interval2);
      double decay_rate = linear_equation(radioactivity, time, m);

      double deviation1 = dev_exp(radioactivity, time, m, decay_time);
      double deviation2 = dev_linear(radioactivity, time, m, decay_rate);

      if (deviation2 > 2.0 * deviation1) {
          time_differences = time[m - 1] - time[0];
          break;
      }
  }

  return time_differences;
}

double dev_exp(double *radioactivity, double *time, int m, double decay_time) {
    double sum_residuals1 = 0;
    for (int i = 0; i < m; i++) {
        sum_residuals1 += pow((radioactivity[i] - exp(-time[i] / decay_time)), 2);
    }
    return sqrt(sum_residuals1) / m;
}

double dev_linear(double *radioactivity, double *time, int m, double decay_rate) {
    double sum_residuals2 = 0;
    for (int i = 0; i < m; i++) {
        sum_residuals2 += pow((radioactivity[i] - (1 - time[i] / decay_rate)), 2);
    }
    return sqrt(sum_residuals2) / m;
}
