// ADS_2023_CA2_Nojus_Matusevicius.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string myText;

    ifstream MyReadFile("sampleXML.txt");
    if (!MyReadFile.is_open()) {
        cerr << "Error opening the file" << endl;
        return 1;
        }

        while (getline(MyReadFile, myText)) {
            // Output the text from the file
            cout << myText << endl;
        }
        MyReadFile.close();
        return 0;
}
