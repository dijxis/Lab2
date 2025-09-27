#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "headers/main.h"
#include "headers/tests.h"
#include "headers/prepare_data.h"
#include "headers/analysis_data.h"
#include "headers/accuracy_analysis_data.h"

int main(int argc, char **argv) {
  double start_time = 0., end_time = 0., step = 0., precision = 0.;
  double betta = 0., interval1 = 0., interval2 = 0.;
  double decay_time = 0., decay_rate = 0., time_differences = 0.;

  if (! checkArg("--test", argc, argv)) {
    getInput(&start_time, &end_time, &step, &precision,
             &betta, &interval1, &interval2);
    runExperiment(start_time, end_time, step, precision,
                  betta, interval1, interval2,
                  &decay_time, &decay_rate, &time_differences);
    printf("decay_time: %lg\n", decay_time);
    printf("decay_rate: %lg\n", decay_rate);
    printf("time_differences: %lg\n", time_differences);
  }
  else {
    runTests();
  }

  return 0;
}

int checkArg(char *arg, int argc, char **argv) {
  for (int i = 0; i < argc; ++i) {
    if (! strcmp(arg, argv[i]))
      return 1;
  }
  return 0;
}

int getInput(double *const start_time, double *const end_time,
             double *const step, double *const precision,
             double *const betta, double *const interval1,
             double *const interval2) {
  assert(start_time);
  assert(end_time);
  assert(step);
  assert(precision);
  assert(betta);
  assert(interval1);
  assert(interval2);

  printf("Enter start_time: ");
  scanf("%lg", start_time);
  printf("Enter end_time: ");
  scanf("%lg", end_time);
  printf("Enter step: ");
  scanf("%lg", step);
  printf("Enter precision: ");
  scanf("%lg", precision);
  printf("Enter betta: ");
  scanf("%lg", betta);
  printf("Enter interval1: ");
  scanf("%lg", interval1);
  printf("Enter interval2: ");
  scanf("%lg", interval2);
  printf("\n");

  return 0;
}

int runExperiment(double start_time, double end_time,
                  double step, double precision,
                  double betta, double interval1, double interval2,
                  double *const decay_time, double *const decay_rate,
                  double *const time_differences) {
  double time[100] = {}, radioactivity[100] = {};
  int n = (end_time - start_time) / step + 1;

  experiment(radioactivity, time,
             start_time, end_time, step, betta);

  add_noise(radioactivity, n);

  *decay_time = nonlinear_equation(radioactivity, time, n, precision, interval1, interval2);

  *decay_rate = linear_equation(radioactivity, time, n);

  *time_differences = precision_analysis(radioactivity, time, n, precision, interval1, interval2);

  return 0;
}
