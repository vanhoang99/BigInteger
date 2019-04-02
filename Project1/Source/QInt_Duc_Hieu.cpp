#include"QInt_16bytes.h"
#include"CConvert.h"
//Code của Đức Hiếu

//=====AND===
QInt QInt::AND(QInt Qnum) {

	bitset<_INT_128BIT> arrBitsResult;
	for (int i = 0; i < _INT_128BIT; i++) {

		arrBitsResult[i] = Qnum.arrBits[i] * arrBits[i];
	}
	return QInt(arrBitsResult.to_string());
}
//======OR=====
QInt QInt::OR(QInt Qnum) {
	bitset<_INT_128BIT> arrBitsResult;
	for (int i = 0; i < _INT_128BIT; i++) {
		arrBitsResult[i] = Qnum.arrBits[i] + arrBits[i];
		if (Qnum.arrBits[i] == 1 && arrBits[i] == 1) {
			arrBitsResult[i] = 1;
		}
	}
	return QInt(arrBitsResult.to_string());
}
//========XOR=====
QInt QInt::XOR(QInt Qnum) {

	bitset<_INT_128BIT> arrBitsResult;

	for (int i = 0; i < _INT_128BIT; i++) {
		if (Qnum.arrBits[i] == arrBits[i]) {
			arrBitsResult[i] = 0;
		}
		else {
			arrBitsResult[i] = 1;
		}
	}

	return QInt(arrBitsResult.to_string());
}

//=====dich phai so hoc====
//Vẫn giữ lại dấu của số
QInt QInt::Shift_Arithmetic_Right(int n) {
	bitset<_INT_128BIT> arrBitsResult=arrBits;
	int bitSign = arrBits[_INT_128BIT - 1];
	for (int T = 0; T < n; T++)
	{
		for (int i = 0; i <= _INT_128BIT - 3; i++) {
			arrBitsResult[i] = arrBitsResult[i + 1];
		}
		arrBitsResult[_INT_128BIT - 2] = 0;
	}
	arrBitsResult[_INT_128BIT - 1] = bitSign;
	return QInt(arrBitsResult.to_string());
}

//=====dich trai so hoc====
QInt QInt::Shift_Arithmetic_Left(int n) {
	bitset<_INT_128BIT> arrBitsResult = arrBits;
	int bitSign = arrBits[_INT_128BIT - 1];
	for (int T = 0; T < n; T++)
	{
		for (int i = _INT_128BIT - 2; i >= 1; i--) {
			arrBitsResult[i] = arrBitsResult[i - 1];
		}
		arrBitsResult[0] = 0;
	}
	arrBitsResult[_INT_128BIT - 1] = bitSign;
	return QInt(arrBitsResult.to_string());
}