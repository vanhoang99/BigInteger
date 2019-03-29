#include"QInt_16bytes.h"
#include"CConvert.h"


using namespace std;

int main()
{	
	//cout << CConvert::strDecToBin("123") << endl; // 10 -> 2
	//cout << CConvert::strBinToDec((QInt(CConvert::strDecToBin("-100")) - QInt(CConvert::strDecToBin( "50"))).ToString())<<endl;
	cout<< _Mult_strDec("123456789", "-123456789") << endl;
	cout<<
	system("pause");
	return 0;
}