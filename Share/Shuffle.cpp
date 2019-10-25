#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};

void addData(node* &, node* &, int);
void ShuffleData(node* &, node * &);
void display(node *);
void displayBack(node *);

int main()
{
	node *head = NULL, *tail = NULL;
	for (int i = 0; i < 5; i++)
    		addData(head, tail, i);
	
	display(head);

	ShuffleData(head, tail);
	display(head);

}

void ShuffleData(node* &head, node* &tail)
{
  srand(time(NULL));
  node *current = head, *temp;
  int counter = 0;
  while (current != NULL)
  {
    counter++;
    current = current->next;
  }

  for (int i = 0; i < 10000; i++)
  {
    int pos = (rand() % (counter - 1)) + 1;
    current = head;
    int j = 0;
    while (current != NULL)
    {
      if (j == pos) break;
      j++;
      current = current->next;
    }
    head = current;
    node *temphead = current->next, *tempPrev;
    while (current->prev != NULL)
    {
      temp = current->next;
      current->next = current->prev;
      if (head == current)
        current->prev = NULL;
      else
        current->prev = temp;
      tempPrev = current;
      current = current->next;
    }
    if (head != tail)
    {
      current->prev = tempPrev;
      current->next = temphead;
      temphead->prev = current;
    }
    else
    {
      current->prev = tempPrev;
      current->next = NULL;
      tail = current;
    }
  }
}

void addData(node* &head, node* &tail, int data)
{
	node *newNode = new node;
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
    		tail = newNode;
		newNode->prev = NULL;
	}
	else
	{
		node *current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = newNode;
		newNode->prev = current;
    		tail = newNode;
	}
}

void display(node *head)
{
	while (head->next != NULL)
	{
		cout << head->data << ", ";
		head = head->next;
	}

	cout << head->data << endl;
}

void displayBack(node *tail)
{
	while (tail->prev != NULL)
	{
		cout << tail->data << ", ";
		tail = tail->prev;
	}

	cout << tail->data << endl;
}
