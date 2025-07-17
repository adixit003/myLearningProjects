#include<iostream>
#include<cstdlib>

using namespace std;

static const int maxSize = 5;

class circularQueue
{
private:
	int front;
	int rear;
	int mycQueue[maxSize];

public:
	circularQueue()
	{
		mycQueue[maxSize - 1] = { 0 };
		front = -1;
		rear = -1;
	}

	bool isEmpty() const;
	bool isFull() const;
	void enqueue(int element);
	bool dequeue();
	void display();
};

bool circularQueue::isEmpty() const
{
	if (front == -1)
		return true;

	return false;
}

bool circularQueue::isFull() const
{
	if ((front == 0) && (rear == maxSize - 1))
		return true;

	if (front == ((rear + 1) % maxSize))
		return true;

	return false;
}

void circularQueue::enqueue(int element)
{
	if (isFull())
	{
		cout << "circular queue is full!" << endl;
		return;
	}

	if (front == -1)
		front = 0;

	rear = (rear + 1) % maxSize;
	mycQueue[rear] = element;
	cout << element << " is inserted at " << rear << endl;
}

bool circularQueue::dequeue() 
{
	int element = 0;
	if (isEmpty())
	{
		cout << "circular queue is empty!" << endl;
		return -1;
	}

	element = mycQueue[front];
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
		front = (front + 1) % maxSize;
	
	return element;

}

void circularQueue::display()
{
	if (isEmpty())
	{
		cout << "circular queue is Empty!" << endl;
		return;
	}
	for (int i = front; i <= rear; ++i)
		cout << mycQueue[i] << " ";

	cout << endl;
}

int main()
{
	circularQueue cq;

	cq.enqueue(11);
	cq.enqueue(12);
	cq.enqueue(13);
	cq.enqueue(14);
	cq.enqueue(15);

	cq.display();

	cout << "Deleted element is: " << cq.dequeue() << endl;

	cq.enqueue(16);
	cq.display();
	return 0;
}