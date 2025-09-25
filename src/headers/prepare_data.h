#ifndef PREPARE_DATA_H
#define PREPARE_DATA_H

int experiment(double *radioactivity, double *time,
               double start_time, double end_time, double step);

void add_noise(double *radioactivity, int n);

double fdecay(double t);

#endif // PREPARE_DATA_H
