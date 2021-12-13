
#include <iostream>
#include <time.h>

using namespace std;


double* input(int&);

void output(double, double);

double* find_difference_of_adjacent(double[], int);

double max(double[], int);

double min(double[], int);




int main()
{
    setlocale(LC_ALL, "");

    int size;
    double *B = input(size);

    double *difference_of_advantages = find_difference_of_adjacent(B, size);

    output(max(difference_of_advantages, size), min(difference_of_advantages, size));

    return 1;
}




double* input(int& size)
{
    srand(time(NULL));
    //srand(5);

    cout << "Введiть розмiр массиву ";
    cin >> size;

    cout << "Массив:\n";

    double* B = new double[size];
  
    double random_value_1, random_value_2, t;
    
    for (int i = 0; i < size; ++i) 
    {
        random_value_1 = rand() % 201 - 100;                                        //Генерація випадкового чисельника та знаменника
        random_value_2 = rand() % 17 - 10;

        while (random_value_2 == 0)                                                 //Перевірка знаменника на 0
        {
            random_value_2 = rand() % 17 - 10;
        }

        t = (int)((random_value_1 / random_value_2) * 1000);                        //Округлення числа до тисячних
        *(B+i) = t / 1000;

        cout << *(B+i)  << ' ';
    }
    cout << "\n\n";
    return B;
}

double* find_difference_of_adjacent(double B[], int size)
{
    double* difference_of_adjacent = new double[size - 1];
    cout << "Массив модулiв рiзниць сусiднiх елементiв: \n";
    for (int i = 0; i < size-1; ++i) 
    {
        *(difference_of_adjacent + i) = abs(B[i] - B[i + 1]);
        cout << *(difference_of_adjacent + i) << ' ';
    }
    cout << "\n\n";
    return difference_of_adjacent;
}

double max(double B[], int size)
{
    double max = B[0];
    for (int i = 1; i < size-1; ++i)
    {
        if (B[i] > max) max = B[i];
    }
    return max;
}

double min(double B[], int size)
{
    double min = B[0];
    for (int i = 1; i < size-1; ++i)
    {
        if (B[i] < min) min = B[i];
    }
    return min;
}

void output(double max, double min)
{
    cout << "Найбiльша рiзниця двох сусiднiх чисел: " << max << '\n';
    cout << "Найменша рiзниця двох сусiднiх чисел: " << min << '\n';
}