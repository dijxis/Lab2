#include "headers/accuracy_analysis_data.h"

#include <math.h>

double dev_exp(double *radioactivity, double *time,
               int M, double decay_time)
{
    double sum_residuals1 = 0;
    for (int i = 0; i < M; i++) {
        sum_residuals1 += pow((radioactivity[i] - pow(M_E, -time[i] / decay_time)), 2);
    }
    return sqrt(sum_residuals1) / M;
}

double dev_linear(double *radioactivity, double *time,
                  int M, double decay_rate)
{
    double sum_residuals2 = 0;
    for (int i = 0; i < M; i++) {
        sum_residuals1 += pow((radioactivity[i] - (1 - time[i] / decay_rate)), 2);
    }
    return sqrt(sum_residuals2) / M;
}
