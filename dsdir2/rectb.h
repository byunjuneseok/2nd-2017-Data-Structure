#ifndef RECTANGLE_H
#define RECTANGLE_H
using namespace std;
class Rectangle {
public:
   Rectangle(int, int, int, int);  // constructor
   bool operator <(Rectangle& s);
   bool operator ==(Rectangle& s);
   int GetHeight();
   int GetWidth();
friend ostream& operator<<(ostream& out, Rectangle& s);
private:
   int xLow, yLow, height, width;
};
#endif
