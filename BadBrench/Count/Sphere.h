#pragma once
#include "stdafx.h"
#include "Color.h"
#include <iostream>
struct Sphere
{
	struct Area
	{
		MyColor Color;
		int Radius;
		void Fill(MyColor NewColor, int NewRadius);
	};
	Area Forest;
	Area Water;
	Area Road;
	Area City;
	Area Factory;
	int d;
	bool Comparison(MyColor Color);
	void showArguments();
};
Sphere GoogleAreas();

Sphere YandexAreas();
