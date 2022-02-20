#pragma once
#include <fstream>
#include <string>


using namespace std;


void writeFile(fstream* file, string output);
void writeFile(ofstream* file, string output);

string readFile(fstream* file);

string getInput();

string processInput(string input);



