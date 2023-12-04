#pragma once
#include "DList.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
class XMLParser
{
private:
	T filename;

public:
	XMLParser(const T& filename);
	T getFilename() const;
	bool load();

};

template <class T>
XMLParser<T>::XMLParser(const T& filename)
{
	//set the filename
	this->filename = filename;
}

template<class T>
T XMLParser<T>::getFilename() const
{
	return this->filename;
}


template <class T>
bool XMLParser<T>::load()
{
	ifstream fileStream(filename);
if (!fileStream.is_open())
	{
		return false;
	}
	string xmlContent((istreambuf_iterator<char>(fileStream)), istreambuf_iterator<char>());

	fileStream.close();
    cout << xmlContent << endl;
	return true;
}
