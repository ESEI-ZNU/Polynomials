#pragma once
#include <iostream>
using namespace std;

class Polynomials
{
private:
	int* PolyArr;
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
		PolyArr = new int[ArrSize];
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

	void PolyDivMono()
	{
		int MCoef, MDeg;
		cout << "Enter Monomial = ";
		cin >> MCoef;
		cout << "Enter Monomials power of = ";
		cin >> MDeg;
		cout << "You entered " << MCoef << "x^" << MDeg << endl;
		int i = 0;
		int j = 0;
		int ResIndex = 0;
		int ResDeg = Degree - MDeg;
		int* ResArr = new int[ResDeg + 1];

		int* Temp = new int[Degree + 1];
		int TempSize = Degree;

		j = ResDeg + 1;

		int Start = 0;
		int Memory;
		for (i = 0; i <= Degree; i++)
		{
			Temp[i] = PolyArr[i];
		}

		while (TempSize >= MDeg)
		{
			ResArr[ResIndex] = Temp[Start] / MCoef;
			for (i = 0; i <= MDeg; i++)
			{
				Temp[i + Start] = ResArr[ResIndex] * MCoef;
			}
			ResIndex++;
			for (i = 0; i <= MDeg; i++)
			{
				Memory = Temp[Degree];
				Temp[i + Start] = PolyArr[i + Start] - Temp[i + Start];

			}
			Start++;
			TempSize--;
		}
	}

	void PolyDiv(Polynomials& SecondPoly, bool Remainder)
	{
		int i = 0;
		int j = 0;
		int ResIndex = 0;
		int ResDeg = Degree - SecondPoly.Degree;
		int* ResArr = new int[ResDeg + 1];

		int* Temp = new int[Degree + 1];
		int TempSize = Degree;

		j = ResDeg + 1;

		int Start = 0;
		int Memory;
		for (i = 0; i <= Degree; i++)
		{
			Temp[i] = PolyArr[i];
		}

		while (TempSize >= SecondPoly.Degree)
		{
			ResArr[ResIndex] = Temp[Start] / SecondPoly.PolyArr[0];
			for (i = 0; i <= SecondPoly.Degree; i++)
			{
				Temp[i + Start] = ResArr[ResIndex] * SecondPoly.PolyArr[i];
			}
			ResIndex++;
			for (i = 0; i <= SecondPoly.Degree; i++)
			{
				Memory = Temp[Degree];
				Temp[i + Start] = PolyArr[i + Start] - Temp[i + Start];

			}
			Start++;
			TempSize--;
		}
		if (Remainder == true)
		{
			j = Degree - Start;
			for (i = Start; i <= Degree; i++)
			{
				if (j >= 1)
				{
					cout << Temp[i] << "x^" << j;
				}
				else
				{
					cout << Temp[i];
				}
				j--;
			}
		}
	}
};