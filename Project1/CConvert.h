#ifndef __CConvert_H__
#define __CConvert_H__

#include <iostream>
#include <string>
using namespace std;

#define _MAXBIT 128

class CConvert {
public:
	//Chuyển đổi nhị phân sang thập lục phân và ngược lại
	static string strBinToHex(string strBin);
	static string strHexToBin(string strDec);
	//Chuyển đổi thập phân sang nhị phân
	static string strDecToBin(string strDec);
	static string strBinToDec(string strBin);
	
	//Chuyển chuỗi bit thường sang chuỗi bit bù 2
	//Nếu truyền vào dãy bit của số 12 thì sẽ trả về chuỗi bit biểu diễn số -12
	static string strBinTo2Complement(string str_src);

	static void DelBit0(string &strSrc);
	static void Reserve_Str(string &str_Src);
};
//Chia 2 giá trị của chuỗi  thập phân
string _Div2_StrDec(string str_src);
//Cộng 2 chuỗi thập phân
string _Sum_strDec(string strDec1, string strDec2);
//Trả về chuỗi giá trị của 2 lũy thừa K
string _2Expn_K(int k);

#endif // !__CConvert_H__
