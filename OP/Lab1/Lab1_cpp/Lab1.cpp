#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Functions.h"

using namespace std;

int main()
{
	fstream inFile;
	cout << "If you want to clear file enter (0), if you want to append enter (1): ";
	int f;
	cin >> f;
	if (f == 0)
		inFile.open("input.txt", ios::out);
	else
		inFile.open("input.txt", ios::app);
	
	writeFile(&inFile, getInput());
	inFile.close();

	inFile.open("input.txt", ios::in);
	string input = readFile(&inFile);
	cout << "\ninput.txt:\n\n" << input << '\n';
	inFile.close();
	

	ofstream outFile("output.txt");
	string output = processInput(input);
	writeFile(&outFile, output);
	cout << "\noutput.txt:\n\n" << output;
	outFile.close();

	return 1;
}

