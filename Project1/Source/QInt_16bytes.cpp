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
	if (strResult=="")
	{
		strResult = "0";
	}
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
				if (BitTemp==2)
				{
					arrBitsResult[i] = 0;
					BitTemp--;
				}
				else
				{
					arrBitsResult[i] = 1;
					BitTemp = 1;
				}
			}
		}
	}
	return QInt((arrBitsResult.to_string()));
}

QInt QInt::operator-(QInt qNum)
{
	bitset<_INT_128BIT> arrBitsResult;
	qNum = CConvert::strBinTo2Complement(qNum.ToString());
	return QInt(this->ToString()) + qNum;
}


QInt QInt::operator*(QInt qNum)
{
	string strSrc = CConvert::strBinToDec(qNum.ToString());
	string strResult =CConvert::strDecToBin(CConvert::Mult_strDec(strSrc, CConvert::strBinToDec(qNum.ToString())));
	return QInt(strResult);
}

QInt QInt::operator/(QInt qNum) {
	/*
	Khởi tạo: A = n bit 0 nếu Q > 0; A = n bit 1 nếu Q < 0; k = n
	Lặp khi k > 0
	{
	Shift left (SHL) [A, Q]
	A – M -> B
	# Nếu A < 0: Q0 = 0
	# Ngược lại: Q0 = 1 và A=B
	k = k – 1
	}
	Kết quả: Q là thương, A là số dư
	*/
	bitset<_INT_128BIT> M(qNum.ToString());//Mảng bit M
	bitset<_INT_128BIT> Q(this->ToString());//Mảng bit Q
	bitset<_INT_128BIT> A("0");//khỏi tạo mang bit A với (_INT_128BIT) bit 0;
	bool SignOfResultIsNagative = false;//Dấu của kết quả phép tính là dương

	//Xét dấu
	if (M[_INT_128BIT - 1] == 1&&Q[_INT_128BIT - 1] == 1)//Nếu 2 số đều âm thì đổi lại thành dương và kết quả chia không đổi
	{
		bitset<_INT_128BIT> T(CConvert::strBinTo2Complement(Q.to_string()));
		bitset<_INT_128BIT> T1(CConvert::strBinTo2Complement(M.to_string()));
		Q = T;
		M = T1;
	}
	else//Ngược lại nếu có 1 trong 2 số là âm thì đổi số đó thành số dương và đánh dấu kết quả sẽ âm
	{
		if (M[_INT_128BIT - 1] == 1&&M.to_string().length() == _INT_128BIT && Q[_INT_128BIT - 1] == 0)
		{
			SignOfResultIsNagative = true;
			bitset<_INT_128BIT> T1(CConvert::strBinTo2Complement(M.to_string()));
			M = T1;
		}
		else
		{
			if (M[_INT_128BIT - 1] == 0&&Q[_INT_128BIT - 1] == 1)
			{
				SignOfResultIsNagative = true;
				bitset<_INT_128BIT> T(CConvert::strBinTo2Complement(Q.to_string()));
				Q = T;
			}
		}
	}
	int n = _INT_128BIT;
	for (int i = 0; i < _INT_128BIT; i++)
	{
		A = A << 1;//Dịch trái bit 1 đơn vị
		if (Q[_INT_128BIT-1]==1)
		{
			A[0] = 1;
		}
		Q = Q << 1;
		bitset<_INT_128BIT> B((QInt(A.to_string()) - QInt(M.to_string())).ToString());//B tạm thời chứa kết quả A-M
		if (B[_INT_128BIT-1]==0)//Nếu A >= 0
		{
			A = B;
			Q[0] = 1;
		}
		else //A < 0
		{
			Q[0] = 0;
		}
	}
	if (SignOfResultIsNagative)//Nếu kết quả là số âm phải chuyển về dạng bù 2
	{
		return QInt(CConvert::strBinTo2Complement(Q.to_string()));
	}
	return QInt(Q.to_string());
}