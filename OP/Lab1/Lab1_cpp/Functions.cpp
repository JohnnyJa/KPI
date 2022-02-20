#include "Functions.h"
#include <iostream>
#include <vector>


void writeFile(fstream* file, string output)
{
	if (!*file)
		cout << "Cannot open the file to write\n";
	*file << output;
}
void writeFile(ofstream* file, string output)
{
	if (!*file)
		cout << "Cannot open the file to write\n";
	*file << output;
}


string readFile(fstream* file)
{
	string input;
	if (!*file)
		cout << "Cannot open the file to read\n";
	cin.ignore();
	getline(*file, input, (char)EOF);
	return input;
}

string getInput()
{
	string input;
	getline(cin, input, (char)19);
	input.erase(input.begin());
	return input;
}

vector <string> findString(string input)
{
	vector<string> arr;
	string eol = "\n";
	size_t prev = 0, next, delta = eol.length();

	while ((next = input.find(eol, prev)) != string::npos)
	{
		arr.push_back(input.substr(prev, next - prev));
		prev = next + delta;
	}
	arr.push_back(input.substr(prev));

	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i] == "")
			arr.erase(arr.begin() + i);
	}
	return arr;
}

string processInput(string input)
{
	string output = "";
	vector<string> text = findString(input);
	for (size_t i = 0; i < text.size(); i++)
	{
		if (text[i][0] != '#')
			output += text[i] + '\n';
	}
	for (size_t i = 0; i < text.size(); i++)
	{
		if (text[i][0] == '#') 
		{
			text[i].replace(0, 1, "");
			text[i].insert(text[i].size() / 2, "!");
			output = output + text[i] + '\n';
		}
	}
	return output;
}


