#include "PolynomialsFunc.h"

// Функція для множення поліномів
int* Multiply(int* poly1, int* poly2, int deg1, int deg2) {
    int* result = new int[deg1 + deg2 + 1];

    for (int i = 0; i <= deg1 + deg2; ++i) {
        result[i] = 0;
    }

    for (int i = 0; i <= deg1; ++i) {
        for (int j = 0; j <= deg2; ++j) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }

    return result;
}
// Функція для множення полінома на одночлен
int* MultiplyOD(int* poly, int deg, int monomialCoeff, int monomialDegree) {
    int* result = new int[deg + monomialDegree + 1];

    for (int i = 0; i <= deg + monomialDegree; ++i) {
        result[i] = 0;
    }

    for (int i = 0; i <= deg; ++i) {
        result[i + monomialDegree] = poly[i] * monomialCoeff;
    }

    return result;
}
