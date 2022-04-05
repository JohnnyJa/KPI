#include "Functions.h"
#include <fstream>
#include <iostream>
#include <vector>



void WriteNewData()
{
	string path = "AllProductList.dat";
	TProduct NewList;
	int ProductsNum;
	ofstream OutFile(path, ios::binary | ios::out);
	cout << "Input number of products: ";
	cin >> ProductsNum;
	cin.ignore();
	cout << "\n---------------------------------------------------------------------\n";
	for (size_t i = 0; i < ProductsNum; i++)
	{
		cout << "Input product name:\n";
		getline(cin, NewList.ProductName);
		cout << "Input release date:\n";
		getline(cin, NewList.ReleaseDate);
		cout << "Input expiration date:\n";
		getline(cin, NewList.ExpirationDate);
		OutFile << NewList.ProductName << ' ' << NewList.ReleaseDate << ' ' << NewList.ExpirationDate;
		cout << "\n---------------------------------------------------------------------\n";
	}
	OutFile.close();
}

void AddData()
{
	string path = "AllProductList.dat";
	TProduct NewList;
	int ProductsNum;
	ofstream OutFile(path, ios::binary | ios::app);
	cout << "Input number of products: ";
	cin >> ProductsNum;
	cin.ignore();
	cout << "\n---------------------------------------------------------------------\n";
	for (size_t i = 0; i < ProductsNum; i++)
	{
		cout << "Input product name:\n";
		getline(cin, NewList.ProductName);
		cout << "Input release date:\n";
		getline(cin, NewList.ReleaseDate);
		cout << "Input expiration date:\n";
		getline(cin, NewList.ExpirationDate);
		OutFile << NewList.ProductName << ' ' << NewList.ReleaseDate << ' ' << NewList.ExpirationDate;
		cout << "\n---------------------------------------------------------------------\n";
	}
	OutFile.close();
}

void CheckInfo(string path)
{
	cout << "\n---------------------------------------------------------------------\n";
	ifstream File(path, ios::binary);
	TProduct List;

	if (!File)
		cout << "Cannot open the file to read\n";

	while (File >> List.ProductName >> List.ReleaseDate >> List.ExpirationDate)
	{
		cout << "Product name: " << List.ProductName << "; Release date: " << List.ReleaseDate << "; Expiration date: " << List.ExpirationDate << "; \n";
	}
	File.close();
	cout << "---------------------------------------------------------------------\n\n";
}

void EditDate()
{
	ofstream File("Date.dat", ios::binary | ios::out);
	string date;
	cout << "\nEnter date: ";
	cin >> date;
	File << date;
	cout << '\n';
	File.close();
}

void CheckDate()
{
	ifstream File("Date.dat", ios::binary);
	string date;
	File >> date;
	cout << "\nCurrent date is: " << date <<"\n\n";
	File.close();
}

int StrToJDN(string Date)
{
	
	int Day = stoi(Date.substr(0, 2));
	int Month = stoi(Date.substr(4, 2));
	int Year = stoi(Date.substr(6));
	int	a = (14 - Month) / 12;
	int y = Year + 4800 - a;
	int m = Month + 12 * a - 3;
	return Day + (int)((153 * m + 2) / 5) + 365 * y + (int)(y / 4) - (int)(y / 100) + (int)(y / 400) - 32045;
}


void ProcessFiles()
{
	ifstream DateFile("Date.dat", ios::binary);
	string DateStr;
	DateFile >> DateStr;
	DateFile.close();

	int CurrDate = StrToJDN(DateStr);
	ifstream AllPrFile("AllProductList.dat", ios::binary);
	ofstream LTPrFile("Long-termStorageProductsList.dat", ios::binary| ios::out);
	ofstream PerPrFile("PerishableProductsList.dat", ios::binary| ios::out);
	TProduct List;

	while (AllPrFile >> List.ProductName >> List.ReleaseDate >> List.ExpirationDate)
	{
		int ExpDate = StrToJDN(List.ExpirationDate);
		int RelDate = StrToJDN(List.ReleaseDate);
		if (ExpDate>=CurrDate)
		{
			if (ExpDate - RelDate <= 5)
			{
				PerPrFile << List.ProductName << ' ' << List.ReleaseDate << ' ' << List.ExpirationDate << '\n';
			}
			else
			{
				LTPrFile << List.ProductName << ' ' << List.ReleaseDate << ' ' << List.ExpirationDate << '\n';
			}
		}
	}
}