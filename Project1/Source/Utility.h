#ifndef  __Utility_H__

#include<iostream>
using namespace std;

class CUtility {
public:

	//Xóa Bit 0 ở đầu dãy nhị phân
	static void DelBit0(string &strSrc);
	//Đảo ngược chuỗi nhị phân
	static void Reserve_Str(string &str_Src);

	//đếm số dấu cách trong chuỗi
	static int Count_cSpacing(const string&);
	//Hàm trả về chữ đầu tiên của chuỗi và xóa chữ đó kèm khoảng trắng sau chuỗi đó
	static string FirstWord(string&);
};

#endif // ! __Utility_H__
