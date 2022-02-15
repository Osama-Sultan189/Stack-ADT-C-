#include<iostream>
using namespace std;
template <class type>
class stack
{
private:
	int top;
	int size;
	type* stackArray;
	void resize()
	{
		if (top + 1 == size)
			size *= 2;
		else if (top + 1 < (size / 4))
			size /= 2;
		else
			size = size;
	}
public:
	stack()
	{
		top = -1;
		size = 0;
		stackArray = new type[size];
	}
	stack(int s)
	{
		top = -1;
		size = s;
		stackArray = new type[size];
	}
	bool isFull()
	{
		if (top == size - 1)
			return 1;
		else
			return 0;
	}
	bool isEmpty() 
	{
		if (top == -1)
			return 1;
		else
			return 0;
	}
	void push(type element)
	{
		if (this->isFull() == false)
		{
			stackArray[++top] = element;
		}
		else
			this->resize();
	}
	void pop()
	{
		cout << top << " ";
		if (this->isEmpty() == false)
		{
			cout << stackArray[top--];
			if (top + 1 < size / 4)
			{
				this->resize();
			}
		}
		else
		{
			cout << "Stack is empty .";
		}
	}
	int getTopValue()
	{
		return stackArray[top];
	}
	int getSize()
	{
		return size;
	}
};