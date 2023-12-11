#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>

using namespace std;

class Node
{
	public :
	string name;
	vector<Node*> children;
	Node* parent;
	Node(const string& nodename) :name(nodename) {};

};
