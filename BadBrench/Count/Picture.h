#include "stdafx.h"
#include "Color.h"
#include <windows.h> 
#include <assert.h>
#include <stdio.h>
#include <gdiplus.h> //���������� ��� ��������� �����������
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
class Picture//������ � ������������, ��������� ������
{
private:
	BYTE* WholeCurrRastData = new BYTE[256 * 256 * 3];//������ ��������(int)
	BYTE Mask[256 * 256 * 3];
	Bitmap* image; //��������, ��� ������
	UINT SizeCol;		//�����
	UINT SizeRow;		//������
	void translate();
	std::wstring points=L"";
	std::wstring Url;
	wchar_t* FileName;
	void download();
	

public:
	Picture(wchar_t* getWay);
	Picture(std::wstring getUrl, wchar_t* getWay);
	MyColor getColor(int x, int y);//�������� ������ rgb � ������� ��������� � getColor
	void Save(std::wstring fname);
	void Draw(int some);
	void setColor(int x, int y, MyColor Color);
	void Delete();

};