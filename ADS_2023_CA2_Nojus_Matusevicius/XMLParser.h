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
	T filename;  // filename
	string XMLContent; // string to hold the content of the file

public:
	XMLParser(const T& filename); 
	T getFilename() const; // returns the filename
	bool load();          // loads the file into a string
	bool hasRoot()const;  // checks if the file has a root tag
	bool hasClosingTags()const; // checks if the file has closing tags
	bool nestingIsValid()const; // checks if the file has valid nesting

};

template <class T>
XMLParser<T>::XMLParser(const T& filename)
{
	//set the filename
	this->filename = filename;  // set the filename
}

template<class T>
T XMLParser<T>::getFilename() const
{
	return this->filename; // return the filename
}


template <class T>
bool XMLParser<T>::load()
{
	ifstream fileStream(filename);

if (!fileStream.is_open())
	{
		cout << "Error opening file:" << filename << endl; // if the file is not open output error message
		return false;
	}

	XMLContent.assign((istreambuf_iterator<char>(fileStream)), istreambuf_iterator<char>());  // reading the file into a string
	fileStream.close();  // closing the file

	

    cout << XMLContent << endl;// print content of file
	return true; 
}


template <class T>
bool XMLParser<T>::hasRoot() const {
	size_t openingRootTag = XMLContent.find("<dir>");
	size_t closingRootTag = XMLContent.find("</dir>"); // finding the opening and closing root tags

	if (openingRootTag != string::npos && closingRootTag != string::npos && openingRootTag < closingRootTag)  // finding that there are a opening and closing dir tag and opening is before the clsoing
	{
		string rootContent = XMLContent.substr(openingRootTag + 5, closingRootTag - openingRootTag - 5); // get the content between the dir tags and ignoring the tags themselves
		size_t nestedDirTag = rootContent.find("<dir>");  // seeing if there is another dir tag between the other dir tags
		return (nestedDirTag != string::npos); // if nestedDirTag is not not present, then there is a dir tags within the root tags
	}
	else
	{
		return false;
	}
}

	template <class T>
	bool XMLParser<T>::hasClosingTags() const {

		size_t openingTagCount = count(XMLContent.begin(),XMLContent.end(),'<'); // count the number of opening tags
		size_t closingTagCount = count(XMLContent.begin(), XMLContent.end(), '>'); // count the number of closing tags
		size_t closingDashTagCount = count(XMLContent.begin(), XMLContent.end(), '/'); // count the number of closing tags with a slash


		return(openingTagCount == closingTagCount && closingDashTagCount * 2 == closingTagCount); // if the number of opening tags is equal to the number of closing tags and the number of closing tags with a slash is half the number of closing tags, then there are closing tags
	}

	template <class T>
	bool XMLParser<T>::nestingIsValid() const {

		return false;
	}
	

