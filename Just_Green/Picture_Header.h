#pragma once
#include <windows.h> 
#include <stdio.h>
#include <gdiplus.h> //библиотека для обработки изображения
#include <assert.h>
#include <urlmon.h>
#include "stdafx.h" 

class picture//работа с изображением, структура класса
{
private:
	BYTE* WholeCurrRastData = new BYTE[256 * 256 * 3];//массив пикселей(int)
	BYTE Mask[256 * 256 * 3];
	Gdiplus::Bitmap* image; //картинка, как объект
	UINT SizeCol;		//длина
	UINT SizeRow;		//ширина

public:
	void Download(wstring strURL, wchar_t* FileName, double x, double y)//откуда-куда(кодировка юникод)
	{
		strURL = strURL.substr(0, strURL.find(L"#")) + to_wstring(x) + L"," + to_wstring(y) + strURL.substr(strURL.find(L"*") + 1, strURL.length() - strURL.find(L"*") - 1);
		assert(!strURL.empty());
		wchar_t* chrURL = &strURL[0];
		URLDownloadToFile(0, chrURL, FileName, 0, 0);	//скачивание картинки
		image = new Gdiplus::Bitmap(FileName);//указываем файл (переход пикселей в байты)
		SizeCol = image->GetWidth();
		SizeRow = image->GetHeight();
	}
	void Translate(wchar_t* FileName)//хоулрастдата заполняется цветами РГБ, картинка переводится в хоул раст дата
	{
		Gdiplus::Rect mRect(0, 0, SizeCol, SizeRow);
		Gdiplus::BitmapData bd;
		image->LockBits(&mRect, ImageLockModeRead | ImageLockModeWrite, image->GetPixelFormat(), &bd);
		WholeCurrRastData = (BYTE*)bd.Scan0;
		image->UnlockBits(&bd);
	}
	vector<int> getColor(UINT i)//получаем массив rgb с помощью обращения к getColor
	{
		vector<int> Color;
		for (int j = 0; j < 3; j++)
		{
			Color.push_back((int)WholeCurrRastData[3 * i + j]);
		}
		return Color;
	}
	void Save(wstring fname, double x, double y)//скачиваение картинки
	{
		fname = fname.substr(0, fname.find(L"#")) + to_wstring(x) + L"," + to_wstring(y) + fname.substr(fname.find(L"*") + 1, fname.length() - fname.find(L"*") - 1);
		assert(!fname.empty());
		wchar_t* Newfname = &fname[0];
		CLSID jpgClsid;
		CLSIDFromString(L"{557cf401-1a04-11d3-9a73-0000f81ef32e}", &jpgClsid);
		image->Save(Newfname, &jpgClsid, NULL);
	}
	void Draw()//выводится RGB 
	{
		HDC hdc = CreateCompatibleDC(NULL);
		Gdiplus::Graphics graphics(hdc);
		BitmapData bitmapData;
		bitmapData.Width = 256,
			bitmapData.Height = 256,
			bitmapData.Stride = 2 * bitmapData.Width;
		bitmapData.Scan0 = (VOID*)Mask;//массив, который вводится в битмапдата, Маск заполнен битами ргб
		bitmapData.Reserved = NULL;
		graphics.DrawImage(image, 0, 0);
		Rect rect(0, 0, 255, 255);
		image->LockBits(&rect, ImageLockModeWrite | ImageLockModeUserInputBuf, image->GetPixelFormat(), &bitmapData);
		image->UnlockBits(&bitmapData);
		graphics.DrawImage(image, 0, 0);
	}
	void setColor(int i, vector<int>Color)//заполнение массива Маск цветами РГБ
	{
		for (int j = 0; j < 3; j++)
		{
			Mask[3 * i + j] = (BYTE)Color[j];
		}
	}
	void Delete()
	{
		delete[] image;
	}

};

void showVector(vector<int> Color)//вывод массива РГБ
{
	for (int i = 0; i < Color.size(); i++)
	{
		cout << Color[i] << " ";
	}
	system("pause");
}

void findFirstSecond(double &first, double &second)
{
	double t;
	if (first > second)
	{
		t = first;
		first = second;
		second = t;
	}
}
void getCoordinate(double& firstX, double& firstY, double& secondX, double& secondY)
{
	cin >> firstX >> firstY >> secondX >> secondY;
	findFirstSecond(firstX, secondX);
	findFirstSecond(firstY, secondY);
}
