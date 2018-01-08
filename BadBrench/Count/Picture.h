#include "stdafx.h"
#include "Color.h"
#include <windows.h> 
#include <assert.h>
#include <stdio.h>
#include <gdiplus.h> //библиотека для обработки изображения
#include<iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <time.h>
#include <urlmon.h> //import URLDownLoadToFile
#include <string>

#pragma comment (lib,"Gdiplus.lib")
#pragma comment (lib, "urlmon.lib")

using namespace Gdiplus;

#pragma once



//using namespace std;
/*using namespace Gdiplus*/
struct Gdi
{
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdi();
	void stop();
};
class Picture//работа с изображением, структура класса
{
private:
	BYTE* WholeCurrRastData = new BYTE[256 * 256 * 3];//массив пикселей(int)
	BYTE Mask[256 * 256 * 3];
	Bitmap* image; //картинка, как объект
	UINT SizeCol;		//длина
	UINT SizeRow;		//ширина
	void translate();
	std::wstring points=L"";
	std::wstring Url;
	wchar_t* FileName;
	void download();
	

public:
	Picture(wchar_t* getWay);
	Picture(std::wstring getUrl, wchar_t* getWay);
	MyColor getColor(int x, int y);//получаем массив rgb с помощью обращения к getColor
	void Save(std::wstring fname);
	void Draw(int some);
	void setColor(int x, int y, MyColor Color);
	void Delete();

};