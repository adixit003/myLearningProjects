#include<iostream>
#include<cstdlib>

using namespace std;

static const int MAX = 10;

class stack {
private:
	int myStack[MAX];
	int top;

public:
	stack()
	{
		myStack[MAX - 1] = { 0 };
		top = -1;
	}
	bool isEmpty() const;
	bool isFull() const;
	void push(int value);
	int pop();
	void print();
};

bool stack::isEmpty() const
{
	if (top == -1)
		return true;

	return false;
}

bool stack::isFull() const
{
	if (top == MAX - 1)
		return true;
	return false;
}

void stack::push(int value)
{
	if(isFull())
		cout << "stack is full!" << endl;

	myStack[++top] = value;
}

int stack::pop()
{
	if (isEmpty())
	{
		cout << "stack is empty!" << endl;
		return -1;
	}
	return myStack[top--];
}

void stack::print()
{
	if (isEmpty())
	{
		cout << "stack is empty!" << endl;
		return;
	}
    for(int i = 0; i <= top; ++i)
		cout << myStack[i] << " ";

	cout << endl;

}

int main()
{
	stack s;
	cout << "Enter elemets to push onto the stack:" << endl;
	cout << "max allowed elements: " << MAX << endl;
	int value;
	for (int i = 0; i < MAX; ++i)
	{
		cin >> value;
		s.push(value);
	}

	s.print();

	for (int i = 0; i < 5; ++i)
	{
		cout << "pop: " << s.pop() << endl;
	}	
	s.print();
	return 0;
}



