/* Question:
Rewrite the function for problem 1 in such a way that if svalue is found multiple times,
the function will add the newvalue before each node with svalue. 
*/

#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

void addNode(node* &, int);
void displayNode(node *);

bool insertByValueBefore(node* &sll, int svalue, int newvalue)
{
	node *current = sll, *prev = NULL;
	bool found = false;

	while (current != NULL)
	{
		if (current->data == svalue)
		{
			if (current == sll)
			{
				node *newNode = new node;
				newNode->data = newvalue;
				newNode->next = current;
				sll = newNode;
			}
			else
			{
				node *newNode = new node;
				newNode->data = newvalue;
				newNode->next = current;
				prev->next = newNode;
			}
			found = true;
		}
		prev = current;
		current = current->next;
	}
	return found;
}

int main()
{
	node *head = NULL;

	for (int i = 1; i <= 10; i++)
	{
		addNode(head, i);
	}
	addNode(head, 7);

	displayNode(head);
	cout << (insertByValueBefore(head, 7, 11) ? "Found" : "Not found") << endl;
	displayNode(head);
}

void addNode(node* &head, int data)
{
	node *newNode = new node;
	if (head == NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
		head = newNode;
	}
	else
	{
		node *current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}

		newNode->data = data;
		newNode->next = NULL;
		current->next = newNode;
	}
}

void displayNode(node *head)
{
	node *current = head;
	while (current->next != NULL)
	{
		cout << current->data << ", ";
		current = current->next;
	}
	cout << current->data << endl;
}
