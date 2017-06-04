
#include "HashTableList.h"
#include <iostream>
#include <fstream>
using namespace std;



int main ()
{
	
	Table <int, int> H (10);
	H.Add (9, 10);
	H.Add (4, 13);
	H.Add (7, 16);
	H.Add (28, 12);
	H.Add (15, 18);
	H.Add (23, 1);
	H.Add (3, 17);
	H.Add (95, 19);
	H.Add (87, 15);
	H.Add (16, 8);
	H.Add (5, 22);
	H.Add (8, 32);
	cout << H << '\n';
	H.saveToFile();
	H.Del (12);
	cout << H << '\n';
	
	H.resize (14);
	cout << H << '\n';
	H.Del (2);
	
	
	


	return 1;
}