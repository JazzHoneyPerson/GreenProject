#include "stdafx.h"
#include "picture.h"
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


using namespace std;
//using namespace Gdiplus;





//struct Sphere
//{
//
//	struct Area
//	{
//		MyColor Color;
//		int Radius;
//		void Fill(MyColor NewColor, int NewRadius)
//		{
//			Color = NewColor;
//			Radius = NewRadius;
//		}
//	};
//	Area Forest;
//	Area Water;
//	Area Road;
//	Area City;
//	Area Factory;
//	int d;
//
//	bool Comparison(MyColor Color)
//	{
//		bool t = true;
//		/*for (int i = 0; i < 256; i++)
//		{
//		t = t&&DistanceOfPixels(Color, MyColor(i, i, i)) <256;
//		}*/
//		return DistanceOfPixels(Color, Forest.Color) < Forest.Radius
//			&& DistanceOfPixels(Color, Water.Color) > Water.Radius
//			&& DistanceOfPixels(Color, Road.Color) > Road.Radius
//			&& DistanceOfPixels(Color, City.Color) > City.Radius
//			&& DistanceOfPixels(Color, Factory.Color) > Factory.Radius;
//	}
//	void showArguments()
//	{
//		cout << Water.Radius << " " << Forest.Radius << " " << Road.Radius << " " << City.Radius << " " << Factory.Radius << endl;
//	}
//};
//
//
//
//
//
//void Addition(MyColor &First, MyColor Second)
//{
//	First.R += Second.R;
//	First.G += Second.G;
//	First.B += Second.B;
//}
//Sphere GoogleAreas()
//{
//	Sphere Google;
//	int  last_value = 443;
//	Google.City.Fill(MyColor(0, 138, 142), 20);
//	Google.Forest.Fill(MyColor(0, 108, 107/*88, 88, 88*/), 496);
//	Google.Water.Fill(MyColor(48, 48, 48), 75);
//	Google.Road.Fill(MyColor(139, 139, 139), 0);
//	Google.Factory.Fill(MyColor(108, 108, 108), 14);
//	Google.d = 30;
//	return Google;
//}
//Sphere YandexAreas()
//{
//	Sphere Yandex;
//	int  last_value = 443;
//	Yandex.City.Fill(MyColor(40, 40, 40), 0);
//	Yandex.Forest.Fill(MyColor(40, 40, 40), 1000000);
//	Yandex.Water.Fill(MyColor(39, 39, 39), 26);
//	Yandex.Road.Fill(MyColor(197, 197, 197), 281);
//	Yandex.Factory.Fill(MyColor(66, 66, 66), 1);
//	Yandex.d = 0;
//	return Yandex;
//}
int main()
{
	srand(time(0));
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	//wstring PalleteSaveWay = L"pallete(#,*).jpg";
	//Picture GoogleSputnik(L"https://maps.googleapis.com/maps/api/staticmap?center=#,*&zoom=19&size=512x512&maptype=satellite&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4", L"GoogleSputnik.jpg");
	//Picture pallete(L"https://maps.googleapis.com/maps/api/staticmap?center=#,*&zoom=19&size=512x512&[]&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4", L"pallete.jpg");
	//Picture YandexSputnik(L"https://static-maps.yandex.ru/1.x/?ll=#,*&size=450,450&z=19&l=sat&694f2d60-17b6-4099-a759-b98a764f50e1", L"YandexSputnik.jpg");
	//Picture RoadsAndRivers(L"https://maps.googleapis.com/maps/api/staticmap?center=#,*&zoom=19&size=512x512&style=feature:road|color:0x000000&style=feature:all|element:labels|visibility:off&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4", L"RoadsAndRivers.jpg");


	//double Coordinates[] = { 56.836239, 60.581441,
	//	56.818611, 60.639404 };
	//MyColor NewColor(0, 0, 0);
	///*MyColor DrawColor;*/
	//for (double Long = Coordinates[0]; Long < Coordinates[2]; Long += 0.00048828125)//координаты Екатеринбурга, шаг
	//	for (double Lat = 16 * 0.00048828125 + Coordinates[1]; Lat < Coordinates[3]; Lat += 0.00048828125)
	//	{
	//		/*while (true)
	//		{*/
	//		int t = 40;
	//		system("cls");
	//		GoogleSputnik.Download(Long, Lat);
	//		YandexSputnik.Download(Lat, Long);
	//		pallete.Download(Long, Lat);
	//		/*while(true)
	//		{


	//		UINT count = 0;
	//		int flag = 0;
	//		while (count < 1)
	//		{*/

	//		/*	flag = false;
	//		count = 0;*/
	//		Sphere Yandex = YandexAreas();
	//		Sphere Google = GoogleAreas();
	//		MyColor Golore(155, 186, 241/*rand() % 256, rand() % 256, rand() % 256*/);
	//		int D = 237/*rand() % 443*/;
	//		for (int y = 0; y < 256; y++)
	//			for (int x = 0; x < 256; x++)
	//			{
	//				if (!Google.Comparison(GoogleSputnik.getColor(x, y)) && !Yandex.Comparison(YandexSputnik.getColor(x, y)))
	//				{
	//					pallete.setColor(x, y, NewColor);
	//					/*count++;*/
	//					if ((Color.R != 19 || Color.G != 19 || Color.B != 19) /*&& (Colorp.R != 0 && Colorp.G != 0 && Colorp.B != 0)*/)
	//					{
	//						count--;
	//					}

	//				}
	//				else
	//				{
	//					pallete.setColor(x, y, pallete.getColor(x, y));
	//				}
	//			}
	//		cout << "1:";
	//		/*Google->showArguments();*/
	//		cout << "2:";
	//		cout << Golore.R << " " << Golore.G << " " << Golore.B << " " << D;
	//		/*Yandex.showArguments();*/
	//		pallete.Draw();
	//		pallete.Save(PalleteSaveWay, 7, 8);
	//		pallete.Delete();
	//		GoogleSputnik.Delete();
	//		YandexSputnik.Delete();
	//		/*	}*/
	//		/*system("pause");*/
	//		/*cout << NewColor.R / count << " " << NewColor.G / count << " " << NewColor.B / count << endl;*/
	//	}

	system("pause");
	GdiplusShutdown(gdiplusToken);
}