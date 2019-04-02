#ifndef __CConvert_H__
#define __CConvert_H__

#include <iostream>
#include <string>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

class CConvert {
public:
	//Chuyển đổi nhị phân sang thập lục phân và ngược lại
	static string strBinToHex(string strBin);
	static string strHexToBin(string strDec);
	//Chuyển đổi thập phân sang nhị phân
	static string strDecToBin(string strDec);
	static string strBinToDec(string strBin);
	
	//Chuyển dổi thâp phân sang thập lục phân và ngược lại
	static string strDecToHex(string strDec);
	static string strHexToDex(string strHex);

	static string ConvertAll(string, int, int);
	//Chuyển chuỗi bit thường sang chuỗi bit bù 2
	//Nếu truyền vào dãy bit của số 12 thì sẽ trả về chuỗi bit biểu diễn số -12
	static string strBinTo2Complement(string str_src);


	//Chia 2 giá trị của chuỗi  thập phân
	static string Div2_StrDec(string str_src);
	//Cộng 2 chuỗi thập phân
	static string Sum_strDec(string strDec1, string strDec2);
	//Nhân 2 chuỗi thập phân
	static string Mult_strDec(string Dec1, string strDec2);
	//Trả về chuỗi giá trị của 2 lũy thừa K
	static string _2Expn_K(int k);
	
	//Xóa Bit 0 ở đầu dãy nhị phân
	static void DelBit0(string &strSrc);
	//Đảo ngược chuỗi nhị phân
	static void Reserve_Str(string &str_Src);

	//đếm số dấu cách trong chuỗi
	static int Count_cSpacing(const string&);
	//Hàm trả về chữ đầu tiên của chuỗi và xóa chữ đó kèm khoảng trắng sau chuỗi đó
	static string FirstWord(string&);

	//Thực hiện các phép toán trên bit
	//Có 2 hàm tùy vào đối số truyền vào
	static string Operator(string, int, string);
	static string Operator(string, string, int, string);
};


#endif // !__CConvert_H__
