
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	float x, y, a, b, c;
	cout << "����i�� ����i�� ����i� ������� a,b,c: ";
	cin >> a >> b >> c;

	cout << "����i�� ����i�� ������: x,y: ";
	cin >> x >> y;

	if ((a <= x && b <= y) || (b <= x && a <= y) || (b <= x && c <= y) || (c <= x && b <= y) || (a <= x && c <= y) || (c <= x) && (a <= y))
	{
		cout << "������� � �������� ����i���� ������ � ���i�";
	}
	else
	{
		cout << "������� � �������� ����i���� �� ������ � ���i�";
	}

	return 0;
}