#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_
#include <iostream>
#include <fstream>
using namespace std;

#include "Node.h"

template <class KEY, class DATA>
class Table
{
protected:
	int size; //общий размер
	int count;
	Node <KEY, DATA> ** mas; // данные
	int Hash(KEY k);
public:
Table(int s); // конструктор
Table(const Table& ht);//конструктор копирования
~Table();
Table& operator=(const Table& ht);//присваивание
void Add(DATA v, KEY k);
void Del(KEY k);
void resize (int s); //изменение размера
void saveToFile ();

friend ostream& operator<<(ostream &out, Table &ht)
  {
	 	  
			for (int i = 0; i < ht.size; i++)
			{
				if (ht.mas[i] != 0)
				{
														
					out << i << "    ";
				(ht.mas[i])->PrintList (); 
				out << '\n';
				}
			
				
			}

			return out;
		
  }

};

template <class KEY, class DATA>
Table <KEY, DATA>::Table(int s)
{
	size = s;
	count = 0;
	mas = new Node <KEY, DATA> * [size];
	for (int i = 0; i < size; i++)
		mas [i] = 0;
}

template <class KEY, class DATA>
Table <KEY, DATA>::~Table()
{
	size = 0;
	for (int i = 0; i < size; i++)
	{
		Node <KEY, DATA> * tmp = mas[i], *tmpn;
		while (tmp != 0)
		{
			tmpn = tmp->GetNext();
			delete [] tmp;
			tmp = tmpn;
		}
	}
		delete [] mas; 
		mas = 0;
	
}

	


template <class KEY, class DATA>
Table <KEY, DATA>::Table (const Table & ht)
{
	size = ht.size;
	count = ht.count;
	mas = new Node <KEY, DATA> * [size];
	for (int i = 0; i < size; i++)
		mas [i] = ht.mas [i];
}

template <class KEY, class DATA>
Table <KEY, DATA> & Table <KEY, DATA>:: operator = (const Table & ht)
{
	size = ht.size;
	count = ht.count;
	mas = new Node <KEY, DATA> * [size];
	for (int i = 0; i < size; i++)
		mas [i] = ht.mas [i];
	return *this;
}

template <class KEY, class DATA>
int Table <KEY, DATA>:: Hash(KEY k)
{
	return ((int)k) % size;

}



template <class KEY, class DATA>
void Table <KEY, DATA>::Add(DATA val, KEY k)
{
	

    int HashIndex = Hash(k);
	Node <KEY, DATA> * Elem;
	Elem = new Node <KEY, DATA> ();
	Elem->SetKey (k);
	Elem->SetVal (val);
	
	
	
	if(mas[HashIndex]!=0)
	{
		Node <KEY, DATA> * tmp, * tmpn;
		tmp = mas[HashIndex];
		tmpn = tmp->GetNext ();
		while (tmpn != 0)
		{
			tmp = tmpn;
			tmpn = tmpn->GetNext ();
		}
		tmpn = Elem;
		tmp->SetNext (Elem);
			

	}

	else 
	{
		
		mas[HashIndex] = Elem;
		count ++;
			
	}

	    
		

}

template <class KEY, class DATA>
void Table<KEY, DATA>:: Del(KEY k)
{
	int HashIndex = Hash(k);
	Node <KEY, DATA> * Head, *HeadPrev;
	Head = mas[HashIndex];
	HeadPrev = 0;
	KEY inskey = 0;
	int newcount = count;
	while (Head != 0)
	{
		inskey = Head->GetKey();
		if (inskey == k)
		{
			if (HeadPrev == 0)
			{
				mas[HashIndex] = Head->GetNext();
				Head = Head->GetNext();
			}

			else
			{
				Head = Head->GetNext();
				HeadPrev->SetNext (Head);
			}

			newcount --;
			
		}
		    
		else 
		{
			HeadPrev = Head;
			Head = Head->GetNext();
						
		}

	}

	if (newcount == count)
		cout << "No element" << '\n' ;



}


template <class KEY, class DATA>
void Table<KEY, DATA>::resize (int s)
{
	Table tmp = (*this);
	size = s;
	DATA insval;
	KEY inskey;
	Node <KEY, DATA> * insNext;
	mas = new Node <KEY, DATA> * [size];
	for (int i = 0; i < size; i++)
		mas [i] = 0;
	for (int j = 0; j < tmp.size; j++)
	{
		insNext = tmp.mas [j];
			while (insNext != 0)
			{
				insval = insNext->GetData();
				inskey = insNext->GetKey();
				(*this).Add (insval, inskey);
				insNext = insNext->GetNext ();
			}
		
	}
		
		
}

template <class KEY, class DATA>
void Table <KEY, DATA>::saveToFile ()
{
	Node <KEY, DATA> * tmp;
	ofstream fout;
    fout.open("Tablica.txt");
	for (int i = 0; i < size; i++)
	{
		if (mas[i] != 0)
		{	
			tmp = mas[i];
					fout << i << "    ";
					while (tmp != 0)
					{
						fout << tmp->GetData() << "  ";
						tmp = tmp->GetNext();
					}
					fout << '\n';
		}
	}
				
	  
   fout.close();
}








#endif