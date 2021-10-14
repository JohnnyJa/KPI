#include <iostream>
#include <math.h>
#define E 0.000001

using namespace std;

int main()
{
    setlocale(LC_ALL, "");


    double a, result = 0, counter = 1, last = 0, flag = 1;
    cout << "Введiть значення а: ";
    cin >> a;


    while (flag >= E) {
        result += pow(-1, (counter - 1) ) * pow( (a - 1), counter ) / counter;  
        counter++;
        flag = abs(result - last);
        last = result;
    }

    cout << "Результат обчислень за формулою: " << result << '\n' << "Результат обчислень стандартною функцiєю: " << log(a);
    return 0;
}

