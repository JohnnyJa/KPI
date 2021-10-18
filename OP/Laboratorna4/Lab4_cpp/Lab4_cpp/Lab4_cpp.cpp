// Lab4_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int n;
    double sum = 0, t;
    cout << "Ââåäiòü n: ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        t = (i * (2 * i + 1) * (2 * i + 1));
        sum += 1 / t;
    }
    cout << "Ñóììà äîðiâíþº: " << sum;

    return 0;
}

