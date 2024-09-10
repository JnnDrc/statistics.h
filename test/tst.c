#include "../statistics.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  double set[] = {7, 6, 4, 7, 5, 9}; // 4 , 5 , 6 , 7 , 7 , 9
  double weights[] = {1, 2, 3, 4};
  printf("\nmin | max : %.2f | %.2f", min(set, SIZEOFSET(set)),
         max(set, SIZEOFSET(set)));
  printf("\nmode : %.2lf", mode(set, SIZEOFSET(set)));
  printf("\nmedian : %.2lf", median(set, SIZEOFSET(set)));

  printf("\nquartile[1] : %.2lf", quartile(set, 1, SIZEOFSET(set)));
  printf("\nquartile[2] : %.2lf", quartile(set, 2, SIZEOFSET(set)));
  printf("\nquartile[3] : %.2lf", quartile(set, 3, SIZEOFSET(set)));

  printf("\npercentile : %.2lf", percentile(set, 50, SIZEOFSET(set)));
  printf("\npercentile : %.2lf", percentile(set, 90, SIZEOFSET(set)));

  printf("\nAM : %.2lf", arithmeticMean(set, SIZEOFSET(set)));
  printf("\nWAM : %.2lf", weightedArithmeticMean(set, weights, SIZEOFSET(set)));

  printf("\nGM : %.2lf", geometricMean(set, SIZEOFSET(set)));
  printf("\nWGM : %.2lf", weightedGeometricMean(set, weights, SIZEOFSET(set)));

  printf("\nHM : %.2lf", harmonicMean(set, SIZEOFSET(set)));
  printf("\nWHM : %.2lf", weightedHarmonicMean(set, weights, SIZEOFSET(set)));

  printf("\nvariance : %.2lf",
         variance(set, arithmeticMean(set, SIZEOFSET(set)), SIZEOFSET(set)));
  printf("\nSD : %.2lf",
         standardDeviation(set, arithmeticMean(set, SIZEOFSET(set)),
                           SIZEOFSET(set)));
  printf("\nSDFV : %.2lf",
         standardDeviationV(variance(set, arithmeticMean(set, SIZEOFSET(set)),
                                     SIZEOFSET(set))));

  printf("\nRMS : %.2lf", rootMeanSquare(set, SIZEOFSET(set)));

  return 0;
}
