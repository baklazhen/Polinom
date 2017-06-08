#ifndef _POLINOM_H_
#define _POLINOM_H_
#include <iostream>
#include "Monom.h"
		
template <class T, class D>
class Polinom
{

private:
	Monom <T, D> * Head, * Tail;
	

public:
	Polinom ();
	Polinom (Polinom & pl);
	~Polinom();
	Polinom& operator = (const Polinom& pl);
	void Add (Monom <T, D> & mn);
	void PrintPolinom ();
	Polinom operator + (Monom <T, D> & mn);
	Polinom  operator +(Polinom & pl);
	
};

template <class T, class D>
Polinom <T, D>::Polinom()
{
	Head = Tail = 0;
	
}

template <class T, class D>
Polinom <T, D>::Polinom(Polinom & pl)
{
	Head = pl.Head;
	Tail = pl.Tail;
	
}

template <class T, class D>
Polinom <T, D>::~Polinom()
{
	

}

template <class T, class D>
Polinom <T, D> & Polinom <T, D>::operator = (const Polinom& pl)
{
	Head = pl.Head;
	Tail = pl.Tail;
	return *this;

}


template <class T, class D>
void Polinom <T, D>::Add(Monom <T, D> &  mn)
{
	
	Monom <T, D> * tmp = &mn;
	Monom <T, D> * tmph = Head;
	Monom <T, D> * tmpt = Tail;
	
	if (Head == 0)
	{
		Head = Tail = tmp;
		return;
	}
	if ((*tmph) < (*tmp))
	 {
		 tmp->SetNext(tmph);
	     Head = tmp;
		 return;
	 }
	if ((*tmp) < (*tmpt))
	 {
		 tmpt->SetNext(tmp);
	     Tail = tmp;
		 Tail->SetNext(0);
		  return;
	 }

	if (Head != 0)
		
	 {
		 while ((*tmp) < (*tmph))
		 {
			 tmpt = tmph;
			 tmph = tmph->GetNext();
		 }

		  tmpt->SetNext (tmp);
	      tmp->SetNext (tmph);
		  
		  
	 }
	
}

template <class T, class D>
void Polinom <T, D> ::PrintPolinom()
{
	Monom <T, D> * tmph = Head;
	
	
	while (tmph != Tail)
	{
		tmph->PrintMonom(); cout << "+ ";
		tmph = tmph->GetNext();
	}
	tmph->PrintMonom();
	cout << '\n';

}

template <class T, class D>
Polinom <T, D> Polinom <T, D>::operator + (Monom <T, D> & mn)
{
	Polinom <int, int> sum = (*this);
	Monom <T, D> * tmph = Head;
	
	while (tmph != 0)
	{
		if ((*tmph) == mn)
		{
			(*tmph) = (*tmph) + mn;
			return *this;
		}
		tmph = tmph->GetNext();
	}

	sum.Add (mn);
	return sum;

}

template <class T, class D>
Polinom <T, D> Polinom <T, D>::operator + (Polinom & pl)
{
	Polinom <int, int> res = (*this);
	Monom <T, D> * tmp = pl.Head;
	Monom <T, D> * tmpn = tmp->GetNext();


	while (tmp != 0)
	{
		
		res = res + (*tmp);
		tmp = tmpn;
		if (tmpn == 0)
			break;
		tmpn = tmpn->GetNext();
		
	}

			
	return res;

}





















#endif