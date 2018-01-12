#include "stdafx.h"
#include "picture.h"
#include "color.h"
#include "wstringfunc.h"
#include "Sphere.h"
#include <windows.h> 
#include <stdio.h>//библиотека для обработки изображения
#include<iostream>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <urlmon.h> //import URLDownLoadToFile
#include <string>
#pragma comment (lib,"Gdiplus.lib")
#pragma comment (lib, "urlmon.lib")


using namespace std;

int main()
{
	
	Gdi gdi;
	wstring PalleteSaveWay = L"PresentForPython/pallete(#).jpg";
	wstring MapSaveWay = L"PresentForPython/GMap(#).jpg";
	wstring InterfaceSaveWay = L"PresentForPython/GInterface(#).jpg";
	wstring GSUrl = L"https://maps.googleapis.com/maps/api/staticmap?center=#&zoom=19&size=512x512&maptype=satellite&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4";
	wstring GMUrl = L"https://maps.googleapis.com/maps/api/staticmap?center=#&zoom=19&size=512x512&style=feature:all|element:labels|visibility:off&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4";
	wstring GIUrl = L"https://maps.googleapis.com/maps/api/staticmap?size=512x512&zoom=19&center=#&style=feature:all|element:labels|visibility:off&style=feature:all|element:geometry.fill|color:0xffffff&style=feature:all|element:geometry.stroke|color:0x000000&style=feature:road|color:0x857b7b&style=feature:water|color:11689eb&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4";

	double Coordinates[] = { 56.805958, 60.578244,
		56.845300, 60.645192 };
	int step=0;
	for (double Long = Coordinates[0]; Long < Coordinates[2]; Long += 0.000488)//координаты Екатеринбурга, шаг
		for (double Lat = Coordinates[1]; Lat < Coordinates[3]; Lat += 0.000488)
		{
			step++;
			Picture pallete(L"pallete.jpg");
			Picture GoogleInterface(fullStr(L"#", GIUrl, std::to_wstring(Long) + L"," + std::to_wstring(Lat)), L"GoogleInterface.jpg");
			Picture GoogleSputnik(fullStr(L"#", GSUrl, std::to_wstring(Long)+L","+ std::to_wstring(Lat)), L"GoogleSputnik.jpg");
			Picture GoogleMap(fullStr(L"#", GMUrl, std::to_wstring(Long) + L"," + std::to_wstring(Lat)), L"GoogleMap.jpg");
			for (int y = 0; y < 256; y++)
				for (int x = 0; x < 256; x++)
				{

					MyColor Sputnik = GoogleSputnik.getColor(x, y);
					bool t = true;
					for (int i = 0; i < 256; i++)
					{
						t = t&&DistanceOfPixels(Sputnik, MyColor(i, i, i)) > 10;
					}
					if (t
						&&DistanceOfPixels(Sputnik, MyColor(255, 255, 255)) > 228
						&& DistanceOfPixels(Sputnik, MyColor(0, 0, 0)) > 20
						&& DistanceOfPixels(Sputnik, MyColor(0, 255, 0)) < 300
						&& DistanceOfPixels(Sputnik, MyColor(255, 0, 255)) > 256
						&& DistanceOfPixels(Sputnik, MyColor(0, 0, 255)) < 232
						&& DistanceOfPixels(Sputnik, MyColor(255, 0, 0)) > 100
						)
					{
						pallete.setColor(x, y, MyColor(0,0,0));
						GoogleMap.setColor(x, y, MyColor(0, 0, 0));
						GoogleInterface.setColor(x, y, MyColor(0, 0, 0));
					}
					else
					{
						pallete.setColor(x, y, (pallete.getColor(x, y)));
						GoogleMap.setColor(x, y, (GoogleMap.getColor(x, y)));
						GoogleInterface.setColor(x, y, (pallete.getColor(x, y)));
					}
				}
			pallete.Draw(0);
			pallete.Save(fullStr(L"#", PalleteSaveWay,to_wstring(step)));
			pallete.Delete();
			GoogleSputnik.Delete();
			GoogleMap.Draw(256);
			GoogleMap.Save(fullStr(L"#", MapSaveWay, to_wstring(1)));
			GoogleMap.Delete();	
			GoogleInterface.Draw(256);
			GoogleInterface.Save(fullStr(L"#", InterfaceSaveWay, to_wstring(step)));
			GoogleInterface.Delete();
		}
	gdi.stop();
	
}