int experiment(double *radioactivity, double *time,
               double start_time, double end_time, double step);

void add_noise(double *radioactivity, int N);

double fdecay(double t);
