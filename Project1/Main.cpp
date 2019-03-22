#include"QInt_16bytes.h"
#include"CConvert.h"


using namespace std;

int main()
{
	cout << CConvert::strDecToBin("123") << endl;
	cout << CConvert::strBinToDec(CConvert::strDecToBin("-12345678999999999999999999")) << endl;
	system("pause");
	return 0;
}