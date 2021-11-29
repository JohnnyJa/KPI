
#include <iostream>

using namespace std;

double product(double, double, double);

int main()
{
	double first_value = 64, last_value = 1, step = 4, result;
	result = product(first_value, last_value, step);
	cout << "Product is: " << result;
	return 1;
}

double product(double relevant_value, double last_value, double step)
{
	if (relevant_value == last_value) return last_value;								//Термінальна гілка рекурсії: 
																					//Повертаємо значення останнього елементу прогресії
	
	else return product((relevant_value / step), last_value, step) * relevant_value;		//Рекурсивна гілка рекурсії:
																					//Повертаємо значення добутку всіх наступних елементів прогресії 
																					// * на теперішній аргумент
}