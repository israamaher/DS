#pragma once
#include"Node.h"
class linked
{
	
	private:
		Node* head;
		int sz;
	public:
		void append(int val);
		void print();
		void insert(int ind , int val);
		void removeAt(int idx);
		int size();


		linked();
		~linked();
	
};

