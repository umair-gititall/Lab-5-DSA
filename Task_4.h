#pragma once
#include <iostream>
using namespace std;


template <class T>
class stack
{
	T* arr;
	int currentsize, maxsize;
public:
	stack(int max) :maxsize(max), currentsize(0)
	{
		if (maxsize <= 0)
			maxsize = 10;
		arr = new T[maxsize]{};
	}
	bool isempty() { return currentsize == 0; }
	bool isfull() { return currentsize == maxsize; }
	bool find(T val)
	{
		for (int i = 0; i < currentsize; i++)
			if (arr[i] == val)
				return true;
		return false;
	}
	void emptystack() { currentsize = 0; }
	void display()
	{
		cout << "Text Editor :: ";
		for (int i = 0; i < currentsize; i++)
			cout << arr[i];
		cout << endl;
	}
	void push(T val)
	{
		if (!isfull())
			arr[currentsize++] = val;
		else
			cout << "Stack Full" << endl;
	}
	T pop()
	{
		if (!isempty())
			return arr[--currentsize];
		return NULL;
	}
	~stack() { delete[] arr; }
};