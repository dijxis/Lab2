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

  if (checkArg("--test", argc, argv)) {
    getInput(&start_time, &end_time, &step, &precision);
    runExperiment(start_time, end_time, step, precision,
                  betta, interval1, interval2,
                  &decay_time, &decay_rate, &time_differences);
  }
  else {
    runTests();
  }

  return 0;
}

int checkArg(char *arg, int argc, char **argv) {
  for (int i = 0; i < argc; ++i) {
    if (strcmp(arg, argv[i]))
      return 1;
  }
  return 0;
}

int getInput(double *const start_time, double *const end_time,
             double *const step, double *const precision) {
  assert(start_time);
  assert(end_time);
  assert(step);
  assert(precision);

  scanf("%lg", start_time);
  scanf("%lg", end_time);
  scanf("%lg", step);
  scanf("%lg", precision);
}

int runExperiment(double start_time, double end_time,
                  double step, double precision) {
  double time[100], radioactivity[100];
  int n = (end_time - start_time) / step + 1;

  experiment(radioactivity, time,
             start_time, end_time, step);

  add_noise(radioactivity, n);

  return 0;
}
