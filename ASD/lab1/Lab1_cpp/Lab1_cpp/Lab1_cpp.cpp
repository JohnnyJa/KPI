
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    float A, B, x, Y;
    cout << "����i�� A �� �: ";
    cin >> A >> B;     //���������� ������ �� ������� ������� ������ 

    x = (A + B - abs(A - B)) / 4; // ���������� x

    Y = 3 * x + 5; //���������� Y

    cout << "Y = " << Y; //���� ����� �����������
    return 0;
}


