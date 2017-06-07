#include "bitfield.h"
#include "tset.h"

int main()
{ 

TSet b (10);
b.InsElem (9);
b.InsElem (3);
b.InsElem (6);
b.InsElem (7);
cout << b;
b.DelElem (9);
cout << b;
b.savetomas();

return 0;
}