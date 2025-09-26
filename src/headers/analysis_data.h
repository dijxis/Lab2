#ifndef ANALYSIS_DATA_H
#define ANALYSIS_DATA_H

double nonlinear_equation (double *radioactivity, double *time,
                           int N, double precision, double interval1, double interval2);

double model(double *radioactivity, double *time, int N, double point);

double linear_equation(double *radioactivity, double *time, int n);

#endif // ANALYSIS_DATA_H
