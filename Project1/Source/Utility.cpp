#include"Utility.h"

//Hàm tách cà trả về từ đâu tiên của chuỗi(tức là chuỗi ký tự liên tục đầu tiên cho đến khi gặp dấu cách), và xóa từ đầu tiền đó ra khỏi chuỗi truyền vào
string CUtility::FirstWord(string & strSrc) {
	if (strSrc.length() == 0)
	{
		return "";
	}
	string strFirstWord = "";
	while (strSrc[0] != ' ' && strSrc.length() > 0)
	{
		strFirstWord = strFirstWord + strSrc[0];
		strSrc.erase(strSrc.begin());
	}
	if (strSrc[0] == ' ')
	{
		strSrc.erase(strSrc.begin());
	}
	return strFirstWord;
}

//Hàm Xóa Bit 0 ở đầu chuỗi
void CUtility::DelBit0(string &strSrc) {
	while (strSrc[0] == '0')//Xóa nhưng bit 0 ở đầu
	{
		strSrc.erase(strSrc.begin());
	}
}

//Đảo ngược chuỗi string truyền vào
void CUtility::Reserve_Str(string &str_Src) {
	string strTemp = str_Src;
	int len = strTemp.length();
	for (int i = 0; i < len; i++)
	{
		str_Src[i] = strTemp[len - 1 - i];
	}
}


int CUtility::Count_cSpacing(const string& strSrc) {
	int len = strSrc.length();
	int c = 0;
	for (int i = 0; i < len; i++)
	{
		if (strSrc[i] == ' ')
		{
			c++;
		}
	}
	return c;
}