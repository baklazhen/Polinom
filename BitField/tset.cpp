#include "tset.h"

TSet::TSet(int mp) : MaxPower(mp), BitField(mp)
{
}

TSet::TSet(const TSet &s) : MaxPower(s.MaxPower), BitField(s.BitField)
{
}

TSet::TSet(const TBitField &bf) : BitField( bf ), MaxPower( bf.GetLength() )
{
}


TSet::operator TBitField()
{
	return BitField;
}

 int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
 {
	 return MaxPower;
 }

 void TSet::InsElem(const int Elem) // включение элемента множества
 {
	 BitField.SetBit(Elem);
 }

 void TSet::DelElem(const int Elem)       // удалить элемент из множества
 {
	 BitField.ClrBit(Elem);
 }

 void TSet::savetomas()       
 {
	 int * mas;
	 mas = new int [MaxPower];
	 for (int i = 0; i < MaxPower; i++)
	 {
		 if (IsMember(i))
		 {
			 mas [i] = i;
			 cout << mas [i] << '\n';
		 }
	 }
 }

TSet& TSet::operator=(const TSet &s) // присваивание
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	if (MaxPower != s.MaxPower)
		return 0;
	return BitField == s.BitField;
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	if (MaxPower != s.MaxPower)
		return 1;
	return BitField != s.BitField;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	TSet res(BitField);
	res.BitField.SetBit(Elem);
	return res;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	TSet res(BitField);
	res.BitField.ClrBit(Elem);
	return res;
}

TSet TSet::operator+(const TSet &s) // объединение
{
	TSet res(BitField | s.BitField);
	return res;
}


TSet TSet::operator*(const TSet &s) // пересечение
{
	TSet res(BitField & s.BitField);
	return res;
}

TSet TSet::operator~(void) // дополнение
{
	TSet res(~BitField);
	return res;
}

int TSet::IsMember(const int Elem) const // элемент множества
 {
	 return this->BitField.GetBit(Elem);
 }

 istream &operator >> (istream &istr, TSet &s) // ввод
 {
   char ts = 0;
    do {
        istr >> ts;
    }
    while (ts != '{');

    int temp = 0;
    do {
        istr >> ts;
        s.InsElem(temp);

        do {
            istr >> ts;
        }
        while ((ts != ',') && (ts != '}'));
    }
    while (ts != '}');

    return istr;
 }
 
 ostream& operator<<(ostream &ostr, const TSet &s) // вывод
 {
    char ts = ' ';
    ostr << "{";

    for (int i = 0; i < s.GetMaxPower(); i++)
        if (s.IsMember(i))
		{
            ostr << ts << i;
            ts = ',';
        }
		ts = ' ';

    ostr << ts << "}" << '\n';

    return ostr;
 }





