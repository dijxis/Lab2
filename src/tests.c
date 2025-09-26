#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "headers/main.h"

int runTests() {
  const int COUNT_PARAMS = 11;

  double params[COUNT_PARAMS] = {};
  double decay_time = 0, decay_rate = 0, time_differences = 0;
  int err_flag = 0;

  for (int i = 0, j = '0'; i < 6; i++, j++) {
    char id = '0' + i;
    FILE * fp = fopen(strcat(strcat("../tests/test", &id), ".txt"), "r");
    assert(fp != NULL);
    for (int j = 0; j < COUNT_PARAMS; j++) {
      fscanf(fp, "%lf", &params[j]);
    }
    fclose(fp);
    runExperiment(params[0], params[1], params[2],
                  params[3], params[4], params[5],
                  params[6], &decay_time,
                  &decay_rate, &time_differences);
    if (!(fabs(params[7] - decay_time) <= 0.05 &&
        fabs(params[8] - decay_rate) <= 0.05 &&
        params[9] <= time_differences && time_differences <= params[10])) {
      fprintf(stderr,
              "Ошибка в тесте %d Должны быть значения %lf +- 0.05 %lf +- 0.05 %lf : %lf, а результат %lf %lf %lf.",
              i, params[7], params[8], params[9], params[10], decay_time, decay_rate, time_differences);
      err_flag = 1;
    }
  }
  return err_flag;
}

