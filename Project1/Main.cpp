#include"QInt_16bytes.h"
#include"CConvert.h"


using namespace std;

int main()
{
	cout << CConvert::strDecToBin("123") << endl; // 10 -> 2
	cout << CConvert::strBinToDec(CConvert::strBinTo2Complement(CConvert::strDecToBin("-1234567899"))) << endl;
	cout << CConvert::strBinToHex(CConvert::strHexToBin("FFFFFFFFAC234234123")) << endl;
	//strDecToHec() và strHexToDec() sẻ dụng lại hàm trên nên việc test lại không cần thiểt!!!


	system("pause");
	return 0;
}