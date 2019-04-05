#ifndef __CConvert_H__
#define __CConvert_H__

#include <iostream>
#include <string>
using namespace std;

//Định nghĩa các hằng cơ số
#define _BASE_DEC 10
#define _BASE_BIN 2
#define _BASE_HEX 16


//Class chứa chứa các phương thức có chức năng chuyển đổi cơ số
//Tất các có đối số và trả về đều là chuỗi string để thống nhât và dễ dàng chuyển đổi qua lại
class CConvert {
public:
	//Hàm chuyển đổi chung giữa các hệ cơ số
	static string ConvertAll(string, int, int);

	//Chuyển đổi nhị phân sang thập lục phân và ngược lại
	static string strBinToHex(string strBin);
	static string strHexToBin(string strDec);

	//Chuyển đổi thập phân sang nhị phân
	static string strDecToBin(string strDec);
	static string strBinToDec(string strBin);
	
	//Chuyển dổi thâp phân sang thập lục phân và ngược lại
	static string strDecToHex(string strDec);
	static string strHexToDec(string strHex);



	//Chuyển chuỗi bit thường sang chuỗi bit bù 2
	//Nếu truyền vào dãy bit của số 12 thì sẽ trả về chuỗi bit biểu diễn số -12
	static string strBinTo2Complement(string str_src);


	



};


#endif // !__CConvert_H__
