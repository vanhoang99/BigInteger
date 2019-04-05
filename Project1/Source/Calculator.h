#ifndef __CALCULATOR_H__

#include<iostream>
using namespace std;


class CCalculator {

public:
	//Chia 2 giá trị của chuỗi  thập phân
	static string Div2_StrDec(string str_src);
	//Cộng 2 chuỗi thập phân
	static string Sum_strDec(string strDec1, string strDec2);
	//Nhân 2 chuỗi thập phân
	static string Mult_strDec(string Dec1, string strDec2);
	//Trả về chuỗi giá trị của 2 lũy thừa K
	static string _2Expn_K(int k);

	//Thực hiện các phép toán trên bit
	//Có 2 hàm tùy vào đối số truyền vào
	static string Operator(string, int, string);
	static string Operator(string, string, int, string);
};
#endif // !__CALCULATOR_H__
