#include"QInt_16bytes.h"
#include"CConvert.h"
QInt::QInt(string strBin){
	CConvert::Reserve_Str(strBin);
	int len = strBin.length();
	for (int i = 0; i < len; i++)
	{
		if (strBin[i]=='1')
		{
			arrBits.set(i);
		}
	}
}

string QInt::ToString()
{
	string strResult;
	strResult = arrBits.to_string();
	CConvert::DelBit0(strResult);
	return strResult;
}

QInt QInt::NOT(){
	QInt Result(ToString());
	Result.arrBits.flip();
	return Result;
}

QInt QInt::operator+(QInt qNum) 
{
	bitset<_INT_128BIT> arrBitsResult;
	int BitTemp = 0;
	for (int i = 0; i < _INT_128BIT; i++)
	{
		BitTemp = qNum.arrBits[i] + arrBits[i] + BitTemp;
		if (BitTemp==0)
		{
			arrBitsResult[i] = 0;
		}
		else
		{
			if (BitTemp==1)
			{
				arrBitsResult[i] = 1;
				BitTemp = 0;
			}
			else
			{
				arrBitsResult[i] = 0;
				BitTemp--;
			}
		}
	}
	return QInt((arrBitsResult.to_string()));
}