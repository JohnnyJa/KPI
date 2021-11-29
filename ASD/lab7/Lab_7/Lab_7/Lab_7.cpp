// Lab_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

void initialize_first_array(char [], int);

void initialize_second_array(char [], int);

int initialize_third_array(char [], char [], char [], int);

char product(char[], int);

int main()
{
    const int size = 10;
    char first_array[size], second_array[size], third_array[size];
    int  third_array_size;  
    
    cout << "First array:\n";
    initialize_first_array(first_array , size);

    cout << "Second array:\n";
    initialize_second_array(second_array, size);

    cout << "Third array:\n";
    third_array_size = initialize_third_array(first_array, second_array, third_array, size);

    char result = product(third_array, third_array_size);

    cout << "Result: " << result;

    return 1;
}

void initialize_first_array(char some_array[], int array_size)
{
    for (int i = 0; i < array_size; ++i) 
    {
        some_array[i] = 5 * i + 30;
        cout << setw(3) << some_array[i];
    }
    cout << '\n';
}

void initialize_second_array(char some_array[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
    {
        some_array[i] = 60 - 5 * i;
        cout << setw(3) << some_array[i];
    }
    cout << '\n';
}

int initialize_third_array(char first_array[], char second_array[], char result_array[], int array_size)
{
    int result_array_size = 0;
    for (int i = 0; i < array_size; ++i)                                                                    //алгоритм пошуку однакових елементів 1 та 2 масиву та додавання їх до 3 массиву
    {
        for (int j = 0; j < array_size; ++j) 
        {
            if(first_array[i] == second_array[j])
            {
                result_array[result_array_size] = first_array[i];
                cout << setw(3) << result_array[result_array_size];
                result_array_size++;
                continue;
            }
        }
    }
    cout << '\n';
    return result_array_size;
}

char product(char some_array[], int some_array_size)
{
    char product = some_array[0];
    for (int i = 1; i < some_array_size; ++i)
    {
        if (some_array[i] < 40) 
        {
            product *= some_array[i];
        }
    }
    return product;
}
