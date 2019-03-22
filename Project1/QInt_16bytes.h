	#ifndef __QInt_16bytes_H__

	#include<iostream>
	#include<bitset>
	#include<string>
	using namespace std;

	#define _INT_128BIT 128
	/*
	Lớp Qint: Biểu diễn số nguyên với độ lớn 16 bytes(128 bit).
	Được lưu trữ dưới dạng số nhị phân bù 2, các bit được lưu trong mảng bitset<128> chiếm đúng 128bit của bộ nhớ
	Các bit được lưu trữ theo Litte Endian

	Hình vẽ:
	Chuỗi bit nhị phân: 11011110111110110000
																											arrBits<128>
	||0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|25|27|28|29|30|31|32|33|34|35|36|......|113|114|115|116|117|118|119|120|121|122|123|124|125|126|127||
	||0 |0 |0 |0 |1 |1 |0 |1 |1 |1 |1 |1 |0 |1 |1 |1 |1 |0 |1 |1 |0 |0 |0 |0 |0 |0 |0 |0 |0 |0 |0 |0 |0 |0 |0 |0 |0 |......|0  |0  |0  |0  |0  |0  |0  |0  |0  |0  |0  |0  |0  |0  |0  ||
	*/

	class QInt {
	private:
		bitset<128> arrBits;
	public:
		QInt() {};
		QInt(string strBin);
		string ToString();
		QInt NOT();
		QInt operator+(QInt);
	};
	#endif // !__QInt_16bytes_H__
