#pragma once
#include "DList.h"
#include "Tree.h"
#include "TreeIterator.h"
#include "Node.h"
#include "Stack.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

template <class T>
class XMLParser
{
public:
	T filename;  // filename
	XMLParser(const T& filename); 
	T getFilename() const; // returns the filename
	bool load();          // loads the file into a string
	bool hasRoot()const;  // checks if the file has a root tag
	bool hasClosingTags()const; // checks if the file has closing tags
	bool nestingIsValid()const; // checks if the file has valid nesting
	bool hasOpeningTags()const; // checks if the file has opening tags
	void buildTree();

	private:
		string XMLContent; // string to hold the content of the file
};

template <class T>
void XMLParser<T>::buildTree()
{
	stack<Node*> nodeStack; // stack to hold the nodes
	Node* root = new Node(); // creating a new node
	root->name = "root"; // setting the name of the node to root
	nodeStack.push(root); // pushing the node onto the stack

	stringstream ss(XMLContent); // creating a string stream to read the content of the file
	string line; // string to hold the line of the file
	while (getline(ss, line)) // while there are lines to read
	{
		if (line.find("<") != string::npos && line.find(">") != string::npos) // if there are opening and closing tags
		{
			string tagName = line.substr(line.find("<") + 1, line.find(">") - line.find("<") - 1); // get the name of the tag
			if (tagName.find("/") != string::npos) // if the tag is a closing tag
			{
				tagName = tagName.substr(tagName.find("/") + 1); // get the name of the tag
				if (nodeStack.top()->name == tagName) // if the top of the stack is the same as the tag name
				{
					nodeStack.pop(); // pop the top of the stack
				}
				else
				{
					cout << "Error: Invalid nesting" << endl; 
					return;
				}
			}
			else
			{
				//Node* newNode = new Node(); // creating a new node
				//newNode->name = tagName; // setting the name of the node to the tag name
				//nodeStack.top()->children.push_back(newNode); // adding the node to the children of the top of the stack
				//newNode->parent = nodeStack.top(); // setting the parent of the node to the top of the stack
				//nodeStack.push(newNode); // pushing the node onto the stack
			}
		}
		else
		{
			//nodeStack.top()->content = line; // setting the content of the node to the line
		}
	}
}

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
	size_t openingRootTag = XMLContent.find("<");
	size_t closingRootTag = XMLContent.find(">"); // finding the opening and closing root tags

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

		stack <char> tagStack; // stack to hold the tags
		for (char c : XMLContent)
		{
			if (c == '<')
			{
				tagStack.push(c); // if the character is a opening tag, push it onto the stack
			}
			else if (c == '>')
			{
				if (!tagStack.empty() && tagStack.top() == '<') // if the character is a closing tag, pop the opening tag off the stack
				{
					tagStack.pop();
				}
				else
				{
					return false; // if the stack is empty or the top of the stack is not a opening tag, return false
				}
			}
		}
			return tagStack.empty(); // if the stack is empty, return true
	}

	template <class T>  // this is the same as the hasclosing tags but i just want to show that i am testing for it 
	bool XMLParser<T>::hasOpeningTags() const{

		stack <char> tagStack; 
		for (char c : XMLContent)
		{
			if (c == '<')
			{
				tagStack.push(c); 
			}
			else if (c == '>')
			{
				if (!tagStack.empty() && tagStack.top() == '<') 
				{
					tagStack.pop();
				}
				else
				{
					return false; 
				}
			}
		}
		return tagStack.empty(); 

	}
		


	template <class T>
	bool XMLParser<T>::nestingIsValid() const {
		{
			stack<char> tagStack; // stack to hold the tags
			int depth = 0; // depth of the tags
			for (char c : XMLContent)
			{
				if (c == '<')
				{
					tagStack.push(c); // if the character is a opening tag, push it onto the stack
					depth++;
				}
				else if (c == '>')
				{
					if (!tagStack.empty() && tagStack.top() == '<') // if the character is a closing tag, pop the opening tag off the stack
					{
						tagStack.pop();
						depth--;
					}
					else
					{
						return false; // if the stack is empty or the top of the stack is not a opening tag, return false
					}
					if (depth < 0)
					{
						return false;
					}
				}
			}
			return tagStack.empty() && depth == 0; // if the stack is empty, return true
		}
	}
	

	
	

