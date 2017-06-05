#ifndef _ARRLIST_H_
#define _ARRLIST_H_
#include <fstream>

#include <iostream>

using namespace std;

template <class T>
class ArrList

{	
	
	
protected:
	T *Value;
	int *Next;
	int size;
	int start;
	int end;
	int count;
	
public:
	
     ArrList(int s);
	 ArrList (ArrList & a);
     ~ArrList();
     void AddFirst (T a);
	 void DelFirst ();
	 void AddLast (T a);
	 void DelLast ();
	 void PrintList ();
	 void SaveToFile ();
	 
     
};

template <class T>
ArrList <T>:: ArrList (int s)
{
	size = s;
	count = 0;
	start = end = 0;
	Value = new T [size];
	Next = new int [size];
	for(int i=0; i<size; i++)
	{
		Value [i] = 0;
		Next [i] = -1;
	}

	

}

template <class T>
ArrList <T>:: ArrList (ArrList & a)
{
	size = a.size;
	count = a.count;
	start = a.start;
	end = a.end;
	Value = new T [size];
	Next = new int [size];
	
	for(int i=0; i<size; i++)
	{
		Value [i] = a.Value [i];
		Next [i] = a.Next [i];
	}
}


template <class T>
ArrList <T>::  ~ArrList()
{
	delete [] Value;
	delete [] Next;

	
}

template <class T>
void ArrList <T>:: AddFirst (T a)
{
	if (count == 0)
	{
		Value [0] = a;
		Next [0] = -2;
	}
		
	
	else 
		for (int i = 0; i < size; i++)
		{
			if (Next [i] == -1)
			{
				Value [i] = a;
				Next [i] =  start;
				start= i;
				break;
			}
		}
		count ++;
}

template <class T>
void ArrList <T>:: AddLast (T a)
{
	 
		for (int i = 0; i < size; i++)
		{
			if (Next [i] == -1)
			{
				Value [i] = a;
				Next [end] =  i;
				Next [i] = start;
				end = i;
				break;
			}
		}
		count ++;
}



template <class T>
void ArrList <T>:: DelFirst ()

{
	int s = start;
	start = Next[start];
	Next[s]= -1;
	count --;
}

template <class T>
void ArrList <T>:: DelLast ()
{
	for (int i = 0; i < size; i++)
		if (Next [i] == end)
		{
			Next[end] = -1;
			end = i;
			Next[end] = -2;
			break;
		}
		count --;


}

template <class T>
void ArrList <T>:: PrintList ()
{
	int d = 0;
	int u = start;
	while (d != count)
	{
		cout << Value [u] << " ";
		u = Next [u];
		d++;
		
	}
	cout << '\n';
}

template <class T>
void ArrList <T>:: SaveToFile ()
{
	ofstream fout;
    fout.open("List.txt");

	int d = start;
	
	for (int i = 0; i < 2; i++)
	{
		fout << Value [d] << "  ";
		d = Next [d];
	}

	ArrList <int> B (3);
	for (int i = 0; i < size; i++)
	{
		if (Next [i] == end)
			for (int j = 0; j < size; j++)
				if (Next [j] == i)
				{
					B.AddFirst (Value[j]);
					B.AddLast (Value[i]);
					B.AddLast (Value[end]);
								

				}

	}
	for (int i = 0; i < 3; i++)
	{
		fout << B.Value [i] << "  ";
		
	}


				
	  
   fout.close();
}










#endif 



