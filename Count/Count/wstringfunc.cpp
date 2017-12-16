#include "stdafx.h"
#include "wstringfunc.h"

std::wstring fullStr(std::wstring symbol,  std::wstring str, std::wstring sstr)											//добавляет подстроку 
{
	return str.substr(0, str.find(symbol)) + sstr + str.substr(str.find(symbol) + 1, str.length() - str.find(symbol) - 1);
}
