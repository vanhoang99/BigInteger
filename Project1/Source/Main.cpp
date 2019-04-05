
#include"QInt_16bytes.h"
#include"Convert.h"
#include<fstream>
#include"Calculator.h"
#include"Utility.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main(int argc, char *argv[])
{
	//Đảm bảo đủ 2 tham số truyền vào để thực hiện chương trình
	if (argc<=2){
		cout << "Khong du tham so de chay chuong trinh!" << endl;
		return 0;
	}
	
	//Khởi tạo 2 chuỗi:
	//fPath_Src: đường dẫn tới file đề
	//fPath_Res: đường dẫn tới file kết quả
	string fPath_Src = argv[1];
	string fPath_Res = argv[2];

	//Xử lý file
	fstream fSrc, fRes;
	fSrc.open(fPath_Src, ios_base::in);
	if (fSrc.is_open()==false)
	{
		return 0;
	}
	fRes.open(fPath_Res, ios_base::out);

	//Xử lý dữ liệu file
	//Xử lý theo dừng dòng cho đến dòng cuối cùng
	while (!fSrc.eof())
	{
		string strLineFile;//Chuõi chứa giá trị của dòng đang xét
		string strLineRes;
		getline(fSrc, strLineFile);
		

		/*
		Sau khi tìm hiểu cấu trúc của file mẫu, tụi em quyết định dựa vào dấu cách để xử lý dữ liệu
		Có 2 trường hợp xảy ra khi xử lý bằng khoảng trắng:
		+ Dòng có 2 khoảng trắng: Gồm những phép chuyển đổi dữ liệu (ví dụ : đổi từ 2 dạng hệ 10) và có phép nhị phân trên chính nó ( NOT,ROL,ROR)
		+ Dòng có 3 khoảng trắng: Gồm những phép toán như (+,-,*,/,&,^,|,<<,>>)
		*/

		//Bắt đầu xử lý khoảng trắng
		int numOfSpacing;
		numOfSpacing= CUtility::Count_cSpacing(strLineFile);//Đếm số dấu cách của chuỗi
		if (numOfSpacing == 2)//Trường hợp 2 khoảng trắng
		{
			//Lấy 2 chỉ thi p1 và p2
			string Temp = strLineFile;
			string p1 = CUtility::FirstWord(Temp);
			string p2 = CUtility::FirstWord(Temp);
			string strNum1 = CUtility::FirstWord(Temp);
			if (p2[0]>'0'&& p2[0]<'9')//Xét trường hợp chỉ thị p2 bắt đầu là một số nguyên tức là lệnh chuyển đổi hệ (convert)
			{
				strLineRes =CConvert::ConvertAll(strNum1, stoi(p1), stoi(p2));
			}
			else//Các phép tính ~, rol, ror
			{
				strLineRes = CCalculator::Operator(strNum1, stoi(p1), p2);
			}
		}
		else//Xử lý trưởng hợp còn lại
		{
			
			if (numOfSpacing == 3)//Các phép tính +, -, *, /, &, ^, |, <<, >>
			{
				string Temp = strLineFile;
				string p1 = CUtility::FirstWord(Temp);
				string strNum1 = CUtility::FirstWord(Temp);
				string p2 = CUtility::FirstWord(Temp);
				string strNum2 = CUtility::FirstWord(Temp);
				strLineRes = CCalculator::Operator(strNum1, strNum2 ,stoi(p1), p2);
			}
			else//Trường hợp không đọc được đinh dạng
			{
				strLineRes = "0";
			}
		}
		CUtility::DelBit0(strLineRes);
		//Xuất vào file kết quả
		fRes << strLineRes << endl;
	}
	fSrc.close();
	fRes.close();

	system("pause");
	return 0;
}