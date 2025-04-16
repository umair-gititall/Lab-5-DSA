#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue{
	T* arr;
	int maxSize, currentSize;
public:
	Queue(int max) : maxSize(max), currentSize(0)
	{
		if (maxSize <= 0)
			maxSize = 10;
		arr = new T[maxSize]{};
	}
	void display()
	{
		for (int i = 0; i < currentSize; i++)
			cout << arr[i] << endl;
		cout << endl;
	}
	bool isFull()  { return (currentSize == maxSize); }
	bool isEmpty()  { return (currentSize == 0); }
	void enqueue(T data) 
	{
		if (!isFull())
			arr[currentSize++] = data;
	}
	T dequeue() 
	{
		if (!isEmpty())
		{
			T temp = arr[0];
			T var{};
			for (int i = 0; i < currentSize - 1; i++)
				arr[i] = arr[i + 1];
			arr[currentSize--] = var;

			return temp;
		}
	}
	T peek()  { return arr[0]; }
};

template <class T>
class circularQueue {
	T* arr;
	int maxSize, front, rear;
public:
	circularQueue(int max) :maxSize(max), front(-1), rear(-1)
	{
		if (maxSize <= 0)
			maxSize = 10;
		arr = new T[maxSize];
	}
	bool isFull()
	{
		if (front == 0 && rear == maxSize - 1)
			return true;
		if (front == (rear + 1) % maxSize)
			return true;
		return false;
	}
	bool isEmpty()
	{
		if (front == -1)
			return true;
		return false;
	}
	void enqueue(T val)
	{
		if (!isFull())
		{
			if (front == -1)
				front = 0;
			rear = (rear + 1) % maxSize;
			arr[rear] = val;
		}
	}
	T dequeue()
	{
		T element;
		if (!isEmpty())
		{
			element = arr[front];
			if (front == rear)
				front = rear = -1;
			else
				front = (front + 1) % maxSize;
		}
		return element;
	}
	T peek()
	{
		T temp;
		if(front != -1)
			return arr[front];
		return temp;
	}
	T peekLast()
	{
		T temp;
		if(rear != -1)
			return arr[rear];
		return temp;
	}
	void display()
	{
		for (int i = front; i <= rear; i++)
			cout << arr[i];
		cout << endl;
	}
	~circularQueue() { delete[] arr; }
};