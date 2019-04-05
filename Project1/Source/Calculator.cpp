#include"Calculator.h"
#include"Convert.h"
#include"QInt_16bytes.h"
#include"Utility.h"

//Hàm thực hiện phép toán Bit 2 đối số: ~,<<,>>
string CCalculator::Operator(string strSrc, int base, string opt) {

	QInt qNum;
	switch (base)
	{
	case _BASE_BIN:
		qNum = QInt(strSrc);
		break;
	case _BASE_DEC:
		qNum = QInt(CConvert::ConvertAll(strSrc, _BASE_DEC, _BASE_BIN));
		break;
	case _BASE_HEX:
		qNum = QInt(CConvert::ConvertAll(strSrc, _BASE_HEX, _BASE_BIN));
		break;
	default:
		return "";
	}

	string ListOpt[] = { "~","ror","rol" };

	int i = 0;
	for (; i < 3; i++)
	{
		if (opt == ListOpt[i])
		{
			break;
		}
	}
	switch (i)
	{
	case 0:
		return CConvert::ConvertAll(qNum.NOT().ToString(), _BASE_BIN, base);
	case 1:
		return CConvert::ConvertAll(qNum.Rotate_right().ToString(), _BASE_BIN, base);
	case 2:
		return CConvert::ConvertAll(qNum.Rotate_left().ToString(), _BASE_BIN, base);
	default:
		return "";
	}
	return "";
}

//Thực hiện các phép +,-,*,/,&,|,<<,>>
//strSrc1,strSrc2: là chuỗi số cần thao tác
//base: cơ số của 2 chuỗi truyền vào, và cũng là cơ số trả về của phép tính
//Opt: phép tính cần thực hiện
string CCalculator::Operator(string strSrc1, string strSrc2, int base, string opt) {
	string ListOpt[] = { "&","|","^","+","-","*","/","<<",">>" };

	QInt qNum1;
	QInt qNum2;
	switch (base)
	{
	case _BASE_BIN:
		qNum1 = QInt(strSrc1);
		qNum2 = QInt(strSrc2);
		break;
	case _BASE_DEC:
		qNum1 = QInt(CConvert::ConvertAll(strSrc1, _BASE_DEC, _BASE_BIN));
		qNum2 = QInt(CConvert::ConvertAll(strSrc2, _BASE_DEC, _BASE_BIN));
		break;
	case _BASE_HEX:
		qNum1 = QInt(CConvert::ConvertAll(strSrc1, _BASE_HEX, _BASE_BIN));
		qNum2 = QInt(CConvert::ConvertAll(strSrc2, _BASE_HEX, _BASE_BIN));
		break;
	default:
		return "";
	}

	int i = 0;
	for (; i < 9; i++)
	{
		if (opt == ListOpt[i])
		{
			break;
		}
	}
	cout << qNum1.ToString() << endl;
	switch (i)
	{
	case 0:
		return CConvert::ConvertAll(qNum1.AND(qNum2).ToString(), _BASE_BIN, base);
	case 1:
		return CConvert::ConvertAll(qNum1.OR(qNum2).ToString(), _BASE_BIN, base);
	case 2:
		return CConvert::ConvertAll(qNum1.XOR(qNum2).ToString(), _BASE_BIN, base);
	case 3:
		return CConvert::ConvertAll((qNum1 + qNum2).ToString(), _BASE_BIN, base);
	case 4:
		return CConvert::ConvertAll((qNum1 - qNum2).ToString(), _BASE_BIN, base);
	case 5:
		return CConvert::ConvertAll((qNum1 * qNum2).ToString(), _BASE_BIN, base);
	case 6:
		return CConvert::ConvertAll((qNum1 / qNum2).ToString(), _BASE_BIN, base);
	case 7:
		return CConvert::ConvertAll(qNum1.Shift_Arithmetic_Left(stoi(strSrc2)).ToString(), 2, base);
	case 8:
		return CConvert::ConvertAll(qNum1.Shift_Arithmetic_Right(stoi(strSrc2)).ToString(), 2, base);
	default:
		return "";
	}
	return "";
}

//Cộng 2 chuỗi số thập phân, trả về chuỗi kết quả
string CCalculator::Sum_strDec(string strDec1, string strDec2) {

	string strResult = "";//chuỗi chứa kết quả
	int len_max = strDec1.length();//khởi tạo độ dài chuỗi lớn nhất tạm thời bằng độ dài chuỗi 1
	string strTemp;//
	//Tìm độ dài lớn nhất trong 2 chuỗi và thêm số 0 vào đầu chuỗi để 2 chuỗi có độ dài bằng nhau tiện tính toán
	if (len_max >= strDec2.length())
	{
		strDec2 = strTemp.assign(len_max - strDec2.length(), '0') + strDec2;
	}
	else
	{
		len_max = strDec2.length();
		strDec1 = strTemp.assign(len_max - strDec1.length(), '0') + strDec1;
	}
	//Biến tạm chứa số dư khi cộng
	int iTemp = 0;
	//Đảo 2 chuỗi số để tiện tính toán
	CUtility::Reserve_Str(strDec1);

	CUtility::Reserve_Str(strDec2);
	//thực hiện cộng từng hàng đơn vị từ nhỏ đến lớn
	for (int i = 0; i < len_max; i++)
	{
		iTemp = (strDec1[i] - '0') + (strDec2[i] - '0') + iTemp;
		//2 trường hợp khi cộng 
		if (iTemp <= 9)
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
	if (iTemp == 1)//Nếu vẫn còn nợ 1 thì cộng thêm vào đâu chuỗi kết quả
	{
		strResult = '1' + strResult;
	}
	return strResult;
}

//Hàm tính và trả về chuỗi kết quả của 2 lũy thừa k
string  CCalculator::_2Expn_K(int k) {
	string strResult = "1";
	for (int i = 0; i < k; i++)
	{
		strResult = CCalculator::Sum_strDec(strResult, strResult);
	}
	return strResult;
}

//Hàm tính tích 2 chuối số thập phân và trả về chuỗi số kết quả
string  CCalculator::Mult_strDec(string strDec1, string strDec2) {
	string strResult = "0";
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
	CUtility::Reserve_Str(strDec1);
	CUtility::Reserve_Str(strDec2);

	//2 vòng lặp thực hiện công việc nhân từng hàng đơn vị của strDec2 cho chuỗi strDec1
	for (int i = 0; i < strLen2; i++)//Xét từng số trong strDec2
	{
		strTemp = "";
		for (int j = 0; j < strLen1; j++)//Xét từng số trong strDec1
		{
			iTemp = (strDec1[j] - '0')*(strDec2[i] - '0') + iTemp;
			strTemp = (char)((iTemp % 10) + '0') + strTemp;
			iTemp = iTemp / 10;
		}
		//Nếu biến nhớ tạm khác 0 thì cộng vào đầu kết quả nhân và đặt lại biến nhớ bằng 0 cho lần nhân tiếp theo
		if (iTemp != 0)
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
		strResult = CCalculator::Sum_strDec(strResult, strTemp);
	}
	if (ResultIsNagative)
	{
		strResult = "-" + strResult;
	}
	return strResult;
}

//Hàm chia 2 số thập phân ở dạng chuỗi,trả về chuỗi kết quả số nguyên làm tròn xuống
string CCalculator::Div2_StrDec(string str_src)
{
	CUtility::DelBit0(str_src);
	if (str_src == "0" || str_src == "1")
	{
		return "0";
	}
	int len = str_src.length();
	int iTemp = 0;
	string strResult = "";
	for (int i = 0; i < len; i++)
	{
		iTemp = (iTemp * 10) + str_src[i] - '0';
		strResult = strResult + (char)((iTemp / 2) + '0');
		iTemp = iTemp % 2;
	}
	CUtility::DelBit0(strResult);
	return strResult;
}