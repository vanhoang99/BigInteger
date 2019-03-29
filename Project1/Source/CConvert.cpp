﻿#include"CConvert.h"
#include"QInt_16bytes.h"

/*
Hàm chuyển đổi cơ số: từ nhị phân sang thập lục phân
Tham số: chuỗi ký tự nhị phân (string)
Kết quả trả về: chuỗi ký tự thập lục phân (string)

*/
string CConvert::strBinToHex(string strBin) {
	int len = strBin.length();//Độ dài của chuỗi
	if (len>_MAXBIT)//Định dạng đầu vào không hợp lệ
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
	CConvert::DelBit0(strBin);//Xóa nhưng bit 0 ở đầu
	return strBin;
}

string CConvert::strDecToBin(string strDec)
{
	string strResult = "";
	//int len = strDec.length();
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
		strDec = _Div2_StrDec(strDec);
		
	}
	if (Nagative)
	{
		strResult= CConvert::strBinTo2Complement(strResult);
	}
	CConvert::DelBit0(strResult);
	return strResult;
}


string CConvert::strDecToHex(string strDec)
{
	return strBinToHex(strDecToBin(strDec));
}

string CConvert::strHexToDex(string strHex)
{
	return strBinToDec(strHexToBin(strHex));
}

//Hàm chia 2 số thập phân ở dạng chuỗi,trả về chuỗi kết quả số nguyên làm tròn xuống
string _Div2_StrDec(string str_src)
{
	if (str_src == "0"||str_src=="1")
	{
		return "0";
	}
	int len = str_src.length();
	int iTemp = 0;
	string strResult="";
	for (int i = 0; i < len; i++)
	{
		iTemp = (iTemp * 10) + str_src[i] - '0';
		strResult = strResult + (char)((iTemp / 2) + '0');
		iTemp = iTemp % 2;
	}
	CConvert::DelBit0(strResult);
	return strResult;
}

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
	CConvert::Reserve_Str(strBin);
	for (int i = 0; i < len; i++)
	{
		if (i!=0)
		{
			strTemp = _Sum_strDec(strTemp, strTemp);
		}
		if (strBin[i] == '1')
		{
			
			strResult = _Sum_strDec(strResult, strTemp);
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
	/*int len = str_src.length();
	string strResult = "";
	for (int i = 0; i < len; i++)
	{
		if (str_src[i]=='1')
		{
			strResult = strResult + "0";
		}
		else
		{
			strResult = strResult + "1";
		}
	}
	while (len<_INT_128BIT)
	{
		strResult = '1' + strResult;
	}
	cout <<strResult<< endl;
	QInt qint(strResult);
	qint = qint + QInt("1");
	return qint.ToString();*/
	return strResult;
}


//Hàm Xóa Bit 0 ở đầu chuỗi
void CConvert::DelBit0(string &strSrc){
	while (strSrc[0] == '0')//Xóa nhưng bit 0 ở đầu
	{
		strSrc.erase(strSrc.begin());
	}
}
//Đảo ngược chuỗi string truyền vào
void CConvert::Reserve_Str(string &str_Src){
	string strTemp = str_Src;
	int len = strTemp.length();
	for (int i = 0; i < len; i++)
	{
		str_Src[i] = strTemp[len - 1 - i];
	}
}

string _Sum_strDec(string strDec1, string strDec2) {

	string strResult = "";//chuỗi chứa kết quả
	int len_max = strDec1.length();//khởi tạo độ dài chuỗi lớn nhất tạm thời bằng độ dài chuỗi 1
	string strTemp;//
	//Tìm độ dài lớn nhất trong 2 chuỗi và thêm số 0 vào đầu chuỗi để 2 chuỗi có độ dài bằng nhau tiện tính toán
	if (len_max>=strDec2.length())
	{
		strDec2 = strTemp.assign(len_max - strDec2.length(), '0')+ strDec2;
	}
	else
	{
		len_max = strDec2.length();
		strDec1 = strTemp.assign(len_max - strDec1.length(), '0') + strDec1;
	}
	//Biến tạm chứa số dư khi cộng
	int iTemp=0;
	//Đảo 2 chuỗi số để tiện tính toán
	CConvert::Reserve_Str(strDec1);
	CConvert::Reserve_Str(strDec2);
	//thực hiện cộng từng hàng đơn vị từ nhỏ đến lớn
	for (int i = 0; i < len_max; i++)
	{
		iTemp = (strDec1[i]-'0') + (strDec2[i]-'0') + iTemp;
		//2 trường hợp khi cộng 
		if (iTemp<=9)
		{
			strResult = (char)(iTemp + '0') + strResult;
			iTemp = 0;//không nợ
		}
		else
		{
			strResult = (char)((iTemp % 10) + '0') + strResult;
			iTemp = 1;//Nợ 1
		}
	}
	if (iTemp==1)//Nếu vẫn còn nợ 1 thì cộng thêm vào đâu chuỗi kết quả
	{
		strResult = '1' + strResult;
	}
	return strResult;
}

//Hàm tính và trả về chuỗi kết quả của 2 lũy thừa k
string _2Expn_K(int k) {
	string strResult = "1";
	for (int i = 0; i < k; i++)
	{
		strResult = _Sum_strDec(strResult, strResult);
	}
	return strResult;
}

string _Mult_strDec(string strDec1,string strDec2) {
	string strResult="0";
	string strTemp = "";
	int iTemp = 0;
	bool ResultIsNagative = false;//Kết quả là một số âm
	//Xử lý dấu của 2 chuỗi
	//
	if (strDec1[0] == '-' &&strDec2[0] == '-')
	{
		strDec1.erase(strDec1.begin());
		strDec2.erase(strDec2.begin());
	}
	else
	{
		if (strDec1[0] == '-')
		{
			strDec1.erase(strDec1.begin());
			ResultIsNagative = true;
		}
		if (strDec2[0] == '-')
		{
			strDec2.erase(strDec2.begin());
			ResultIsNagative = true;
		}
	}

	
	//Lấy độ dài 2 chuỗi số
	int strLen1 = strDec1.length();
	int strLen2 = strDec2.length();
	//Đảo 2 chuỗi số để tiện tính toán
	CConvert::Reserve_Str(strDec1);
	CConvert::Reserve_Str(strDec2);

	//2 vòng lặp thực hiện công việc nhân từng hàng đơn vị của strDec2 cho chuỗi strDec1
	for (int i = 0; i < strLen2; i++)//Xét từng số trong strDec2
	{
		strTemp = "";
		for (int j = 0; j < strLen1; j++)//Xét từng số trong strDec1
		{
			iTemp = (strDec1[j] - '0')*(strDec2[i] - '0') + iTemp;
			strTemp = (char)((iTemp % 10) + '0') + strTemp;
			iTemp = iTemp/10;
		}
		//Nếu biến nhớ tạm khác 0 thì cộng vào đầu kết quả nhân và đặt lại biến nhớ bằng 0 cho lần nhân tiếp theo
		if (iTemp!=0)
		{
			strTemp = (char)(iTemp + '0') + strTemp;
			iTemp = 0;
		}
		//Sau mỗi lần tăng đơn vị nhân của chuỗi 2  thì tăng kết quả nhân lên 1 đơn vị để cộng vào kết quả trước đó
		for (int k = 0; k < i; k++)
		{
			strTemp = strTemp + "0";
		}
		//Cộng từng lần nhân chuỗi số strDec1 cho từng đơn vị của strDec2
		strResult = _Sum_strDec(strResult, strTemp);
	}
	if (ResultIsNagative)
	{
		strResult = "-" + strResult;
	}
	return strResult;
}