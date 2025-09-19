#ifndef ACCURACY_ANALYSIS_DATA_H
#define ACCURACY_ANALYSIS_DATA_H
double dev_exp(double *radioactivity, double *time,
               int M, double decay_time);

double dev_linear(double *radioaktivity, double *time,
                  int M, double decay_rate);
#endif // ACCURACY_ANALYSIS_DATA_H
