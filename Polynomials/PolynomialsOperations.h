#pragma once
#include <iostream>
using namespace std;

class Polynomials
{
private:
	double* PolyArr;
	int ArrSize;
	//int current_size = ArrSize;
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
	void PolyDiv() {
		/*
		ƒл€ нахождени€ частного и остатка от делени€ полиномов нам нужно 2 обьекта полиномов. ¬ начале функции мы должны проверить 
		максимальную степень числител€(она должна быть больше либо равна степени знаменател€).  ƒалее мы делим ведущие члены 
		полиномов и записываем результат в структуре: степень и коэфициент. ”множаем полученный результат на все члены
		знаменател€. –езультат умножени€ умножаем на -1 и прибавл€ем к числителю почленно слагаемые с одинаковыми степен€ми. 
		  полиному результата приписываем оставшиес€ члены числител€. 
		ѕовтор€ем шаги, пока ведуща€ степень числител€ больше или равна степени ведущего члена знаменател€.
		*/
		//—оздаем полиномы дл€ числител€ и знаменател€:
		// Polynom a, b, result;
		// int a_size, b_size;
		// cout << "Enter size of the first polynom\t";
		// cin >> a_size;
		// cout << "Enter size of the second polynom\t";
		// cin >> b_size;
		// ≈сли максимальна€ степень числител€ меньше, чем максимальна€ степень знаменател€, то смысла продолжать программу делени€ нету! 
		// if(a < b) cout << "We can`t continue program!";
		// else {
		//a.Generate(a_size);
		//b.Generate(b_size);
		//result.Generate(20);
		// int i = 0, j = 0;
		// 
		// while (a.current_size >= b.current_size){ // ¬ыполн€етс€, пока текуща€ максимальна€ степень числител€ больше-равно максимальной степени знаменател€
		//result.PolyArr[i] = a.PolyArr[a_size - i] - b.PolyArr[b_size - i];
		//result.ArrSize[i] = a.ArrSize[a_size -1] - b.ArrSize[b_size - i];
		//current_size--;
		// while(/*не конец массива*/) {
		// temp.PolyArr[current_size -j] = result.PolyArr[i] * b.PolyArr[b_size-j];
		// temp.ArrSize[current_size] = result.ArrSize[i] * b.ArrSize[b_size-j];
		// j++;
		// }
		// //«десь нужно умножить все коэфициенты полинома temp на -1, а далее прибавить temp к текущему значению знаменател€
		// //ј далее повторить предыдущие операции
		// 
		//

	}
	//Add PolyRemainder()
};