#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "headers/main.h"
#include "headers/tests.h"

int runTests() {
  enum { COUNT_PARAMS = 11, AMOUNT_OF_FILES = 7 };
  const double COMP_PRECISION = 0.05, EPS = 1e-5;

  double params[COUNT_PARAMS] = {};
  double decay_time = 0, decay_rate = 0, time_differences = 0;
  int err_flag = 0;
  char *tests[AMOUNT_OF_FILES] = {"./tests/test0.txt", "./tests/test1.txt", "./tests/test2.txt",
                    "./tests/test3.txt", "./tests/test4.txt", "./tests/test5.txt", "./tests/test6.txt"};

  for (int i = 0, j = '0'; i < AMOUNT_OF_FILES; i++, j++) {
    FILE *fp = fopen(tests[i], "r");
    assert(fp != NULL);

    for (int k = 0; k < COUNT_PARAMS; k++) {
      fscanf(fp, "%lf", &params[k]);
    }
    fclose(fp);
    runExperiment(params[0], params[1], params[2],
                  params[3], params[4], params[5],
                  params[6], &decay_time,
                  &decay_rate, &time_differences);
    if (fabs(decay_time - params[7]) > COMP_PRECISION ||
        fabs(decay_rate - params[8]) > COMP_PRECISION ||
        time_differences - params[9] < -EPS ||
        time_differences - params[10] > EPS) {
      fprintf(stderr,
              "Error in test [%d] \n\tExpected: %-9lf %-9lf %lg : %lg \n\tResults : %-9lf %-9lf    %-9lg\n",
              i, params[7], params[8], params[9], params[10], decay_time, decay_rate, time_differences);
      err_flag = 1;
    }
  }
  return err_flag;
}

