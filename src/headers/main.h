#ifndef MAIN_H
#define MAIN_H

int checkArg(char *arg, int argc, char **argv);

int getInput(double *const start_time, double *const end_time,
             double *const step, double *const precision);

int runExperiment(double start_time, double end_time,
                  double step, double precision,
                  double betta, double interval1, double interval2,
                  double *const decay_time, double *const decay_rate,
                  double *const time_differences);

#endif // MAIN_H

