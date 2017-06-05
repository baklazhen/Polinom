#include <iostream>
#include "ArrList.h"
using namespace std;

int main ()
{
	ArrList <int> R (10);
	R.AddFirst (3);
	R.AddFirst (8);
	R.AddFirst (6);
	R.AddFirst (1);
	R.AddLast (4);
	R.AddFirst (7);
	R.PrintList ();
	R.DelFirst ();
	R.DelLast ();
	R.PrintList ();


	return 1;
}