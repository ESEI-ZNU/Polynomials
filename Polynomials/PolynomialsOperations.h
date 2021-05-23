#pragma once
#include <iostream>
using namespace std;

class Polynomials
{
private:
	double* PolyArr;
	int ArrSize;
	int cSize;
public:
	//Constructor
	Polynomials()
	{
		int i;
		cout << "Enter number of elements: ";
		cin >> ArrSize;
		while (ArrSize < 2)
		{
			cin >> ArrSize;
			if (ArrSize < 2)
			{
				cout << "Enter at least two elements:" << endl;
			}
		}
		PolyArr = new double[ArrSize];
		for (i = 0; i < ArrSize; i++)
		{
			cout << "Enter " << i + 1 << " element: ";
			cin >> PolyArr[i];
		}
		cSize = ArrSize;
	}
	//Destructor
	~Polynomials()
	{
		delete[] PolyArr;
	}
	//Copy constructor
	Polynomials(const Polynomials& copy)
	{
		int i;
		ArrSize = copy.ArrSize;
		for (i = 0; i < ArrSize; i++)
		{
			PolyArr[i] = copy.PolyArr[i];
		}
	}
	//----------------------------------------------------------------
	
	//Function calculating the value of a polynomial for a specific argument
	double ArgumentCalculus()
	{
		int i;
		double eps;
		double result;
		double* b = new double[ArrSize];

		cout << "Enter epsilon: ";
		cin >> eps;

		cout << endl;

		//Top part of spreadsheet
		for (i = 0; i < ArrSize; i++)
		{
			cout << "+-------";
		}
		cout << "+" << endl;

		//Output of initial data
		for (i = 0; i < ArrSize; i++)
		{
			cout << "| " << PolyArr[i] << "\t";
		}
		cout << "|" << endl;

		//Mid part of spreadsheet
		for (i = 0; i < ArrSize; i++)
		{
			cout << "+-------";
		}
		cout << "+" << endl;

		b[0] = PolyArr[0];
		cout << "| " << b[0] << "\t";
		//Calculation and writing to the spreadsheet
		for (i = 1; i < ArrSize; i++)
		{
			b[i] = (b[i - 1] * eps) + PolyArr[i];
			cout << "| " << b[i] << "\t";
		}
		cout << "|" << endl;

		//Botom part of spreadsheet
		for (i = 0; i < ArrSize; i++)
		{
			cout << "+-------";
		}
		cout << "+" << endl << endl;

		result = b[ArrSize - 1];

		cout << "Answer: " << result << endl;

		delete[]b;
		return result;
	}

	void copyFromTempToPoly(int *tempKf, int tempMaxElemID, int *tempDegree, Polynomials & copyTo) {
		copyTo.ArrSize = copyTo.cSize = tempDegree[tempMaxElemID];
		for (int i = 0; i <= tempMaxElemID; i++) {
			copyTo.PolyArr[i] = tempKf[i];//copying koeficients to another object
		}
	}
	void copyPoly(Polynomials& copy_from, Polynomials& copy_to) {
		copy_to.ArrSize = copy_to.cSize = copy_from.cSize;
		for (int i = 0; i <= copy_from.cSize; i++) {
			copy_to.PolyArr[i] = copy_from.PolyArr[i];
		}
	}

	void PolyDiv() {
		/*
To find the quotient and remainder of the division of polynomials, we need 2 polynomial objects. At the beginning of the function, we must check
the maximum degree of the numerator (it must be greater than or equal to the degree of the denominator). Next, we divide the leading members
polynomials and write the result in the structure: degree and coefficient. We multiply the result by all terms
denominator. We multiply the result of multiplication by -1 and add term-by-term terms with the same degrees to the numerator.
We assign the remaining members of the numerator to the polynomial of the result.
Repeat the steps until the leading power of the numerator is greater than or equal to the power of the leading term of the denominator.
		*/
		//Creating nominator and denominator polynoms 
		Polynomials a, b, printPolynom;
		int a_size, b_size;
			cout << "Enter size of the first polynom\t";
				cin >> a_size;
			cout << "Enter size of the second polynom\t";
				cin >> b_size;

		copyPoly(a, printPolynom);

		//IF maxdegree of a is less then we will end this func  
		if(a_size < b_size) cout << "We can`t continue program!";
		else {
			a.ArrSize = a_size;
			b.ArrSize = b_size;


			int *resDegree = new int[100];
			int maxElemID = 0;//id of max elem for result 
			int* resKf = new int[100];


			int* tempDegree = new int[100];
			int tempMaxElemID = 0;//id of max elem for result 
			int* tempKf = new int[100];

			a.cSize = a.ArrSize;
			b.cSize = b.ArrSize;

			int i = 0, j = 0;

			while (a.cSize >= b.cSize) { // Continuing while a degree is bigger or equal with b degree
				resKf[maxElemID] = a.PolyArr[a.cSize] - b.PolyArr[b.cSize];
				resDegree[maxElemID] = a.cSize - b.cSize;
				a.cSize--;
				while (j <= b_size) {
					tempKf[j] = resKf[i] * b.PolyArr[b_size - j];
					tempDegree [j] = resDegree[i] * (b_size - j);
					j++;
				}
				//Then we have to repeat previous operations
				while (i <= j) {//Multiplying tempKf[i] by -1
					tempKf[i] *= -1;
					i++;
				}
				i = 0;
				while (i <= j) {
					tempMaxElemID = j;
					if (a.cSize - i == tempDegree[tempMaxElemID]) {
						tempKf[i] = tempKf[i] + a.PolyArr[a.cSize - i];
						i++;
					}
					else {
						break;
					}
				}
				maxElemID++;
				copyFromTempToPoly(tempKf, tempMaxElemID, tempDegree, a);
			}
		}
		int iter = 0;
		//Printing result of the division
		while (iter <= maxElemID) {//Printing the result
			cout << resKf[iter] << "x^" << resDegree[iter] << " + ";
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

		int tepmIter = 0;
		//Printing remainder of the division
		while (tempMaxElemID >= tempIter) {
			cout << tempKf[tempIter] << "x^" << tempDegree[iter] << " + ";
		}
	}
	//Add PolyRemainder()
};