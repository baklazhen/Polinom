#ifndef _MONOM_H_
#define _MONOM_H_
#include <iostream>
using namespace std;


template <class T, class D>
class Monom
{
protected:
	T index;
	int count;
	D * degree;
	Monom * Next;
	
public:
	Monom ();
	Monom (T k, int c);
	Monom (Monom &mn);
	~Monom ();
	Monom & operator = (Monom& mn);
	void InputMonom ();
	void PrintMonom ();
	void SetNext (Monom * mn);
	Monom * GetNext ();
	bool operator <(const Monom & mn);
	bool operator==(const Monom & mn);
	Monom operator+(Monom& mn);
	Monom operator*(Monom& mn);
};

template <class T, class D>
Monom <T, D>::Monom()
{
	index = 0;
	count = 0;
	degree = 0;
	Next = 0;
}


template <class T, class D>
Monom <T, D>::Monom(T k, int c)
{
	Next = 0;
	index = k;
	count = c;
	degree = new D [count];
	for (int i = 0; i < count; i++)
		degree [i] = 0;
}

template <class T, class D>
Monom <T, D>::Monom (Monom &mn)
{
	Next = mn.Next;
	index = mn.index;
	count = mn.count;
	degree = new D [count];
	for (int i = 0; i < count; i++)
		degree [i] = mn.degree [i];
}

template <class T, class D>
Monom <T, D>:: ~Monom()
{
	
	
}

template <class T, class D>
Monom <T, D> & Monom <T, D>::operator = (Monom & mn)
{
	Next = mn.Next;
	index = mn.index;
	count = mn.count;
	degree = new D [count];
	for (int i = 0; i < count; i++)
		degree [i] = mn.degree [i];
	return (*this);
}

template <class T, class D>
void Monom <T, D>::InputMonom()
{
	for (int i = 0; i < count; i++)
	{
		cout << "Vvedite stepen " << i+1 << " peremennoi ";
		cin >> degree [i];
	}
}

template <class T, class D>
void Monom <T, D>::PrintMonom()
{
	
	cout << index;
	for (int i = 0; i < count; i++)
	 cout << "X(" << i+1 << ")^" << degree [i] << " ";
		
}
template <class T, class D>
void Monom <T, D>::SetNext (Monom * mn)
{
	Next = mn;
	
}

template <class T, class D>
Monom <T, D> * Monom <T, D>::GetNext ()
{
	return Next;
}

template <class T, class D>
bool Monom <T, D>::operator<(const Monom & mn)
{
	for (int i = 0; i < count; i++)
	{
		if (degree [i] < mn.degree [i])
			return 1;
		if (degree [i] > mn.degree [i])
			return 0;
	}
	if ((*this) == mn && index < mn.index)
		return 1;

	

}

template <class T, class D>
bool Monom <T, D>::operator==(const Monom & mn) 
{
	if (count != mn.count)
		return 0;
	for (int i = 0; i < count; i++)
		if (degree [i] != mn.degree [i])
		return 0;

	return 1;
}

template <class T, class D>
Monom <T, D> Monom <T, D>::operator+(Monom & mn)
{
	if ((*this) == mn)
	{
		T Nindex = index + mn.index;
		Monom <T, D> A (Nindex, count);
		A.Next = Next;

		for (int i = 0; i < count; i++)
			A.degree [i] = degree [i];
		return A;
	}

	else 
		cout << "Error!";

}

template <class T, class D>
Monom <T, D> Monom <T, D> :: operator * (Monom & mn)
{
	int min, max;
	if (count >= mn.count)
	{
		max = count;
		min = mn.count;
	}
	else
	{
		max = mn.count;
		min = count;
	}
		

	Monom res ((index*mn.index), max);
	for (int i = 0; i < min; i++)
		res.degree [i] = degree [i] + mn.degree[i];
	for (int j = min; j < max; j++)
	{
		if (count > mn.count)
			res.degree[j] = degree[j];
		else
			res.degree[j] = mn.degree[j];
	}


		
	return res;
}
























#endif