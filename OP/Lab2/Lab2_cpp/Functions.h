#pragma once
#include <string>


using namespace std;

struct TProduct
{
	string ProductName,
		   ReleaseDate,
		   ExpirationDate;
};


void WriteNewData();

void AddData();

void CheckInfo(string path);

void EditDate();

void CheckDate();

void ProcessFiles();



