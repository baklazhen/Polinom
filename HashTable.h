#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_
#include <iostream>
using namespace std;

#include "Node.h"

template <class KEY, class DATA>
class Table
{
protected:
	int size; //общий размер
	int count;//текущее число записей
	int pos; // смещение
	Node <KEY, DATA> * mas; // данные
	int Hash(KEY k);
public:
Table(int s, int p); // конструктор
Table(Table& ht);
~Table();
Node <KEY, DATA>& operator[](KEY k);
Table& operator=(Table& ht);
void Add(DATA v, KEY k);
void Del(KEY k);
friend ostream& operator<<(ostream &out, const Table &ht)
  {
    for (int i = 0; i < ht.size; i++)
		out << i << "    " << ht.mas[i] << '\n' ;
			return out;
		
  }

};

template <class KEY, class DATA>
Table<KEY, DATA>::Table(int s, int p)
{
	size = s;
	count = 0;
	pos = p;
	mas = new Node <KEY, DATA> [size];
}

template <class KEY, class DATA>
Table<KEY, DATA>::~Table()
{
	delete [] mas;
	size=0;
	count=0;
}

template <class KEY, class DATA>
int Table<KEY, DATA>:: Hash(KEY k)
{
	return ((int)k) % size;

}

template <class KEY, class DATA>
Node <KEY, DATA>& Table<KEY, DATA>::operator[](KEY k)
{
	
	int index = Hash(k);
	
	do
	{
		int HashIndex = Hash(index);
		if(mas[HashIndex].GetKey()==k)
		return mas[HashIndex];
	else
		index+=pos;
	}
	while(index!=HashIndex)

}

template <class KEY, class DATA>
void Table<KEY, DATA>::Add(DATA val, KEY k)
{

    int index = Hash(k);
	int HashIndex = 0;
	
	do
	{
		HashIndex = Hash(index);
		if(mas[HashIndex].used==false)
	{
		mas[HashIndex].SetKey(k);
		mas[HashIndex].SetVal(val);
		mas[HashIndex].used = true;
		count++;
		return;

	}
	else
		index+=pos;
	}
	while(index!=HashIndex);
	cout <<"Warning: Table is full!"<< '\n';

}

template <class KEY, class DATA>
void Table<KEY, DATA>:: Del(KEY k)
{
	int index = Hash(k);
	int HashIndex = 0;
	
	do
	{
		HashIndex = Hash(index);
		if(mas[HashIndex].used==true)
	{
		mas[HashIndex].used = false;
		count--;
		return;

	}
	else
		index+=pos;
	}
	while(index!=HashIndex);
	

}



#endif