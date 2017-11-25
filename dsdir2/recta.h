#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle {
public:
   Rectangle(int x, int y, int h, int w);  // constructor
   void Print();
   bool LessThan(Rectangle& s);
   bool Equal(Rectangle& s);
   int GetHeight();
   int GetWidth();
private:
   int xLow, yLow, height, width;
};
#endif