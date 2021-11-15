// Lab6_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

using namespace std;

double calculate_square_triangle(double a, double b, double c);

double calculate_max_square(double square1, double square2, double square3);

void input(double &a, double &b, double &c);

void output(double square1, double square2, double square3, double answer);



int main()
{
    setlocale(LC_ALL, "");
    double a1, b1, c1, a2, b2, c2, a3, b3, c3;
    cout << "Введiть сторони першого трикутника\n";
    input(a1, b1, c1);
    cout << "Введiть сторони другого трикутника\n";
    input(a2, b2, c2);
    cout << "Введiть сторони третього трикутника\n";
    input(a3, b3, c3);
    
    //Обчислюємо площі трикутників

    double square1 = calculate_square_triangle(a1, b1, c1);
    double square2 = calculate_square_triangle(a2, b2, c2);
    double square3 = calculate_square_triangle(a3, b3, c3);

    //обчислюємо найбільшу площу
    
    output(square1, square2, square3, calculate_max_square(square1, square2, square3) );
   
    return 1;
}

double calculate_square_triangle(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    double square = sqrt(p * (p - a) * (p - b) * (p - c));
    return square;
}


double calculate_max_square(double square1, double square2, double square3)
{
    double max;
    if ((square1 > square2) && (square1 > square3)) {
        max = square1;
    }

    if ((square2 > square1) && (square2 > square3)) {
        max = square2;
    }

    if ((square3 > square2) && (square3 > square1)) {
        max = square3;
    }

    return max;
}

void input(double &a, double &b, double &c)
{
    bool f = true;
    while (f) 
    {
        f = false;
        cin >> a >> b >> c;
        if ((a + b <= c) || (c + b <= a) || (a + c <= b))
        {
            f = true;
            cout << "Такого трикутника не iснує\n";
        }
    }
}

void output(double square1, double square2, double square3, double answer)
{
    cout << "Площа першого трикутника: " << square1 << "\nПлоща другого трикутника: " << square2 << "\nПлоща третього трикутника: " << square3 << "\nНайбiльша площа трикутника: " << answer;
}



