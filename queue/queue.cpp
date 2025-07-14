#include<iostream>
#include<cstdlib>

using namespace std;
static const int MAX = 100;

class queue
{
private:
	int myQueue[MAX];
	int front, rear;
public:
	queue()
	{
		myQueue[MAX - 1] = { 0 };
		front = -1;
		rear = -1;
	}

	bool isEmpty() const;
	bool isFull() const;
	void enqueue(int value);
	int dequeue();
	void display();
};

bool queue::isEmpty() const
{
	if(front == -1)
		return true;
	return false;
}

bool queue::isFull() const
{
	if(rear == MAX - 1)
		return true;
	return false;
}

void queue::enqueue(int value)
{
	if (isFull())
	{
		cout << "Queue is full! Cannot enqueue " << value << endl;
		return;
	}
	if (front == -1)
		front = 0;
	myQueue[++rear] = value;
}

int queue::dequeue()
{
	int element = 0;
	if(isEmpty())
		{
		cout << "Queue is empty! Cannot dequeue." << endl;
		return -1; // Indicating an error
	}
	element = myQueue[front];
	if (front >= rear)
	{
		front = -1;
		rear = -1;
	}
	else
		front++;
	return element;

}

void queue::display()
{
	if (isEmpty())
	{
		cout << "Queue is empty!" << endl;
		return;
	}
	cout << "Queue elements: ";
	for (int i = front; i <= rear; i++)
	{
		cout << myQueue[i] << " ";
	}
	cout << endl;
}

int main()
{
	queue q;
	cout << "Enter up to 100 elements to enqueue into the queue:" << endl;
	cout << "Enter a negative number to stop inputting elements." << endl;
	int value = 0;
	for (int i = 0; i < 100; i++)
	{
		cin >> value;
		if (value < 0) // Assuming negative value indicates end of input
			break;
		q.enqueue(value);
	}
	q.display();

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.display();

	return 0;
}