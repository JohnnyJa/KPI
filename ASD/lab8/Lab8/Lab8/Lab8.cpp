
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

double** generate_matrix(int, int);

double generate_random_double();

double* form_array_of_average(double**, int, int);

double find_avarage(double*, int);

void swap(double&, double&);

void sort_array(double*, int);

void delete_matrix(double**, int);

void delete_array(double*);

void output_matrix(double**, int, int);

void output_array(double*, int);

void output_line();


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "");

	const int width = 6, height = 5;

	//Генеруємо матрицю
	cout << "Матриця: \n";

	double** matrix = generate_matrix(width, height);

	output_matrix(matrix, width, height);


	output_line();

	//формуємо массив середніх значень
	cout << "\nНесортований масив середнiх значень рядкiв: \n";

	double* array_of_avarage = form_array_of_average(matrix, width, height);

	output_array(array_of_avarage, width);


	output_line();
	
	//Сортуємо массив
	cout << "\nВiдсортований масив середнiх значень рядкiв: \n";

	sort_array(array_of_avarage, width);

	output_array(array_of_avarage, width);


	output_line();


	//Очищаємо пам'ять 
	delete_array(array_of_avarage);
	delete_matrix(matrix, height);

	return 1;
}

//Рішення задачі

double* form_array_of_average(double** matrix, int width, int height)
{
	double* array_of_avarage = new double [width];
	for (int i = 0; i < width; ++i)
	{
		array_of_avarage[i] = find_avarage(matrix[i], height);
	}
	return array_of_avarage;
}

double find_avarage(double* some_array, int size)
{
	double sum = 0, avarage;
	for (int i = 0; i < size; ++i) sum += some_array[i];
	avarage = sum / size;
	return avarage;
}

void sort_array(double* some_array, int size)
{
	for (int i = 0; i < size - 1; ++i)
		for (int j = 0; j < size - 1; ++j)
			if (some_array[j] < some_array[j + 1]) swap(some_array[j], some_array[j+1]);
}

void swap(double& a, double& b)
{
	double save = a;
	a = b;
	b = save;
}











// Робота з массивами та матрицями

void output_line()
{
	cout << "\n-----------------------------------------------------\n";
}

void output_array(double* some_array, int size)
{
	for (int i = 0; i < size; ++i)
			cout << setw(10) << some_array[i];
}

void delete_array(double* some_array)
{
	delete some_array;
}


double generate_random_double() 
{
	return double(int((double(rand() % 2001 - 1000) / double(rand() % 11 + 1)) * 1000)) / 1000;		// Формуємо випадкове дійсне число від -10000 до 10000 з точністю до трьох знаків після коми
}


double** generate_matrix(int width, int height)
{
	double** matrix = new double* [width];
	for (int i = 0; i < width; ++i) matrix[i] = new double[height];


	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			matrix[i][j] = generate_random_double();

		}
	}
	return matrix;
}

void output_matrix(double** matrix, int width, int height)
{
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
			cout << setw(10) << matrix[i][j];
		cout << '\n';
	}
}

void delete_matrix(double** matrix, int height)
{
	for (int i = 0; i < height; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}