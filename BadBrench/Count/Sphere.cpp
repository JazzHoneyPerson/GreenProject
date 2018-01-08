#include "stdafx.h"
#include "Sphere.h"

using namespace std;

bool Sphere::Comparison(MyColor Color)
{
	bool t = true;

	return DistanceOfPixels(Color, Forest.Color) < Forest.Radius
		&& DistanceOfPixels(Color, Water.Color) > Water.Radius
		&& DistanceOfPixels(Color, Road.Color) > Road.Radius
		&& DistanceOfPixels(Color, City.Color) > City.Radius
		&& DistanceOfPixels(Color, Factory.Color) > Factory.Radius;
}
void Sphere::showArguments()
{
	cout << Water.Radius << " " << Forest.Radius << " " << Road.Radius << " " << City.Radius << " " << Factory.Radius << endl;
}
void Sphere::Area::Fill(MyColor NewColor, int NewRadius)
{
	Color = NewColor;
	Radius = NewRadius;
}


Sphere GoogleAreas()
{
	Sphere Google;
	int  last_value = 443;

	Google.City.Fill(MyColor(0, 138, 142), 1);
	Google.Forest.Fill(MyColor(88, 88, 88), rand() % 431);//77
	Google.Water.Fill(MyColor(48, 48, 48),rand() % 256);//16
	Google.Road.Fill(MyColor(139, 139, 139), rand() %256);//13
	Google.Factory.Fill(MyColor(108, 108, 108), 1);//
	return Google;
}
Sphere YandexAreas()
{
	Sphere Yandex;
	int  last_value = 443;
	Yandex.City.Fill(MyColor(0, 138, 142), rand() % 256);
	Yandex.Forest.Fill(MyColor(88, 88, 88), rand() % 431);
	Yandex.Water.Fill(MyColor(48, 48, 48), rand() % 256);
	Yandex.Road.Fill(MyColor(139, 139, 139), rand() % 256);
	Yandex.Factory.Fill(MyColor(108, 108, 108), 1);
	return Yandex;
}