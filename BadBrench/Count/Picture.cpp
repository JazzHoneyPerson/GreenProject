#include "stdafx.h"
#include "picture.h"



void Picture::translate()
{
	image = new Bitmap(FileName);//указываем файл (переход пикселей в байты)
	SizeCol = image->GetWidth();
	SizeRow = image->GetHeight();
	Gdiplus::Rect mRect(0, 0, SizeCol, SizeRow);
	BitmapData bd;
	image->LockBits(&mRect, ImageLockModeRead | ImageLockModeWrite, image->GetPixelFormat(), &bd);
	WholeCurrRastData = (BYTE*)bd.Scan0;
	image->UnlockBits(&bd);
}
void Picture::download()
{
	assert(!Url.empty());
	wchar_t* chrURL = &Url[0];
	URLDownloadToFile(0, chrURL, FileName, 0, 0);
}

Picture::Picture(wchar_t* getWay)
{
	FileName = getWay;
	translate();
}
Picture::Picture(std::wstring getUrl, wchar_t* getWay)
{
	Url = getUrl;
	FileName = getWay;
	download();
	translate();
}


MyColor Picture::getColor(int x, int y)//получаем массив rgb с помощью обращения к getColor
{
	
	return MyColor((int)WholeCurrRastData[3 * x + 3 * 256 * y], (int)WholeCurrRastData[3 * x + 3 * 256 * y + 1], (int)WholeCurrRastData[3 * x + 3 * 256 * y + 2]);;
}


void Picture::Save(std::wstring fname)
{
	assert(!fname.empty());
	wchar_t* Newfname = &fname[0];
	CLSID jpgClsid;
	CLSIDFromString(L"{557cf401-1a04-11d3-9a73-0000f81ef32e}", &jpgClsid);
	image->Save(Newfname, &jpgClsid, NULL);
}
void Picture::Draw(int some)
{
	HDC hdc = CreateCompatibleDC(NULL);
	Gdiplus::Graphics graphics(hdc);
	BitmapData bitmapData;
	bitmapData.Width = 256,
		bitmapData.Height = 256,
		bitmapData.Stride = 2 * bitmapData.Width;
	bitmapData.Scan0 = (VOID*)Mask;
	bitmapData.Reserved = NULL;
	graphics.DrawImage(image, 0, 0);
	Rect rect(0, 0+some, 255, 255);
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
