#include"QInt_16bytes.h"
#include"CConvert.h"


using namespace std;

int main()
{
	bitset<8> a = 5;
	bitset<8> b = 5;
	QInt q1(a.to_string());
	QInt q2(b.to_string());
	QInt q3;
	q3 = q1 + q2;
	//cout << CConvert::strDecToBin("-4") << endl;
	QInt data("0000011110001");
	cout << sizeof(bitset<126>) << endl;
	//cout << data.NOT().ToString() << endl;
	//cout << CConvert::strBinTo2Complement("1111111110000000000") << endl;

	system("pause");
	return 0;
}