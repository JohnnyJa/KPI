#include <iostream>



using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	float SquareBig, SquareSmall;
	cout << "����i�� ����� �������� ��������:";
	cin >> SquareBig;

	SquareSmall = SquareBig / 2;

	cout <<"����� ��������� ��������: " << SquareSmall;
}