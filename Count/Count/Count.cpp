#include "stdafx.h"
#include "picture.h"
#include "color.h"
#include <windows.h> 
#include <stdio.h>//библиотека для обработки изображения
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






struct Sphere
{

	struct Area
	{
		MyColor Color;
		int Radius;
		void Fill(MyColor NewColor, int NewRadius)
		{
			Color = NewColor;
			Radius = NewRadius;
		}
	};
	Area Forest;
	Area Water;
	Area Road;
	Area City;
	Area Factory;
	int d;

	bool Comparison(MyColor Color)
	{
		bool t = true;
		/*for (int i = 0; i < 256; i++)
		{
		t = t&&DistanceOfPixels(Color, MyColor(i, i, i)) <256;
		}*/
		return DistanceOfPixels(Color, Forest.Color) < Forest.Radius
			&& DistanceOfPixels(Color, Water.Color) > Water.Radius
			&& DistanceOfPixels(Color, Road.Color) > Road.Radius
			&& DistanceOfPixels(Color, City.Color) > City.Radius
			&& DistanceOfPixels(Color, Factory.Color) > Factory.Radius;
	}
	void showArguments()
	{
		cout << Water.Radius << " " << Forest.Radius << " " << Road.Radius << " " << City.Radius << " " << Factory.Radius << endl;
	}
};






Sphere GoogleAreas()
{
	Sphere Google;
	int  last_value = 443;

	Google.City.Fill(MyColor(0, 138, 142), rand()%1);
	Google.Forest.Fill(MyColor(88, 88, 88), 77/*rand() % 431*/);
	Google.Water.Fill(MyColor(48, 48, 48), 16/*rand() % 256*/);
	Google.Road.Fill(MyColor(139, 139, 139),13/* rand() %256*/);
	Google.Factory.Fill(MyColor(108, 108, 108), rand() % 1);
	return Google;
}
Sphere YandexAreas()
{
	Sphere Yandex;
	int  last_value = 443;
	Yandex.City.Fill(MyColor(40, 40, 40),48/* rand() % 256*/);
	Yandex.Forest.Fill(MyColor(40, 40, 40), 381/*rand() % 431*/);
	Yandex.Water.Fill(MyColor(39, 39, 39),155/* rand() % 256*/);
	Yandex.Road.Fill(MyColor(197, 197, 197), 5/*rand() % 256*/);
	Yandex.Factory.Fill(MyColor(66, 66, 66), 1);
	return Yandex;
}
int main()
{
	
	Gdi gdi;
	wstring PalleteSaveWay = L"pallete(#).jpg";
	Picture GoogleSputnik(L"https://maps.googleapis.com/maps/api/staticmap?center=#&zoom=19&size=512x512&maptype=satellite&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4", L"GoogleSputnik.jpg");
	/*Picture pallete(L"https://static-maps.yandex.ru/1.x/?ll=#&size=450,450&z=19&l=sat*&694f2d60-17b6-4099-a759-b98a764f50e1", L"pallete.jpg");*/
	Picture pallete(L"https://maps.googleapis.com/maps/api/staticmap?center=#&zoom=19&size=512x512&style=feature:all|element:labels|visibility:off&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4", L"pallete.jpg");
	Picture YandexSputnik(L"https://static-maps.yandex.ru/1.x/?ll=#&size=450,450&z=19&l=map&694f2d60-17b6-4099-a759-b98a764f50e1", L"YandexSputnik.jpg");
	Picture RoadsAndRivers(L"https://maps.googleapis.com/maps/api/staticmap?center=#&zoom=19&size=512x512&style=feature:road|color:0x000000&style=feature:all|element:labels|visibility:off&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4", L"RoadsAndRivers.jpg");


	double Coordinates[] = { 56.818492, 60.581048,
		56.840514, 60.638554};
	Sphere Google = GoogleAreas();
	for (double Long = 56.819468; Long < Coordinates[2]; Long += 0.000488/*28125*/)//координаты Екатеринбурга, шаг
		for (double Lat = 60.633752/*9*0.000488+Coordinates[1]*/; Lat < Coordinates[3]; Lat += 0.000488/*28125*/)
		{
			/*while (true)
			{*/
				srand(time(0));

				//int t = 40;
				//system("cls");
				GoogleSputnik.Download(Long, Lat);
				YandexSputnik.Download(Lat, Long);
				pallete.Download(Long, Lat);
				///*while(true)
				//{


				//UINT count = 0;
				//int flag = 0;
				//while (count < 1)
				//{*/

				///*	flag = false;
				//count = 0;*/
				//Sphere Yandex = YandexAreas();
				//Sphere Google = GoogleAreas();
				//MyColor Golore(155, 186, 241/*rand() % 256, rand() % 256, rand() % 256*/);
				//int D = 237/*rand() % 443*/;
				Sphere Google = GoogleAreas();
				Sphere Yandex = YandexAreas();

				/*cout << Block[1].size();*/
				MyColor NewColor(rand() % 256, rand() % 256, rand() % 256);
				for (int y = 0; y < 256; y ++)
					for (int x = 0; x < 256; x++)
					{
						if (Google.Comparison(GoogleSputnik.getColor(x, y))&& DistanceOfPixels(MyColor(140,43,134), GoogleSputnik.getColor(x, y))>85&&Yandex.Comparison(YandexSputnik.getColor(x,y)) && DistanceOfPixels(MyColor(94,108,54), GoogleSputnik.getColor(x, y))>50&& DistanceOfPixels(MyColor(132, 110, 101), GoogleSputnik.getColor(x, y))>50)
						{
							pallete.setColor(x, y, MyColor(0, 0, 0));
						}
						else
						{
							pallete.setColor(x, y, pallete.getColor(x, y));
						}
					}

				/*		for (int i = 0; i < 4; i++)
						{
							vector<MyColor> B(4);
							for (int j = 0; j<4; j++)
								B[i] = MyColor(0, 0, 0);
							Blck[i] = B;
						}
						for (int i = 0; i < 4; i++)
						{
							for (int j = 0; j < 4; j++)
							{
								Addition(Blck[j][i], Block[j][i]);
								Blck[j][i] = MyColor(Blck[j][i].R / 2, Blck[j][i].G / 2, Blck[j][i].B / 2);
							}
						}*/
				pallete.Draw();
				pallete.Save(PalleteSaveWay, 7, 8);
				//pallete.Download(Lat,Long);
				pallete.Delete();
				GoogleSputnik.Delete();
				YandexSputnik.Delete();
				///*system("pause");*/
				Yandex.showArguments();
				NewColor.Show();
 			//}///*cout << NewColor.R / count << " " << NewColor.G / count << " " << NewColor.B / count << endl;*/
				
		}
	/*ofstream fout("BlockData.txt");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fout << Blck[j][i].R <<" "<< Blck[j][i].G<<" " << Blck[j][i].B << endl;
		}
	}*/
	gdi.stop();
	system("pause");
	
}