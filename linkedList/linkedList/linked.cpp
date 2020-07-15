#include "linked.h"
#include <iostream>
#include <assert.h>
using namespace std;

void linked::append(int val)
{
	Node* newNode = new Node(val);
	if (head->Next == nullptr)
	{
		newNode = head;
	}
	else
	{
		Node* currentNode = head;
		while (currentNode->Next != nullptr)
		{
			currentNode->Next = currentNode;
		}

		newNode = currentNode->Next;
	}

	sz++;
}

void linked::print()
{
	Node* currtenNode = head;
	while (currtenNode->Next !=nullptr)
	{
		cout << currtenNode->value <<endl;
		currtenNode = currtenNode->Next;
	}
}

void linked::insert(int ind,int val)
{
	assert(ind >= 0 && ind <= sz);

	Node* newNode = new Node(val);
	if (ind == 0)
	{
		newNode->Next = head;
		newNode = head;
	}
	else
	{
		Node* currtenNode = head;

		int i = 0;
		while (  i < ind-1)
		{
			currtenNode = currtenNode->Next;
			i++;
		}
		newNode->Next = currtenNode->Next;
		currtenNode->Next = newNode;
	}



}

void linked::removeAt(int idx)
{
	assert(idx >= 0 && idx <= sz);
		
	if (idx == 0)
	{
		Node* tmp = head->Next;
		delete head;
		tmp = head;
	}
	else
	{
		Node* currtenNode = head;
		int i = 0;
		while (i< idx-1)
		{
			currtenNode = currtenNode->Next;
			i++;
		}

		Node* after = currtenNode->Next->Next;
		delete currtenNode->Next;
		currtenNode->Next = after;
		sz--;

	}

}




int linked::size()
{
	return sz;
}

linked::linked() :sz(0), head(nullptr)
{
}

linked::~linked()
{
	while (head != nullptr)
	{
		Node* tmp = head->Next;
		delete head;
		head = tmp;
	}
}
