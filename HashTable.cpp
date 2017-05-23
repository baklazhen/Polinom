
#include "HashTable.h"
#include <iostream>
using namespace std;



int main ()
{
	
	Table <int, int> H (10, 1);
	H.Add (4, 20);
	H.Add (8, 45);
	H.Add (15, 25);
	H.Add (18, 15);
	H.Add (21, 30);
	H.Del (20);
	
	cout << H << '\n';
	


	return 1;
}