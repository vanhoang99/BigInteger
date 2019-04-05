#include"Convert.h"
#include"QInt_16bytes.h"
#include"Calculator.h"
#include"Utility.h"
/*
Hàm chuyển đổi cơ số: từ nhị phân sang thập lục phân
Tham số: chuỗi ký tự nhị phân (string)
Kết quả trả về: chuỗi ký tự thập lục phân (string)

*/
string CConvert::strBinToHex(string strBin) {
	int len = strBin.length();//Độ dài của chuỗi
	if (len>_INT_128BIT)//Định dạng đầu vào không hợp lệ
	{
		
		return "0";
	}
	while (len % 4 != 0)//điều chỉnh chuỗi thành những khối 4 bit
	{
		strBin = '0' + strBin; 
		len++;
	}
	string strHex;//Chuỗi hexa chứa kết quả
	int n = len / 4;//Số khối 4 bit
	char tabHex[] = "0123456789ABCDEF";//Bảng chứa giá bị hexa tương ứng với giá trị của khối 4 bit
	for (int i = 0; i < n; i++)//Xét từng khối 4 bit
	{
		int Temp = 0;//Biến tạm chứa giá trị của từng khối 4 bit
		for (int j = 0; j <= 3; j++)
		{

			if (strBin[j]=='1')//Bằng 1 thì tính giá trị ở dạng thập phân tương ứng
			{ 
				Temp += 1 << (3-j);//Dịch phải 3-j tức là 2^(3-j)
			}
			else
			{
				if (strBin[j]!='0')//Nếu khác 0 tức chuỗi chứa nhưng ký tự khác 0 và 1 nên không hợp lệ, trả về "0"
				{
					return "0";
				}
			}
		}
		strBin.erase(strBin.begin(), strBin.begin() + 4);//Xóa khối 4 bit đầu trong chuỗi Binary đã tính toán
		strHex = strHex + tabHex[Temp];//Chuyển giá trị tính được thành hexa và thêm vào
	}
	return strHex;
}

/*
Hàm chuyển đổi  từ nhị phân sang thập lục phân
Tham số: chuỗi ký tự thập lục phân (string)
Kết quả trả về: chuỗi ký nhị phân (string)
*/
string CConvert::strHexToBin(string strHex) {
	string strBin = "";
	int len = strHex.length();
	for (int i = 0; i < len; i++)
	{
		switch (strHex[i])
		{
		case '0':
			strBin += "0000";
			break;
		case '1':
			strBin += "0001";
			break;
		case '2':
			strBin += "0010";
			break;
		case '3':
			strBin += "0011";
			break;
		case '4':
			strBin += "0100";
			break;
		case '5':
			strBin += "0101";
			break;
		case '6':
			strBin += "0110";
			break;
		case '7':
			strBin += "0111";
			break;
		case '8':
			strBin += "1000";
			break;
		case '9':
			strBin += "1001";
			break;
		case 'A':
		case 'a':
			strBin += "1010";
			break;
		case 'B':
		case 'b':
			strBin += "1011";
			break;
		case 'C':
		case 'c':
			strBin += "1100";
			break;
		case 'D':
		case 'd':
			strBin += "1101";
			break;
		case 'E':
		case 'e':
			strBin += "1110";
			break;
		case 'F':
		case 'f':
			strBin += "1111";
			break;
		default:
			return "0";
			break;
		}
	}
	CUtility::DelBit0(strBin);//Xóa nhưng bit 0 ở đầu
	return strBin;
}

//Chuyển chuỗi cơ số 10 sang 2
string CConvert::strDecToBin(string strDec)
{
	string strResult = "";
	bool Nagative = false;
	if (strDec[0]=='-')
	{
		Nagative = true;
		strDec.erase(strDec.begin());
	}
	while (strDec != "0")
	{
		if ((strDec[strDec.length() - 1] - '0') % 2 == 1)
		{
			strResult = "1" + strResult;
		}
		else
		{
			strResult = "0" + strResult;
		}
		strDec = CCalculator::Div2_StrDec(strDec);
		
	}
	if (Nagative)
	{
		strResult= CConvert::strBinTo2Complement(strResult);
	}
	CUtility::DelBit0(strResult);
	return strResult;
}

//Chuyển chuỗi cơ số 10 sang 2
string CConvert::strDecToHex(string strDec)
{
	return strBinToHex(strDecToBin(strDec));
}

//Chuyển chuỗi cơ số 16 sang 10
string CConvert::strHexToDec(string strHex)
{
	return strBinToDec(strHexToBin(strHex));
}


//Chuyển chuỗi cơ số 2 sáng 10
string CConvert::strBinToDec(string strBin) {
	int len = strBin.length();
	if (len >_INT_128BIT)
	{
		return "0";
	}
	bool Nagative = false;
	string strResult = "0";
	if ((strBin[0] == '1') && (len == _INT_128BIT))
	{
		Nagative = true;
		strBin = CConvert::strBinTo2Complement(strBin);
		len = strBin.length();
	}
	string strTemp = "1";
	CUtility::Reserve_Str(strBin);
	for (int i = 0; i < len; i++)
	{
		if (i!=0)
		{
			strTemp = CCalculator::Sum_strDec(strTemp, strTemp);
		}
		if (strBin[i] == '1')
		{
			
			strResult = CCalculator::Sum_strDec(strResult, strTemp);
		}
	}
	if (Nagative)
	{
		strResult = "-" + strResult;
	}
	return strResult;
}

//Chuyễn chuỗi nhị phân sang dạng bù 2
string CConvert::strBinTo2Complement(string str_src){
	//Vượt quá phạm vi lưu trữ trả về 0
	if (str_src.length()>_INT_128BIT)
	{
		return "0";
	}
	string strResult = "";
	QInt qNum(str_src);
	qNum = qNum.NOT();
	qNum = qNum + QInt("1");
	strResult = qNum.ToString();
	return strResult;
}



//Hàm chuyển đổi chung giữa các hệ cơ số:
//strSrc: chuỗi số cần chuyển
//p1: cơ số của chuỗi truyền vào
//p2: cơ số trả về
string CConvert::ConvertAll(string strSrc, int p1, int p2)
{
	if (p1==p2)
	{
		return strSrc;
	}
	switch (p1)
	{
	case 2:
	{
		switch (p2)
		{
		case 10:
			return CConvert::strBinToDec(strSrc);
		case 16:
			return CConvert::strBinToHex(strSrc);
		default:
			return "0";
		}
	}
	case 10:
		switch (p2)
		{
		case 2:
			return CConvert::strDecToBin(strSrc);
		case 16:
			return CConvert::strDecToHex(strSrc);
		default:
			return "0";
		}
	case 16:
		switch (p2)
		{
		case 2:
			return CConvert::strHexToBin(strSrc);
		case 10:
			return CConvert::strHexToDec(strSrc);
		default:
			return "0";
		}
	default:
		return "0";
	}
}


