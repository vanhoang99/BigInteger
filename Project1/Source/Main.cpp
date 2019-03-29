#include"QInt_16bytes.h"
#include"CConvert.h"


using namespace std;

int main()
{
	cout << CConvert::strDecToBin("123") << endl; // 10 -> 2
	cout << CConvert::strBinToDec(CConvert::strDecToBin("65484686846684641684846464686")) << endl;
	//strDecToHec() và strHexToDec() sẻ dụng lại hàm trên nên việc test lại không cần thiểt!!!
	system("pause");
	return 0;
}