#include "../statistics.h"
#include <math.h>
#include <stddef.h>
#include <stdlib.h>

// Utils

int assertSize(size_t size) {
  if (size <= 0)
    return 1;
  else
    return 0;
}

int compqs(const void *a, const void *b) {
  return (*(double *)a - *(double *)b);
}

// statistics.h

double median(double *dataset, size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;

  qsort(dataset, numOfElements, sizeof(double), compqs);

  if (!(numOfElements % 2)) {
    size_t mid1 = (numOfElements / 2) - 1, mid2 = numOfElements / 2;
    return ((*(dataset + mid1)) + (*(dataset + mid2))) / 2;
  } else {
    size_t mid = (size_t)(numOfElements / 2);
    return (*(dataset + mid));
  }
  return 0;
}
double quartile(double *dataset, int quartile, size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;

  qsort(dataset, numOfElements, sizeof(double), compqs);
  switch (quartile) {
  case 1:
    if (numOfElements == 4)
      return *dataset;
    return *(dataset + numOfElements / 4);
    break;
  case 2:
    if (!(numOfElements % 2)) {
      size_t mid1 = (numOfElements / 2) - 1, mid2 = numOfElements / 2;
      return ((*(dataset + mid1)) + (*(dataset + mid2))) / 2;
    } else {
      size_t mid = (size_t)(numOfElements / 2);
      return (*(dataset + mid));
    }
    break;
  case 3:
    return *(dataset + numOfElements * 3 / 4);
    break;

  default:
    return 0;
    break;
  }
}
double percentile(double *dataset, int percentile, size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;
  qsort(dataset, numOfElements, sizeof(double), compqs);

  double index = (percentile / 100.0) * (numOfElements - 1);
  if (index != (size_t)index) {
    size_t lwrI = (size_t)index;
    size_t uprI = lwrI + 1;
    if (uprI >= numOfElements)
      return *(dataset + (numOfElements - 1));

    double interpolation = index - lwrI;
    return *(dataset + lwrI) +
           interpolation * (*(dataset + uprI) - *(dataset + lwrI));
  } else
    return *(dataset + (size_t)index);
}

double mode(double *dataset, size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;
  double mode = 0.0;
  size_t mxcount = 0;

  for (register size_t i = 0; i < numOfElements; i++) {
    size_t count = 0;

    for (size_t j = 0; j < numOfElements; j++) {
      if ((*(dataset + j)) == (*(dataset + i)))
        ++count;
    }
    if (count > mxcount) {
      mxcount = count;
      mode = (*(dataset + i));
    }
  }

  return mode;
}

double min(double *dataset, size_t numOfElements) {
  double min = *dataset;
  for (size_t i = 0; i < numOfElements; i++) {
    if ((*(dataset + i)) < min)
      min = (*(dataset + i));
  }

  return min;
}
double max(double *dataset, size_t numOfElements) {
  double max = *dataset;
  for (size_t i = 0; i < numOfElements; i++) {
    if ((*(dataset + i)) > max)
      max = (*(dataset + i));
  }

  return max;
}

// means

double arithmeticMean(double *dataset, size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;
  double mean = 0.0;
  double sum = 0;
  for (register size_t i = 0; i < numOfElements; i++) {
    sum += *(dataset + i);
  }
  mean = sum / numOfElements;
  return mean;
}
double weightedArithmeticMean(double *dataset, double *weights,
                              size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;
  double xw = 0.0;
  double w_sum = 0.0;
  for (register size_t i = 0; i < numOfElements; i++) {
    w_sum += *(weights + i);
    xw += ((*(dataset + i)) * (*(weights + i)));
  }

  double mean = xw / w_sum;

  return mean;
}

double geometricMean(double *dataset, size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;
  double prod = 1.0;
  for (register size_t i = 0; i < numOfElements; i++) {
    prod *= (*(dataset + i));
  }

  return pow(prod, 1.0 / numOfElements);
  ;
}
double weightedGeometricMean(double *dataset, double *weights,
                             size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;
  double prod = 1.0;
  double wsum = 0.0;
  for (register size_t i = 0; i < numOfElements; i++) {
    wsum += *(weights + i);
    prod *= pow((*(dataset + i)), (*(weights + i)));
  }

  return pow(prod, 1.0 / wsum);
}

double harmonicMean(double *dataset, size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;
  double mean = 0.0;
  double xprod = 1.0;
  double densum = 0.0;
  for (register size_t i = 0; i < numOfElements; i++) {
    xprod *= (*(dataset + i));
  }
  for (register size_t i = 0; i < numOfElements; i++) {
    densum += xprod / (*(dataset + i));
  }

  mean = (numOfElements * xprod) / densum;

  return mean;
}
double weightedHarmonicMean(double *dataset, double *weights,
                            size_t numOfElements) {
  double mean = 0.0;
  double wsum = 0.0;
  double wxsum = 0.0;
  for (register size_t i = 0; i < numOfElements; i++) {
    wsum += (*(weights + i));
    wxsum += ((*(weights + i)) / (*(dataset + i)));
  }

  mean = wsum / wxsum;
  return mean;
}

// Variance and standar deviation

double variance(double *dataset, double mean, size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;
  double xxmsq = 0;
  for (size_t i = 0; i < numOfElements; i++) {
    xxmsq += pow((*(dataset + i)) - mean, 2);
  }
  return xxmsq / numOfElements;
}
double standardDeviation(double *dataset, double mean, size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;
  double xxmsq = 0;
  for (size_t i = 0; i < numOfElements; i++) {
    xxmsq += pow((*(dataset + i)) - mean, 2);
  }
  return sqrt(xxmsq / numOfElements);
}
double standardDeviationV(double variance) { return sqrt(variance); }

double rootMeanSquare(double *dataset, size_t numOfElements) {
  if (assertSize(numOfElements))
    return 0;

  double mean = 0.0;
  double sum = 0;
  for (register size_t i = 0; i < numOfElements; i++) {
    sum += ((*(dataset + i)) * (*(dataset + i)));
  }
  mean = sum / numOfElements;
  mean = sqrt(mean);

  return mean;
}
