#pragma once
#include "stdafx.h"
struct MyColor
{
	int R;
	int G;
	int B;
	
	MyColor();
	MyColor(int Red, int Green, int Blue);
	void Show();
};
int DistanceOfPixels(MyColor First, MyColor Second);