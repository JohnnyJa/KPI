
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float A, B, x, Y;
    cout << "Введiть A та В: ";
    cin >> A >> B;     //Оголошення змінних та задання вхідних данних 

    x = (A + B - abs(A - B)) / 4; // Обчислення x

    Y = 3 * x + 5; //Обчислення Y

    cout << "Y = " << Y; //Вивід віповіді користувачу
    return 0;
}


