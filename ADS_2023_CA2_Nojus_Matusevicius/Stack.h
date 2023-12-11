#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class Stack {
public:
	Stack(){}
	~Stack(){} 
	void push(T data) {
		stack.push_back(data);
	}
	T pop() {
		T data = stack.back();
		stack.pop_back();
		return data;
	}
	T peek() {
		return stack.back();
	}
	bool isEmpty() {
		return stack.empty();
	}
	int size() {
		return stack.size();
	}
	private:
		vector<T> stack;
};