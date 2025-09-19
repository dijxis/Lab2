#ifndef ANALYSIS_DATA_H
#define ANALYSIS_DATA_H

double nonlinear_equation (double *radioactivity, double *time, int N, double precision);

double model(double *radioactivity, double *time, int N, double point);

#endif // ANALYSIS_DATA_H
