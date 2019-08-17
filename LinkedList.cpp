/*
 * LinkedList.cpp
 *
 *  Created on: 17-Aug-2019
 *      Author: Soham Basu
 */

#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
};

class LinkedList
{
public:
	Node *start, *end; int size;
	LinkedList(){
		start = end = NULL;
		size = 0;
	}
	int getVal(int p)
	{
		if(p>=size)
		{
			cout<<"Position is out of List's bounds!"<<endl;
			return -1;
		}
		int pos = 0;
		Node *temp = new Node;
		temp = start;
		int val = 0;
		while(pos!=p)
		{
			val = temp->data;
			temp = temp->next;
			pos++;
		}
		cout<<"Element at position "<<p<<" is: "<<val<<endl;
		return 1;
	}
	void insert_end(int val)
	{
		Node *temp = new Node;
		if(start == NULL)
		{
			temp->data = val;
			temp->next = NULL;
			temp->prev = NULL;
			start = end = temp;
		}
		else
		{
			temp->prev = end;
			temp->next = NULL;
			temp->data = val;
			end->next = temp;
			end = temp;
		}
		size++;
		cout<<val<<" has been inserted at the end of the list"<<endl;
	}
	void insert_start(int val)
	{
		Node *temp = new Node;
		if(start == NULL)
		{
			temp->data = val;
			temp->next = NULL;
			temp->prev = NULL;
			start = end = temp;
		}
		else
		{
			temp->next = start;
			temp->prev = NULL;
			temp->data = val;
			start->prev=temp;
			start = temp;
		}
		size++;
		cout<<val<<" has been inserted at the beginning of the list"<<endl;
	}
	void insert_pos(int val, int p)
	{
		Node *temp = start;
		Node *cur = new Node;
		temp = start;
		int pos = 0;
		if(p > size)
			cout<<"Position does not exist"<<endl;

		else if(p == size)
			insert_end(val);
		else if(p == 0)
			insert_start(val);
		else
		{
			while(pos != p-1)
			{
				temp = temp->next;
				pos++;
			}
			cur->data = val;
			cur->prev = temp;
			cur->next = temp->next;
			temp->next->prev = cur;
			temp->next = cur;
			cout<<val<<" inserted at position "<<p<<endl;
			size++;
		}
	}
	void delete_start()
	{
		if(start==NULL)
			cout<<"Underflow! List is empty"<<endl;
		else
		{
			cout<<"Deleting "<<start->data<<endl;
			if(start->next != NULL)
			{
				start = start->next;
				start->prev = NULL;
			}
			else
				start = end = NULL;
		}
		size--;
	}
	void delete_end()
	{
		if(end==NULL)
					cout<<"Underflow! List is empty"<<endl;
		else
		{
			cout<<"Deleting "<<end->data<<endl;
			if(end->prev != NULL)
			{
				end = end->prev;
				end->next = NULL;
			}
			else
				start = end = NULL;
		}
		size--;
	}
	void delete_pos(int p)
	{
		Node *temp = start;
		int pos = 0;
		if(start == NULL)
			cout<<"Underflow! List is empty"<<endl;
		else if(p > size)
				cout<<"Position does not exist"<<endl;

		else if(p == size-1)
				delete_end();
		else if(p == 0)
				delete_start();
		else
		{
			while(pos != p)
			{
				temp = temp->next;
				pos++;
			}
			cout<<temp->data<<" has been deleted from position "<<p<<endl;
			if(temp->next != NULL)
				temp->next->prev = temp->prev;
			if(temp->prev != NULL)
				temp->prev->next = temp->next;
			delete temp;
			size--;
		}
	}
	void display()
	{
		if(start == NULL)
			cout<<"List is empty!"<<endl;
		else
		{
			Node *temp = new Node;
			temp = start;
			while(temp!=NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<endl;
		}
	}
};

int main()
{
	LinkedList ob;
	int ch = 0, num, pos;
	do {
	     cout<<"MENU"<<endl;
	     cout<<"1. Insert from start \n2. Insert from end \n3. Insert at Position \n4. Delete from start \n5. Delete from end \n6. Delete from position \n7. Display List \n8. Display Size of List \n9. Delete List  \n10. Get value at a position \n11. Exit \n"<<endl;

	     cout<< "Enter your choice : ";
	     cin>>ch;
	     switch(ch)
	     {
	         case 1: cout<<"\n Enter the number to be inserted : "<<endl;;
	                 cin>>num;
	                 ob.insert_start(num);
	         break;
	         case 2: cout<<"\n Enter the number to be inserted : "<<endl;;
             	 	 cin>>num;
             	 	 ob.insert_end(num);
	         break;
	         case 3: cout<<"\n Enter the number to be inserted : "<<endl;;
	         	 	 cin>>num;
	         	 	 cout<<"\n Enter the position: "<<endl;
	         	 	 cin>>pos;
	         	 	 ob.insert_pos(num,pos);
	         break;
	         case 4: ob.delete_start();
	         break;
	         case 5: ob.delete_end();
	         break;
	         case 6: cout<<"\n Enter the position: "<<endl;
	         	     cin>>pos;
	         	     ob.delete_pos(pos);
	         break;
	         case 7: ob.display();
	         break;
	         case 8: cout<<"Size of the list: "<<ob.size<<endl;
	         break;
	         case 9: cout<<"List has been deleted!"<<endl;
	         	 	 ob.start = ob.end = NULL; ob.size = 0;
	         break;
	         case 10: cout<<"Enter position to retrieve value"<<endl;
	         	 	  cin>>pos;
	         	 	  pos = ob.getVal(pos);
	         break;
	         case 11: cout<<"Exiting.."<<endl;
	         break;
	         default: cout<<"Enter a Valid Choice"<<endl;
	      }
	     }
	     while(ch!=11);
		return 0;
}
