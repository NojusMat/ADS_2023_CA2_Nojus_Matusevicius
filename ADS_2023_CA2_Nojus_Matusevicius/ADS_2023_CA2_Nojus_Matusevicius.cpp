// ADS_2023_CA2_Nojus_Matusevicius.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "XMLParser.h"
#include <string>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;



int main()
{
	XMLParser<string> parser("myfile.xml");
	bool result = parser.load();
if (result)
	{
		cout << "File loaded successfully" << endl;

	}
	else
	{
		cout << "File not loaded" << endl;
	}

return 0;
}

