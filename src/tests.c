#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "headers/main.h"
#include "headers/tests.h"

int runTests() {
  const int COUNT_PARAMS = 11;

  double params[COUNT_PARAMS] = {};
  double decay_time = 0, decay_rate = 0, time_differences = 0;
  int err_flag = 0;
  char *tests[6] = {"./tests/test0.txt", "./tests/test1.txt", "./tests/test2.txt",
                    "./tests/test3.txt", "./tests/test4.txt", "./tests/test5.txt",};

  for (int i = 0, j = '0'; i < 6; i++, j++) {
    char id = '0' + i;
    FILE * fp = fopen(tests[i], "r");
    assert(fp != NULL);
    for (int k = 0; k < COUNT_PARAMS; k++) {
      fscanf(fp, "%lf", &params[k]);
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
              "Ошибка в тесте %d Должны быть значения %lf +- 0.05 %lf +- 0.05 %lf : %lf, а результат %lf %lf %lf.\n",
              i, params[7], params[8], params[9], params[10], decay_time, decay_rate, time_differences);
      err_flag = 1;
    }
  }
  return err_flag;
}

