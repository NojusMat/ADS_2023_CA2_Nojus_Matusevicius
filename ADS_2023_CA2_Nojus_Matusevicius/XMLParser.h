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
	T file;

public:
	XMLParser(const T& filename);
	T getFilename() const;
	bool load();

};

template <class T>
XMLParser<T>::XMLParser(const T& filename)
{
	//set the filename
	this->file = filename;
}

template<class T>
T XMLParser<T>::getFilename() const
{
	return this->file;
}

template <class T>
bool XMLParser<T>::load()
{
	return true;
}
