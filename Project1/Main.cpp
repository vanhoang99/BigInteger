#include"QInt_16bytes.h"
#include"CConvert.h"


using namespace std;

int main()
{
	cout << CConvert::strDecToBin("123") << endl;
	cout << CConvert::strBinToDec(CConvert::strBinTo2Complement(CConvert::strDecToBin("-1234567899"))) << endl;
	cout << CConvert::strBinToHex(CConvert::strHexToBin("FFFFFFFFAC234234123")) << endl;
	system("pause");
	return 0;
}