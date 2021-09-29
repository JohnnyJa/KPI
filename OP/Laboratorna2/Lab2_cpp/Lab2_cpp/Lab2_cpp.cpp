
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	float x, y, a, b, c;
	bool res = false;

	cout << "¬ведiть розмiри сторiн цеглини a,b,c: ";
	cin >> a >> b >> c;

	cout << "¬ведiть розмiри отвору: x,y: ";
	cin >> x >> y;



	if (a <= x && b <= y)
	{
		res = true;
	}
	 if (b <= x && a <= y)
	{
		 res = true;
	}
	 if (b <= x && c <= y)
	 {
		 res = true;
	 }
	 if (c <= x && b <= y)
	 {
		 res = true;
	 }
	 if (a <= x && c <= y)
	 {
		 res = true;
	 }
	 if (c <= x && a <= y)
	 {
		 res = true;
	 }


	 if (res) {
		 cout << "÷еглина з заданими розмiрами пройде в отвiр";
	 }
	else
	{
		cout << "÷еглина з заданими розмiрами не пройде в отвiр";
	}
	return 0;
}