/**
 *   Statistics.h
 *   A små statistics library I made for C/C++ for learning purposes
 *   Fell free to use :3
 *   By Jay(aka JannyDarky)
 **/

#ifndef _STATISTICS_H
#define _STATISTICS_H

#ifdef _cplusplus
extern "C" {
#endif
//*DevNotes
// TODO? : versão das funções para float

#include <stddef.h>

// Macro for the size of a set | Macro para o tamanho de um conjuto
//@param SET : an dataset(array)
#define SIZEOFSET(SET) (sizeof(SET) / sizeof(SET[0]))

// Find the median | acha a mediana
//@param dataset : dataset(array)
//@param numOfElements : size of the dataset | tamanho do dataset;
double median(double *dataset, size_t numOfElements);
// Find the quartile | acha o quartil
//@param dataset : dataset(array)
//@param quartile : the quartile, valid values [1, 2(median), 3], ever other
// value will bug and return 0 | o quartil, valores validos [1, 2(mediana), 3],
// qualquer outro valor retornara 0
//@param numOfElements : size of the dataset | tamanho do dataset;
double quartile(double *dataset, int quartile, size_t numOfElements);
// Find the percentile | acha o percentil
//@param dataset : dataset(array)
//@param numOfElements : size of the dataset | tamanho do dataset;
double percentile(double *dataset, int percentile, size_t numOfElements);

// find the mode | acha a média
//@param dataset : dataset(array)
//@param numOfElements : size of the dataset | tamanho do dataset;
double mode(double *dataset,
            size_t numOfElements); // ! very slow (*- *) [O(n^2)]

// finds the min value | acha o menor valor
//@param dataset : dataset(array)
//@param numOfElements : size of the dataset | tamanho do dataset;
double min(double *dataset, size_t numOfElements);
// finds the max value | acha o maior valor
//@param dataset : dataset(array)
//@param numOfElements : size of the dataset | tamanho do dataset;
double max(double *dataset, size_t numOfElements);

// Means|Médias

// calculates the arithmetic mean | calcula a média aritmética
//@param dataset : dataset(array)
//@param numOfElements : size of the dataset | tamanho do dataset;
double arithmeticMean(double *dataset, size_t numOfElements);
// calculates the weighted arithmetic mean | calcula a média aritmética
// ponderada
//@param dataset : dataset(array)
//@param weights : an array of the weights, each weight i is for the element
// i-th of the dataset | uma array de pesos, cada peso i é para o i-ézimo
// elemento do dataset
//@param numOfElements : size of the dataset;
double weightedArithmeticMean(double *dataset, double *weights,
                              size_t numOfElements);
// calculates the geometric mean | calcula a média geométrica
//@param dataset : dataset(array)
//@param numOfElements : size of the dataset | tamanho do dataset;
double geometricMean(double *dataset, size_t numOfElements);
// calculates the weighted geometric mean | calcula a média geométrica ponderada
//@param dataset : dataset(array)
//@param weights : an array of the weights, each weight i is for the element
// i-th of the dataset | uma array de pesos, cada peso i é para o i-ézimo
// elemento do dataset
//@param numOfElements : size of the dataset;
double weightedGeometricMean(double *dataset, double *weights,
                             size_t numOfElements);
// calculates the harmonic mean | calcula a média harmônica
//@param dataset : dataset(array)
//@param numOfElements : size of the dataset | tamanho do dataset;
double harmonicMean(double *dataset, size_t numOfElements);
// calculates the weighted harmonic mean | calcula a média harmônica ponderada
//@param dataset : dataset(array)
//@param weights : an array of the weights, each weight i is for the element
// i-th of the dataset | uma array de pesos, cada peso i é para o i-ézimo
// elemento do dataset
//@param numOfElements : size of the dataset | tamanho do dataset;
double weightedHarmonicMean(double *dataset, double *weights,
                            size_t numOfElements);

// Variance

// calculates the variance | calcula a variancia
//@param dataset : dataset(array);
//@param mean : dataset mean | média do dataset
//@param numOfElements : size of the dataset | tamanho do dataset
double variance(double *dataset, double mean, size_t numOfElements);
// calculates o standard deviation | calcula o desvio padrão
//@param dataset : dataset(array);
//@param mean : dataset mean | média do dataset
//@param numOfElements : size of the dataset | tamanho do dataset
double standardDeviation(double *dataset, double mean, size_t numOfElements);
// calculates o standard deviation from the variance| calcula o desvio padrão a
// partir da variancia
//@param variance : variance | variancia
double standardDeviationV(double variance);

double rootMeanSquare(double *dataset, size_t numOfElements);

#ifdef _cplusplus
}
#endif

#endif
