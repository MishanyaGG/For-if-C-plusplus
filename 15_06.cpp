#include <iostream>
#include <math.h>
#include <cstdlib> // srand()
#include <random>
#include <vector> // для использования динамического массива

/// <summary>
/// Задача 1
/// </summary>
void task1();

/// <summary>
/// Задача 2
/// </summary>
/// <param name="n">Количество элементов массива</param>
void task2(const int n);

/// <summary>
/// Задача 3
/// </summary>
/// <param name="n">Количество элементов массива</param>
void task3(const int n);

void task4();

using namespace std;

int main()
{
    int choise = -1;
    while (choise != 0) {
        cout << "Enter action. "; cin >> choise;

        switch (choise) {
        case 1: {
            task1(); break;
        }
        case 2: {
            int size;
            cout << "Enter size array "; cin >> size;
            task2(size);
        }
        case 3: {
            int size;
            cout << "Enter size array "; cin >> size;
            task3(size);
        }
        case 4: {
            task4(); break;
        }
        case 0:
            choise = 0;
        }
    }
}

void task1() {
    // выделение памяти для интервалов таблицы
    double tn, tk, tx, u, a;
    int n;
    cout << "Vvecti tn tk tx a: "; cin >> tn >> tk >> tx >> a;
    //расчёт количества строк в таблице на заданноминтервале
    n = (tk - tn) / tx + 1;
    double t = tn;
    for (int i = 1; i <= n; i++, t += tx)
    {
        // введение дополнит переменных, чтобы не считать дважды
        double zn1 = sin(t), zn2 = cos(t);
        // проверка ОДЗ
        if (t > 0 and zn1 != 0 and zn2 > 0)
        {
            u = (log(t) + pow(a, (log(2) / zn1)) / sqrt(zn2));
            cout << " i=" << i << " x=" << t << " y=" << u << endl;
        }
        else cout << " i=" << i << " x=" << t << " narushenie ODZ\n";
    }
    system("pause");
}

void task2(const int N) {
    int m, n;
    cout << "Set m, n: "; cin >> m >> n;

    // Посев случайных чисел
    srand(time(0));

    // Создание массива через указатель
    int* const arr = new int[N];

    // Генерация случайных значений в массиве
    // в диапазоне от 0 до 50
    for (int i { 0 }; i < N; i++) {
        
        int& el = *(arr + i) = rand() % 51;

        cout << i+1 << ". Snach do " << el << ". ";

        // Если элемент кратный m то увеличиваем в 3 раза
        if (el % m == 0) {
            el *= 3; 
            cout << "Snach posle " << el << endl;
            continue;
        }

        // Если элемент кратный n то уменьшаем в 2 раза
        if (el % n == 0) {
            el /= 2;
            cout << "Snach posle " << el << endl;
            continue;
        }

        // Если значение не кратно ни m, ни n
        cout << "Snach posle " << el << endl;
    }
}

void task3(const int N) {
    // Посев случайных чисел
    srand(time(0));

    // Создание массива через указатель
    int* const arr = new int[N];
    
    // Динамический массив
    vector<int> rezArr;

    cout << "Elements arr: ";

    // Формирование элементов массива в диапазове от -5 до 10
    // И запись в вектор значений элементов массива кратных 3
    for (int i{ 0 }; i < N; i++) {

        const int& el = *(arr + i) = rand() % 16 - 5;

        if (el % 3 == 0) {
            rezArr.push_back(el);
        }

        cout << el << " ";
    }

    cout << endl;

    cout << "Elements vector rezArr: ";

    // Отображение записанных элементов вектора
    for (const int& el : rezArr) {
        cout << el << " ";
    }
    cout << endl;
}

void task4() {
    int N, N1, n_char = 0;

    cout << "Vvesty lyuboe tseloe chislo: ";
    cin >> N;

    N1 = N;

    while (N1 > 0)
    {
        N1 /= 10;
        n_char++;
    }

    cout << "V chisle N = " << N << '\t' << n_char << " tsifr \n";

}