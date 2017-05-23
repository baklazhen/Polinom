#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
using namespace std;

template <class KEY, class DATA>
class Node
{
protected:
	KEY k;
	DATA val;
public:
	Node ();
	Node (KEY k_, DATA val_);
	KEY GetKey();
	DATA GetData();
	void SetKey(KEY k_);
	void SetVal(DATA val_);
	bool used;
	friend ostream& operator<<(ostream &out, const Node &nd)
  {
	  if (nd.used == true)
      cout << nd.val << '\n';
	  return out;
		
  }
};

template <class KEY, class DATA>
Node<KEY, DATA>::Node()
{
	k = 0;
	val = 0;
	used = false;
}

template <class KEY, class DATA>
Node<KEY, DATA>::Node(KEY k_, DATA val_)
{
	k = k_;
	val = val_;
	used = false;
}


template <class KEY, class DATA>
KEY Node<KEY, DATA>::GetKey()
{
	return k;
}
template <class KEY, class DATA>
DATA Node<KEY, DATA>::GetData()
{
	return val;
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

#endif