#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "headers/prepare_data.h"

int experiment(double *radioactivity, double *time,
               double start_time, double end_time, double step,
               double betta) {
  int n = 0;
  double cur_time = 0;
  for (n = 0, cur_time = start_time;
       cur_time <= end_time && n < 100;
       ++n, cur_time += step) {
    time[n] = cur_time;
  }
  for (int i = 0; i < 100; ++i) {
    radioactivity[i] = fdecay(time[i], betta);
  }

  return n;
}

void add_noise(double *radioactivity, int n) {
  srand((unsigned int)time(NULL));

  for (int i = 0; i < n; ++i) {
    radioactivity[i] += ((double) rand() / RAND_MAX * 2 - 1) * 0.00;
  }

  return;
}

double fdecay(double t, double betta) {
  return exp(-t / betta);
}
