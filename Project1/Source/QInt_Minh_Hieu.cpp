#include"QInt_16bytes.h"
#include"CConvert.h"
//Code của Minh Hiếu


QInt QInt::Rotate_right()
{
	bitset<_INT_128BIT> arrBitResult(this->ToString()); //tạo chuỗi kết quả lưu tại chuỗi truyền vào
	char temp = arrBitResult[0]; //biến temp giữ lại phần tử cuối cùng của chuỗi
	for (int i =0; i <=_INT_128BIT - 2; i++)//vòng for chạy từ phần tử ở vị trí  cuối cùng đến phần tử thứ 1 của chuỗi
	{
		arrBitResult[i] = arrBitResult[i + 1]; //dịch bit sang phải. tức gán giá trị ở vị trí sau cho nó.
	}
	arrBitResult[_INT_128BIT - 1] = temp; //gán giá trị của biến cuối cùng, tức hiện giờ là biến temp cho phần tử đầu tiên của chuỗi strResult
	return QInt(arrBitResult.to_string());
}

QInt QInt::Rotate_left()
{
	bitset<_INT_128BIT> arrBitResult(this->ToString()); //tạo chuỗi kết quả lưu tại chuỗi truyền vào
	char temp = arrBitResult[_INT_128BIT - 1]; //biến temp giữ lại phần tử cuối cùng của chuỗi
	for (int i = _INT_128BIT - 1; i >= 1; i--)//vòng for chạy từ phần tử ở vị trí  cuối cùng đến phần tử thứ 1 của chuỗi
	{
		arrBitResult[i] = arrBitResult[i - 1]; //dịch bit sang phải. tức gán giá trị ở vị trí sau cho nó.
	}
	arrBitResult[0] = temp; //gán giá trị của biến cuối cùng, tức hiện giờ là biến temp cho phần tử đầu tiên của chuỗi strResult
	return QInt(arrBitResult.to_string());
}