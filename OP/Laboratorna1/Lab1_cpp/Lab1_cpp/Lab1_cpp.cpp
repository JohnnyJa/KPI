#include <iostream>



using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	float SquareBig, SquareSmall;
	cout << "Введiть площу заданого квадрата:";
	cin >> SquareBig;

	SquareSmall = SquareBig / 2;

	cout <<"Площа вписаного квадрата: " << SquareSmall;
}