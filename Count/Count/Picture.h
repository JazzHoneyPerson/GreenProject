#include "stdafx.h"
#include "Color.h"
#include <windows.h> 
#include <stdio.h>
#include <gdiplus.h> //библиотека для обработки изображения
#include<iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <urlmon.h> //import URLDownLoadToFile
#include <string>
#pragma comment (lib,"Gdiplus.lib")
#pragma comment (lib, "urlmon.lib")

using namespace Gdiplus;

#pragma once



//using namespace std;
/*using namespace Gdiplus*/

class Picture//работа с изображением, структура класса
{
private:
	BYTE* WholeCurrRastData = new BYTE[256 * 256 * 3];//массив пикселей(int)
	BYTE Mask[256 * 256 * 3];
	Bitmap* image; //картинка, как объект
	UINT SizeCol;		//длина
	UINT SizeRow;		//ширина
	std::wstring Url;
	wchar_t* FileName;
	void translate();
	void download(std::wstring strURL);
	std::wstring fullStr(std::wstring symbol, double x, double y, std::wstring str, std::wstring sstr);											//добавляет подстроку 

public:
	Picture(std::wstring getUrl, wchar_t* getWay);
	void Download(double x, double y);//откуда-куда(кодировка юникод)

	MyColor getColor(int x, int y);//получаем массив rgb с помощью обращения к getColor
	std::vector<std::vector<MyColor>> getRect(int FirstX, int FirstY, int SecondX, int SecondY);//получаем массив rgb с помощью обращения к getColor

	void Save(std::wstring fname, double x, double y);
	void Draw();
	void setColor(int x, int y, MyColor Color);
	void Delete();

};