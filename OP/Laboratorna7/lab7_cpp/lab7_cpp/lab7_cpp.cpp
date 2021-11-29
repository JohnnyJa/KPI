
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void input(double[], int&);

void output(double[], int, double, double);

void find_difference_of_adjacent(double[], int);

double max(double[], int);

double min(double[], int);

int main()
{
    setlocale(LC_ALL, "");
    double B[10], difference_of_advantages[9];
    int size;
    input(B, size);
    find_difference_of_adjacent(B, size);
    output(B, size, max(B, size), min(B, size));
    return 1;
}

void input(double B[], int& size)
{
    srand(time(NULL));
    //srand(5);

    cout << "¬ведiть розмiр массиву(<=10) ";
    cin >> size;

    cout << "ћассив:\n";
    
    double random_value_1, random_value_2, t;
    
    for (int i = 0; i < size; ++i) 
    {
        random_value_1 = rand() % 201 - 100;                                        //√енерац≥€ випадкового чисельника та знаменника
        random_value_2 = rand() % 17 - 10;

        while (random_value_2 == 0)                                                 //ѕерев≥рка знаменника на 0
        {
            random_value_2 = rand() % 17 - 10;
        }

        t = (int)((random_value_1 / random_value_2) * 1000);                        //ќкругленн€ числа до тис€чних
        B[i] = t / 1000;

        cout << B[i] << setprecision(3) << ' ';
    }
    cout << "\n";
}

void find_difference_of_adjacent(double B[], int size)
{
    for (int i = 0; i < size-1; ++i) 
    {
        B[i] = abs(B[i] - B[i + 1]);
    }
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

void output(double B[], int size, double max, double min)
{
    cout << "Ќайбiльша рiзниц€ двох сусiднiх чисел: " << max << '\n';
    cout << "Ќайменша рiзниц€ двох сусiднiх чисел: " << min << '\n';
}