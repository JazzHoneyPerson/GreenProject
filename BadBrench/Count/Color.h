#pragma once
#include "stdafx.h"
#include <iostream>
#include <windows.h>
struct MyColor
{
	UINT R;
	UINT G;
	UINT B;
	
	MyColor();
	MyColor(int Red, int Green, int Blue);
	void Show();
};
int DistanceOfPixels(MyColor First, MyColor Second);
MyColor Addition(MyColor First, MyColor Second);