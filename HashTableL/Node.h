#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
#include <fstream>
using namespace std;

template <class KEY, class DATA>
class Node
{
protected:
	KEY k;
	DATA val;
	Node *Next;
	
public:
	Node ();
	Node (KEY k_, DATA val_);
	Node (const Node &nd);
	Node& operator=(const Node& nd);
	KEY GetKey();
	DATA GetData();
	void SetKey(KEY k_);
	void SetVal(DATA val_);
	Node *GetNext ();
	void SetNext (Node *nd);
	void PrintList();
	
		
};

template <class KEY, class DATA>
Node<KEY, DATA>::Node()
{
	k = 0;
	val = 0;
	Next = 0;
	
}

template <class KEY, class DATA>
Node<KEY, DATA>::Node(KEY k_, DATA val_)
{
	k = k_;
	val = val_;
	Next = 0;
}

template <class KEY, class DATA>
Node <KEY, DATA>::Node(const Node &nd)
{
	k = nd.k;
	val = nd.val;
	Next = nd.Next;
}

template <class KEY, class DATA>
Node<KEY, DATA> & Node <KEY, DATA>::operator=(const Node& nd)
{
	k = nd.k;
	val = nd.val;
	Next = nd.Next;
	return *this;
}


template <class KEY, class DATA>
KEY Node<KEY, DATA>::GetKey()
{
	return k;
}
template <class KEY, class DATA>
DATA Node<KEY, DATA>::GetData()
{
	return (*this).val;
}
template <class KEY, class DATA>
void Node<KEY, DATA>::SetKey(KEY k_)
{
	k = k_;
}
template <class KEY, class DATA>
void Node<KEY, DATA>::SetVal(DATA val_)
{
	val = val_;
}

template <class KEY, class DATA>
Node <KEY, DATA> * Node <KEY, DATA>::GetNext ()
{
	Node *tmp = (*this).Next;
	return tmp;
}


template <class KEY, class DATA>
void Node <KEY, DATA>::SetNext (Node *nd)
{
	(*this).Next = nd;
	
}

template <class KEY, class DATA>
void Node <KEY, DATA>::PrintList()
{
	Node * tmp;
	tmp = this;
	while (tmp != 0)
	{
		cout << tmp->k << "  " << tmp->val << '\n';
		tmp = tmp->Next;
	}
}



#endif