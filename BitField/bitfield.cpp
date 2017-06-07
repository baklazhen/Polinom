#include "bitfield.h"

enum ERRORS { BADSIZE = 0, BADINDEX };


TBitField::TBitField (int len)
{
	if (len<1)
		throw BADSIZE;
	BitLen=len;
	MemLen=BitLen/(sizeof(TELEM)*8) + 1;
	pMem=new TELEM [MemLen];
	for (int i=0; i<MemLen; i++)
	{
		pMem[i]=0;
	}
}

TBitField::TBitField(const TBitField &bf)
{
	BitLen=bf.BitLen;
	MemLen=bf.MemLen;
	pMem=new TELEM [MemLen];
	for (int i=0; i<MemLen; i++)
	{
		pMem[i]=bf.pMem[i];
	}
}

TBitField::~TBitField()
{
	delete [] pMem;
}

int TBitField::GetMemIndex( const int n ) const
{
	return n/(sizeof( TELEM )*8);
}

TELEM TBitField::GetMemMask (const int n) const
{
	int pos = n % (sizeof(TELEM)*8);
	TELEM tmp = 1;
	tmp <<= pos;
	return tmp;
}

int TBitField::GetLength(void) const
{
	return BitLen;
}

void TBitField::SetBit(const int n)
{
	if ( ( n < 0 ) || ( n > BitLen ))
  		throw BADINDEX;
	int index = GetMemIndex(n);
  	TELEM mask = GetMemMask(n);
	pMem[index] |= mask;
}

void TBitField::ClrBit(const int n)
{
	if ( ( n < 0 ) || ( n > BitLen ))
  		throw BADINDEX;
	int index = GetMemIndex(n);
  	pMem[index] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const
{
	if ( ( n < 0 ) || ( n > BitLen ))
  		throw BADINDEX;
	int index = GetMemIndex(n);
  	return pMem[index] & GetMemMask(n);
}

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
  	  if (this != &bf)
		  delete [] pMem;
	  BitLen = bf.BitLen;
	  MemLen = bf.MemLen;
	  pMem = new TELEM [MemLen];
	  for (int i = 0; i < MemLen; ++i)
		  pMem[i] = bf.pMem[i];
	  return * this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
  	  if (BitLen == bf.BitLen)
  	  {
		  for (int i=0; i<MemLen; i++)
		  {
			  if (pMem[i]!=bf.pMem[i])
			  return 0;
		  }
		  return 1;
	  }
	  return 0;	 
	  
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	if (BitLen != bf.BitLen)
		  return 1;
		  for (int i=0; i<MemLen; i++)
		  {
			  if (pMem[i]!=bf.pMem[i])
			  return 1;
		  }
				  
		  return 0;
}

TBitField TBitField::operator |(const TBitField &bf) // операция "или"
{
	if(BitLen != bf.BitLen)
		throw BADSIZE;

	TBitField res(BitLen);
	for (int i = 0; i < MemLen; ++i)
		res.pMem[i] = bf.pMem[i] | pMem[i];
	return res;
}



TBitField TBitField::operator &(const TBitField &bf) // операция "и"
{
	if( BitLen != bf.BitLen)
		throw BADSIZE;
	TBitField res(BitLen);
	for( int i = 0; i < MemLen ; ++i )
		res.pMem[i] =(bf.pMem[i] & pMem[i]);
	return res;
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField res(BitLen);
	for( int i = 0; i < MemLen ; ++i )
		res.pMem[i] = ~pMem[i];
	return res;
}

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
	int i = 0;
	char c;
	while (true)
	{
		istr >> c;
		if (c == '0')
			bf.ClrBit(i++);
		else if (c == '1')
			bf.SetBit(i++);
		else
			break;
		return istr;
	}
}
ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
		int len = bf.GetLength();
		for (int i = 0; i < len; ++i)
		{
			if (bf.GetBit(i))
				ostr << '1';
			else
				ostr << '0';
		}
		return ostr;
}




















