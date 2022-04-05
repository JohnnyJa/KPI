#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;



int main()
{
	bool flag = true;
	while (flag) {
		int b;
		cout << "What do you want to do?\n 1 - Create new data file\n 2 - Edit data file\n 3 - Check info \n 4 - Edit date\n";
		cin >> b;
		switch (b)
		{
		case 1:
			WriteNewData();
			ProcessFiles();
			break;
		case 2:
			AddData();
			ProcessFiles();
			break;
		case 3:
			cout << "\nWhat info do yu want to check?\n 1 - All product list\n 2 - Perishable products list\n 3 - Long-term storage products list\n 4 - Date\n";
			int a;
			cin >> a;
			switch (a)
			{
			case 1:
				cout << "\nAll Product List: \n";
				CheckInfo("AllProductList.dat");
				break;
			case 2:
				cout << "\nPerishable Products List: \n";
				CheckInfo("PerishableProductsList.dat");
				break;
			case 3:
				cout << "\nLong-term Storage Products List: \n";
				CheckInfo("Long-termStorageProductsList.dat");
				break;
			case 4:
				CheckDate();
				break;
			default:
				cout << "Error: Wrong input";
				break;
			}
			break;
			case 4:
				EditDate();
				ProcessFiles();
				break;
		default:
			cout << "Work stopped.";
			flag = false;
			break;
		}
		
	}

	return 0;
}
