#ifndef __CConvert_H__
#define __CConvert_H__

#include<iostream>
#include<string>
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

	static string strBinTo2Complement(string str_src);

	static void DelBit0(string &strSrc);
	static void Reserve_Str(string &str_Src);
};
string _Div2_StrDec(string str_src);

#endif // !__CConvert_H__
