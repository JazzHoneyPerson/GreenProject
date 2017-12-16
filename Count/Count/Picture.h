#include "stdafx.h"
#include "Color.h"
#include "wstringfunc.h"
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
	std::wstring Url;
	wchar_t* FileName;
	void translate();
	void download(std::wstring strURL);


public:
	Picture(std::wstring getUrl, wchar_t* getWay);
	void Download(double x, double y);//������-����(��������� ������)

	MyColor getColor(int x, int y);//�������� ������ rgb � ������� ��������� � getColor
	std::vector<std::vector<MyColor>> getRect(int FirstX, int FirstY, int SecondX, int SecondY);//�������� ������ rgb � ������� ��������� � getColor

	void Save(std::wstring fname, double x, double y);
	void Draw();
	void setColor(int x, int y, MyColor Color);
	void Delete();

};