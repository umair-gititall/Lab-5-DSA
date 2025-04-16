#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue {
protected:
	T* arr;
	int maxSize, currentSize;
public:
	Queue(int maxQueueSize) :maxSize(maxQueueSize), currentSize(0)
	{
		if (maxSize <= 0)
			maxSize = 10;
		arr = new T[maxSize]{};
	}
	virtual bool isFull() = 0;
	virtual bool isEmpty() = 0;
	virtual void enqueue(T data) = 0;
	virtual  T dequeue() = 0;
	virtual T peek() = 0;
	virtual ~Queue() { delete[] arr; }
};

template <typename T>
class MyQueue : public Queue <T> {
public:
	MyQueue(int maxQueueSize) :Queue <T>(maxQueueSize) {}
	void display()
	{
		for (int i = 0; i < this->currentSize; i++)
			cout << this->arr[i] << endl;
		cout << endl;
	}
	bool isFull() override { return (this->currentSize == this->maxSize); }
	bool isEmpty() override { return (this->currentSize == 0); }
	void enqueue(T data) override
	{
		if (!isFull())
			this->arr[(this->currentSize)++] = data;
	}
	T dequeue() override
	{
		if (!isEmpty())
		{
			T temp = this->arr[0];

			for (int i = 0; i < this->currentSize - 1; i++)
				this->arr[i] = this->arr[i + 1];
			this->currentSize--;

			return temp;
		}
	}
	T peek() override { return this->arr[0]; }
};