#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>

using namespace std;

template <class T>
class List

{	
	
	
protected:
	struct Node
	{
		T val;
		Node *Next;
		Node(): val(0), Next(0){}
		
	};
	
	Node *Head,*Tail;

public:
	
	List(): Head(0),Tail(0){};
	List (List & a);
	~List();
    void AddFirst (T a);
	void DelFirst ();
	void AddLast (T a);
	void DelLast ();
	void PrintList ();
	 
     
};


template <class T>
List <T>::~List()
{
	Node *tmp = Head;
	 while (tmp!=0) 
	 {
		  tmp = Head->Next;
		  delete Head;
		  Head=tmp;
	 }
}

template <class T>
void List <T>::AddLast (T a)
{
	Node *tmp = new Node;
	tmp->val = a;

if (Head == 0)
	{
		Head = Tail = tmp;
	}
	else
	{
		Tail->Next = tmp;
		Tail = tmp;
	}
	
	
}


template <class T>
void List <T>::AddFirst (T a)
{
	Node * tmp = new Node;
	tmp->val = a;

if (Head == 0)
	{
		Head = Tail = tmp;
	}
	else
	{
		tmp->Next = Head;
		Head = tmp;
	}
	
}

template <class T>
void List <T>::DelFirst ()
{
	if (Head == 0)
		cout << "Warning: List is empty!" << '\n';

	Node * tmp=Head;
    if (Head != Tail) 
    {
       
        Head = Head->Next;
        delete tmp;
    }
	else 
	{
		Head = Tail = 0;
		delete tmp;
	}
}

template <class T>
void List <T>::DelLast ()
{
	if (Head == 0)
		cout << "Warning: List is empty!" << '\n';

	Node * tmp = Head;
	Node * tmpn;
    while (tmp->Next != Tail)
		tmp = tmp->Next;
	tmpn = Tail;
	Tail = tmp;
	Tail->Next = 0;
	delete tmpn;
	   
   
}

template <class T>
void List <T>::PrintList()
{
	Node *tmp = Head;
	 while (tmp!=0) 
	 {
		 cout << tmp->val << " ";
		 tmp = tmp->Next;
	 }
	 cout << '\n';
}

#endif




