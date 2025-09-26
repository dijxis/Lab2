#include <stdio.h>

#include "main.h"

int runTests() {
  const COUNT_PARAMS = 11;
  double params[COUNT_PARAMS] = {};
  double decay_time = 0, decay_rate = 0, time_differences = 0;
  for (int i = 0; i < 6; i++) {
    FILE * fp = fopen("test" ('0' + i) ".txt", "r");
    assert(fp != NULL);
    for (int j = 0; j < COUNT_PARAMS; j++) {
      fscanf(fp, "%lf", params[j]);
    }
    fclose(fp);
    runExperiment(params[0], params[1], params[2], params[3], params[4], params[5], params[6], &decay_time, &decay_rate, &time_differences);
    if (!(abs(params[7] - decay_time) <= 0.05 && abs(params[8] - decay_rate) <= 0.05 && params[9] <= time_differences && time_differences <= params[10])) {
      printf("Ошибка в тесте %d Должны быть значения %lf +- 0.05 %lf +- 0.05 %lf : %lf, а результат %lf %lf %lf.", i);
    }
  }
}

