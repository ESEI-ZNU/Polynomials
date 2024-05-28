#pragma once
//Функції программи
int* Multiply(int* poly1, int* poly2, int deg1, int deg2);
int* MultiplyOD(int* poly, int deg, int monomialCoeff, int monomialDegree);
void Printp(int* poly, int deg);
int* Plus(int* poly1, int* poly2, int deg1, int deg2);
int* Minus(int* poly1, int* poly2, int deg1, int deg2);
int* Dil(int* poly1, int* poly2, int deg1, int deg2);
int* Surplus(int* poly1, int* poly2, int deg1, int deg2);
int DilOD(int* poly, int deg, int x);
int* ArgPol(int* poly, int deg, int monomialCoeff, int monomialDegree);
