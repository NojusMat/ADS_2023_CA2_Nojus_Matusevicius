#pragma once
#include <iostream>
#include "XMLParser.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

using namespace std;

class Node
{
public:
	string name;
	vector<Node*> children;
	Node* parent;
	map <string, string> attributes;
	//string content;
	//Node() : parent(nullptr) {}
//	Node(string name) : name(name), parent(nullptr) {}

};
