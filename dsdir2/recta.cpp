#include <iostream>
#include "recta.h"
using namespace std;

Rectangle::Rectangle(int x = 0, int y = 0, int h = 0, int w = 0)
: xLow(x), yLow(y), height(h), width(w) { }
void Rectangle::Print()
{
 cout << "Position : " << xLow <<" " << yLow << "; Height = " <<height << " Width = " << width << endl;	
}
bool Rectangle::LessThan(Rectangle& s)
{
	if (height * width < s.height * s.width) return true;

	else return false;
}

bool Rectangle::Equal(Rectangle& s)
{
   if (height * width == s.height * s.width) return 1;
	else return 0;
}
int Rectangle::GetHeight() { return height; }
int Rectangle::GetWidth() { return width; }