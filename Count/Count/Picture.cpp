#include "stdafx.h"
#include "picture.h"




	void Picture::translate()
	{
		image = new Bitmap(FileName);//указываем файл (переход пикселей в байты)
		SizeCol = image->GetWidth();
		SizeRow = image->GetHeight();
		Gdiplus::Rect mRect(0, 0, SizeCol, SizeRow);
		BitmapData bd;
		image->LockBits(&mRect, ImageLockModeRead |ImageLockModeWrite, image->GetPixelFormat(), &bd);
		WholeCurrRastData = (BYTE*)bd.Scan0;
		image->UnlockBits(&bd);
	}
	void Picture::download(std::wstring strURL)
	{
		assert(!strURL.empty());
		wchar_t* chrURL = &strURL[0];
		URLDownloadToFile(0, chrURL, FileName, 0, 0);
	}
	
	Picture::Picture(std::wstring getUrl, wchar_t* getWay)
	{
		Url = getUrl;
		FileName = getWay;
	}
	void Picture::Download(double x, double y)//откуда-куда(кодировка юникод)
	{
		std::wstring str = fullStr(L"#", Url, std::to_wstring(x) + L"," + std::to_wstring(y));
		download(fullStr(L"#", Url, std::to_wstring(x) + L"," + std::to_wstring(y)));
		translate();

	}

	MyColor Picture::getColor(int x, int y)//получаем массив rgb с помощью обращения к getColor
	{
		MyColor Color((int)WholeCurrRastData[3 * x + 3 * 256 * y], (int)WholeCurrRastData[3 * x + 3 * 256 * y + 1], (int)WholeCurrRastData[3 * x + 3 * 256 * y + 2]);
		return Color;
	}
	std::vector<std::vector<MyColor>> Picture::getRect(int FirstX, int FirstY, int SecondX, int SecondY)//получаем массив rgb с помощью обращения к getColor
	{
		std::vector<std::vector<MyColor>> Rect;
		std::vector<MyColor> Line;
		for (int y = FirstY; y < SecondY; y++)
		{
			for (int x = FirstX; x < SecondX; x++)
			{
				Line.push_back(getColor(x, y));
			}
			Rect.push_back(Line);
		}
		return Rect;
	}

	void Picture::Save(std::wstring fname, double x, double y)
	{
		fname = fullStr(L"#", fname, std::to_wstring(x));
		assert(!fname.empty());
		wchar_t* Newfname = &fname[0];
		CLSID jpgClsid;
		CLSIDFromString(L"{557cf401-1a04-11d3-9a73-0000f81ef32e}", &jpgClsid);
		image->Save(Newfname, &jpgClsid, NULL);
	}
	void Picture::Draw()
	{
		/*Url=fullStr(L"*", Url, points);*/
		HDC hdc = CreateCompatibleDC(NULL);
		Gdiplus::Graphics graphics(hdc);
		BitmapData bitmapData;
		bitmapData.Width = 256,
			bitmapData.Height = 256,
			bitmapData.Stride = 2 * bitmapData.Width;
		bitmapData.Scan0 = (VOID*)Mask;
		bitmapData.Reserved = NULL;
		graphics.DrawImage(image, 0, 0);
		Rect rect(0, 0, 255, 255);
		image->LockBits(&rect, ImageLockModeWrite | ImageLockModeUserInputBuf, image->GetPixelFormat(), &bitmapData);
		image->UnlockBits(&bitmapData);
		graphics.DrawImage(image, 0, 0);
	}
	void Picture::setColor(int x, int y, MyColor Color)
	{
		/*points += (L"&pl=c:00ff00,"+std::to_wstring(x) + L"," + std::to_wstring(y) + L","+ std::to_wstring(x) + L"," + std::to_wstring(y));*/
		Mask[3 * x + 3 * 256 * y] = Color.R;
		Mask[3 * x + 3 * 256 * y + 1] = Color.G;
		Mask[3 * x + 3 * 256 * y + 2] = Color.B;
	}
	void Picture::Delete()
	{
		delete[] image;
	}
	Gdi::Gdi()
	{
		Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	}
	void Gdi::stop()
	{
		GdiplusShutdown(gdiplusToken);
	}
