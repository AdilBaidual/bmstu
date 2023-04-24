#ifndef METRIC_H
#define METRIC_H

typedef struct {
    double *data;
    int rowLen;
} metricInit;

typedef struct {
    double max;
    double min;
    double median;
} metrics;

metrics calc(metricInit init);

#endif // METRIC_H
