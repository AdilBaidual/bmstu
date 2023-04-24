#include "metric.h"

double maxArray(double *arr, int size);
double minArray(double *arr, int size);
double median(double *arr, int n);

metrics calc(metricInit init) {
    double *data = init.data;
    metrics result;
    result.max = maxArray(data, init.rowLen);
    result.min = minArray(data, init.rowLen);
    result.median = median(data, init.rowLen);
    return result;
}

double maxArray(double *arr, int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

double minArray(double arr[], int size) {
    double min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double median(double *arr, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                double temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    if (n % 2 != 0) {
        return arr[n/2];
    }
    return (arr[(n-1)/2] + arr[n/2]) / 2;
}
