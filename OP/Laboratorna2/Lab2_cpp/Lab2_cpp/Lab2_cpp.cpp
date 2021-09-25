
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	float x, y, a, b, c;
	cout << "¬ведiть розмiри сторiн цеглини a,b,c: ";
	cin >> a >> b >> c;

	cout << "¬ведiть розмiри отвору: x,y: ";
	cin >> x >> y;

	if ((a <= x && b <= y) || (b <= x && a <= y) || (b <= x && c <= y) || (c <= x && b <= y) || (a <= x && c <= y) || (c <= x) && (a <= y))
	{
		cout << "÷еглина з заданими розмiрами пройде в отвiр";
	}
	else
	{
		cout << "÷еглина з заданими розмiрами не пройде в отвiр";
	}

	return 0;
}