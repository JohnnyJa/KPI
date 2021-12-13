#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

int** generate_matrix(int);

int max_in_zone(int, int, int**, int);

void process_matrix(int**, int);

void output_matrix(int**, int);

void delete_matrix(int**, int);

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));

    int size;
    int** matrix;

    cout << "Введiть розмiри матрицi:\n";
    cin >> size;

    matrix = generate_matrix(size);
    cout << "Матриця A: \n";
    output_matrix(matrix, size);

    process_matrix(matrix, size);

    cout << "Матриця В: \n";
    output_matrix(matrix, size);

    delete_matrix(matrix, size);

    return 1;

}

int** generate_matrix(int size)
{
    int** matrix = new int* [size];

    

    for (int i = 0; i < size; ++i) matrix[i] = new int[size];

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            matrix[i][j] = rand() % 301;
        }

    }
    return matrix;
}

int max_in_zone(int row, int column, int** matrix, int size)
{
    int first_j_in_row = column, last_j_in_row = column, max = matrix[row][column];
    for (int i = row; i < size; ++i)
    {
        for (int j = first_j_in_row; j <= last_j_in_row; ++j)
        {
            if (max < matrix[i][j]) max = matrix[i][j];
        }


        if (first_j_in_row - 1 >= 0) first_j_in_row--;

        if (last_j_in_row + 1 < size) last_j_in_row++;
    }
    return max;
}

void process_matrix(int** matrix, int size)
{
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] = max_in_zone(i, j, matrix, size);

}

void output_matrix(int** matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            cout << setw(5) << matrix[i][j];
        cout << '\n';
    }
}

void delete_matrix(int** matrix, int size)
{
    for (int i = 0; i < size; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}