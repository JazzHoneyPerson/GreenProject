#include "stdafx.h"
#include "Color.h"


using namespace std;

MyColor::MyColor()
{
}
MyColor::MyColor(int Red, int Green, int Blue)
{
	R = Red;
	G = Green;
	B = Blue;
}
void MyColor::Show()
{
	cout << R << " " << G << " " << B << " " << endl;
}
int DistanceOfPixels(MyColor First, MyColor Second)
{
	return sqrt((First.R - Second.R)*(First.R - Second.R) + (First.G - Second.G)*(First.G - Second.G) + (First.B - Second.B)*(First.B - Second.B));
}
MyColor Addition(MyColor First, MyColor Second)
{
	First.R += Second.R;
	First.G += Second.G;
	First.B += Second.B;
	return First;
}

