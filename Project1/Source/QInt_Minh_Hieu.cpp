#include"QInt_16bytes.h"
//Code của Minh Hiếu


string CConvert::Rotate_left(const string &strbin)
{
	string strResult = strbin; //tạo chuỗi kết quả lưu tại chuỗi truyền vào
	int size_strbin = strbin.size(); //lấy độ dài chuỗi truyền vào
	char temp = strResult[0]; //biến temp giữ lại phần tử đầu tiên của chuỗi

	for (int i = 1; i < size_strbin - 1; i++) //vòng for chạy từ phần tử thứ 1 đến phần tử cuối cùng của chuỗi
	{
		strResult[i] = strResult[i + 1];//dịch bit sang trái. tức gán giá trị ở vị trí trước cho nó. giá tị vị trí 2 cho 1,  giá tị vị trí 3 cho 2, ...
	}
	//Sau khi kết thúc vòng lặp
	strResult[size_strbin - 1] = temp; //gán giá trị của biến đầu tiên, tức hiện giờ là biến temp cho phần tử cuối cùng của chuỗi strResult
	CConvert::DelBit0(strResult); //xóa các bit 0 ở đầu chuỗi
	return strResult;

}

string CConvert::Rotate_right(const string &strbin)
{
	string strResult = strbin; //tạo chuỗi kết quả lưu tại chuỗi truyền vào
	int size_strbin = strbin.size();//lấy độ dài chuỗi truyền vào
	char temp = strResult[size_strbin - 1]; //biến temp giữ lại phần tử cuối cùng của chuỗi

	for (int i = size_strbin - 1; i > 0; i--)//vòng for chạy từ phần tử ở vị trí  cuối cùng đến phần tử thứ 1 của chuỗi
	{
		strResult[i] = strResult[i - 1]; //dịch bit sang phải. tức gán giá trị ở vị trí sau cho nó.
	}
	//Sau khi kết thúc vòng lặp
	strResult[0] = temp; //gán giá trị của biến cuối cùng, tức hiện giờ là biến temp cho phần tử đầu tiên của chuỗi strResult
	CConvert::DelBit0(strResult);//xóa các bit 0 ở đầu chuỗi
	return strResult;
}