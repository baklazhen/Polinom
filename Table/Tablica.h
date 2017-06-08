#ifndef _TABLICA_H_
#define _TABLICA_H_

#include <iostream>

using namespace std;
enum {FULL};



template <class T, class D>
class Tablica
{
protected:
	T *Key;
	D *Table;
	int count;
	int size;

public:
  Tablica (int size);
  virtual ~Tablica ();
  virtual void Add(T k, D val);
  virtual void Del (T k);
  void resize ();
  D & operator [] (T k);
  Tablica  & operator = (Tablica <T, D> &a);
  friend ostream& operator<<(ostream &out, const Tablica &tb)
  {
    for (int i = 0; i < tb.count; i++)
      out << tb.Key[i] << "    " << tb.Table[i] << '\n';
    return out;
  }
};

  template <class T, class D>
  Tablica <T, D> :: Tablica (int s)
  {
	  count = 0;
	  size = s;
	  Key = new T[size];
	  Table = new D[size];
	  for (int i = 0; i < size; i++)
	  {
		  Key [i] = 0;
		  Table [i] = 0;
	  }
  }

  template <class T, class D>
  Tablica <T, D> :: ~Tablica ()
{
	delete [] Key;
	delete [] Table;
}


template <class T, class D>
void Tablica <T, D> :: Add (T k, D val)
{
	count ++;
	if (count > size)
	resize ();
	Key [count - 1] = k;
	Table [count - 1] = val;
	
}

template <class T, class D>
void Tablica <T, D> :: resize ()
{
	Tablica <T, D> tmp (size);
	tmp = (*this);
	delete [] Key;
	delete [] Table;
	size = count;
	Key = new T [size];
	Table = new D [size];
	for (int i = 0; i < count - 1; i++)
	  {
		  Table [i] = tmp.Table [i];
		  Key [i] = tmp.Key [i];
	  }
				
}


  template <class T, class D>
void Tablica <T, D> :: Del (T k)
{
	for (int i = 0; i < count; i++)
		if (Key [i] == k)
		{
			for (int j = i; j < count - 1; j++)
			{
				Key [j] = Key [j + 1];
				Table [j] = Table [j + 1];
			}

				count--;
				
		}
}
		

  template <class T, class D>
  Tablica <T, D> & Tablica <T, D> :: operator = (Tablica <T, D> &a)
  {
	  count = a.count;
	  size = a.size;
	  delete [] Key;
	  delete [] Table;
	  Key = new T [size];
	  Table = new D [size];
	  for (int i = 0; i < count; i++)
	  {
		  Table [i] = a.Table [i];
		  Key [i] = a.Key [i];
	  }
	  return *this;
	  
  }


  template <class T, class D>
  D & Tablica <T, D> :: operator [] (T k)
  {
	  for (int i = 0; i < count; i++)
	  {
		  if (Key [i] == k)
			  return Table [i];
	  }
  }

//----------------------------


  template <class T, class D>
  class sortTable : public Tablica <T, D>
{

public:
  sortTable (int size);
  sortTable(const Tablica <T, D> &tb);
  ~sortTable ();
  void Add(T k, D val);
  void Del (T k);
  void resize ();
  
};

  template <class T, class D>
  sortTable <T, D> :: sortTable (int s) : Tablica <T, D> (s)
  {
	  
  }


  template <class T, class D>
  sortTable <T, D> :: ~sortTable ()
{

}



template <class T, class D>
void sortTable <T, D> :: Add (T k, D val)
{
	
	if (count >= size)
			resize ();

	int i = 0; int j = count;

	do
	{
		int tmp = i + (j - i)/2;
		
		if ((Key [tmp] == k) || (Key [tmp - 1] < k && Key [tmp] > k) || tmp == count || Key [tmp] > k && tmp == 0)
	{
		

		for (int z = count; z > tmp; z--)
		{
			Key [z] = Key [z - 1];
			Table [z] = Table [z - 1];
		}
		Key [tmp] = k;
		Table [tmp] = val;
		count++;
		i = j + 1;
		
	}

		else if (Key [tmp] > k)
			j = tmp;


		else if (Key [tmp] < k)
			i = tmp + 1;
	}
	while (i <= j);



	
}

		


template <class T, class D>
void sortTable <T, D> :: Del (T k)
{
	int i = 0; int j = count;
		
	do
	{
		int tmp = i + (j - i)/2;

		if (Key [tmp] == k)
		{
			for (int z = tmp; z < count - 1; z++)
			{
				Key [z] = Key [z + 1];
			    Table [z] = Table [z + 1];
			}
			count--;
		}

		else if (Key [tmp] > k)
			j = tmp;
		else if (Key [tmp] < k)
			i = tmp;
	}
		while (i < j);
	
}

template <class T, class D>
void sortTable <T, D> :: resize ()
{
	sortTable <T, D> tmp (size);
	tmp = (*this);
	delete [] Key;
	delete [] Table;
	size = count+1;
	Key = new T [size];
	Table = new D [size];
	for (int i = 0; i < count; i++)
	  {
		  Table [i] = tmp.Table [i];
		  Key [i] = tmp.Key [i];
	  }
	
				
}





  

#endif



	  



