// Polynomials.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

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

// Функція для виводу полінома
void Printp(int* poly, int deg) {
    for (int i = deg; i >= 0; --i) {
        if (poly[i] != 0) {
            if (i != deg && poly[i] > 0) {
                cout << " + ";
            }
            else if (i != deg && poly[i] < 0) {
                cout << " - ";
            }
            if (abs(poly[i]) != 1 || i == 0) {
                cout << abs(poly[i]);
            }
            if (i > 0) {
                cout << "x";
                if (i > 1) {
                    cout << "^" << i;
                }
            }
        }
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ukr");
    int maxDeg = 10;
    int* poly1 = new int[maxDeg + 1];
    int* poly2 = new int[maxDeg + 1];
    int deg1, deg2;
    int* result = nullptr;

    // Зчитування степенів поліномів та їх коефіцієнтів
    cout << "Введіть степінь першого полінома: ";
    cin >> deg1;
    cout << "Введіть коефіцієнти першого полінома: ";
    for (int i = deg1; i >= 0; --i) {
        cin >> poly1[i];
    }
    cout << "Перший поліном: ";
    Printp(poly1, deg1);

    cout << "Введіть степінь другого полінома: ";
    cin >> deg2;
    cout << "Введіть коефіцієнти другого полінома: ";
    for (int i = deg2; i >= 0; --i) {
        cin >> poly2[i];
    }
    cout << "Другий поліном: ";
    Printp(poly2, deg2);

    int action;
    cout << "Оберіть операцію:" << endl;
    cout << "1. Додавання" << endl;
    cout << "2. Віднімання" << endl;
    cout << "3. Множення" << endl;
    cout << "4. Ділення" << endl;
    cout << "5. Знаходження залишку" << endl;
    cout << "6. Множення на одночлен" << endl;
    cout << "7. Ділення на одночлен" << endl;
    cout << "8. Обчислення з аргументом" << endl;
    cout << "Ваш вибір: ";
    cin >> action;


    switch (action) {

    case 3:
        result = Multiply(poly1, poly2, deg1, deg2);
        cout << "Результат множення: ";
        Printp(result, deg1 + deg2);
        break;
    case 6:
        int monomialCoeff, monomialDegree;
        cout << "Введіть коефіцієнт одночлена: ";
        cin >> monomialCoeff;
        cout << "Введіть степінь одночлена: ";
        cin >> monomialDegree;
        result = MultiplyOD(poly1, deg1, monomialCoeff, monomialDegree);
        cout << "Результат множення полінома на одночлен: ";
        Printp(result, deg1 + monomialDegree);
        break;

    delete[] poly1;
    delete[] poly2;
    delete[] result;

    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
