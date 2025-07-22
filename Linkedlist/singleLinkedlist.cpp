#include<iostream>
#include<cstdlib>

using namespace std;

struct slinklist
{
	int data;
	struct slinklist* next;
};

void insertAtBeginning(struct slinklist** head, int newData)
{
	struct slinklist *newNode = (struct slinklist *)malloc(sizeof(struct slinklist));

	if (newNode == NULL)
	{
		cout << "newNode not initilized" << endl;
		return;
	}

	newNode->data = newData;
	newNode->next = (*head);

	(*head) = newNode;
}

void insertAtEnd(struct slinklist** head, int newData)
{
	struct slinklist* newNode = (struct slinklist*)malloc(sizeof(struct slinklist));
	struct slinklist* temp = *head;
	if (newNode == NULL)
	{
		cout << "not initilized" << endl;
		return;
	}
	newNode->data = newData;
	newNode->next = NULL;

	if (*head == NULL) 
	{
		*head = newNode;
		return;
	}
	
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;

}

void insertAfter(struct slinklist* prevNode, int newData)
{
	if (prevNode == NULL)
	{
		cout << "prevoius node is Null!" << endl;
		return;
	}

	struct slinklist* newNode = (struct slinklist*)malloc(sizeof(struct slinklist));
	if (newNode == NULL)
	{
		cout << "Not iniltlized" << endl;
		return;
	}
	newNode->data = newData;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void deleteNodewithKey(struct slinklist** head, int key)
{
	struct slinklist* temp = *head;
	struct slinklist* prev = nullptr;

	if (temp != NULL && temp->data == key)
	{
		*head = temp->next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return;

	prev->next = temp->next;
	free(temp);
}

bool searchNode(struct slinklist** head, int key)
{
	struct slinklist* temp = *head;
	while (temp != NULL)
	{
		if (temp->data == key)
			return true;
		temp = temp->next;
	}
	return false;
}

void sortLinklist(struct slinklist** head)
{
	struct slinklist* current = *head, *index = NULL;
	int temp = 0;

	if (current == NULL)
		return;
	else
	{
		while (current != NULL)
		{
			index = current->next;
			while (index != NULL)
			{
				if (current->data > index->data)
				{
					temp = current->data;
					current->data = index->data;
					index->data = temp;
				}
				index = index->next;
			}
			current = current->next;
		}
	}
}

void printLinklist(struct slinklist* head)
{
	struct slinklist* current = head;
	while (current != NULL)
	{
		cout << current->data;
		current = current->next;
		cout << "->";
	}
	cout << "NULL";
	cout << endl;
}

int main()
{
	struct slinklist* head = NULL;

	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 13);
	insertAtBeginning(&head, 15);
	insertAtBeginning(&head, 17);
	printLinklist(head);
	insertAfter(head, 2);
	printLinklist(head);
	insertAtEnd(&head, 19);
	printLinklist(head);

	deleteNodewithKey(&head, 15);
	printLinklist(head);

	if (searchNode(&head, 13))
		cout << "Node found" << endl;
	else
		cout << "Node not found" << endl;

	if (searchNode(&head, 15))
		cout << "Node found" << endl;
	else
		cout << "Node not found" << endl;

	sortLinklist(&head);
	printLinklist(head);

	return 0;
}

