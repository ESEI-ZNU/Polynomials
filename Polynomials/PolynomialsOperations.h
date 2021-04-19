#pragma once
#include <iostream>
using namespace std;

class Polynomials
{
private:
	double* PolyArr;
	int ArrSize;
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
};