#include "PolynomialsFunc.h"
#include <algorithm>
using namespace std;
// Функція для додавання поліномів
int* Plus(int* poly1, int* poly2, int deg1, int deg2) {
    int maxDeg = max(deg1, deg2);
    int* result = new int[maxDeg + 1];

    for (int i = 0; i <= maxDeg; ++i) {
        int term1 = (i <= deg1) ? poly1[i] : 0;
        int term2 = (i <= deg2) ? poly2[i] : 0;
        result[i] = term1 + term2;
    }

    return result;
}

// Функція для віднімання поліномів
int* Minus(int* poly1, int* poly2, int deg1, int deg2) {
    int maxDeg = max(deg1, deg2);
    int* result = new int[maxDeg + 1];

    for (int i = 0; i <= maxDeg; ++i) {
        int term1 = (i <= deg1) ? poly1[i] : 0;
        int term2 = (i <= deg2) ? poly2[i] : 0;
        result[i] = term1 - term2;
    }

    return result;
}

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

// Функція для ділення поліномів
int* Dil(int* poly1, int* poly2, int deg1, int deg2) {
    int* result = new int[deg1 - deg2 + 1];
    int* tempPoly = new int[deg1 + 1];

    for (int i = 0; i <= deg1; ++i) {
        tempPoly[i] = poly1[i];
    }

    for (int i = deg1 - deg2; i >= 0; --i) {
        int coeff = tempPoly[deg1] / poly2[deg2];
        result[i] = coeff;

        for (int j = 0; j <= deg2; ++j) {
            tempPoly[i + j] -= coeff * poly2[j];
        }
        deg1--;
    }

    delete[] tempPoly;
    return result;
}

// Функція для знаходження залишку від ділення поліномів
int* Surplus(int* poly1, int* poly2, int deg1, int deg2) {
    int* quotient = Dil(poly1, poly2, deg1, deg2);
    int* product = Multiply(quotient, poly2, deg1 - deg2, deg2);

    int* result = new int[deg1 + 1];
    for (int i = 0; i <= deg1; ++i) {
        result[i] = poly1[i] - product[i];
    }

    delete[] quotient;
    delete[] product;
    return result;
}
// Функція для ділення полінома на одночлен
int DilOD(int* poly, int deg, int x) {
    int result = poly[deg];

    for (int i = deg - 1; i >= 0; --i) {
        result = result * x + poly[i];
    }

    return result;
}

// Функція для обчислення значення полінома з певним аргументом
int* ArgPol(int* poly, int deg, int monomialCoeff, int monomialDegree) {
    int* result = new int[deg - monomialDegree + 1];

    for (int i = 0; i <= deg - monomialDegree; ++i) {
        result[i] = poly[i + monomialDegree] / monomialCoeff;
    }

    return result;
}
