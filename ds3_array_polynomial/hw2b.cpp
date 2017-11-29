#include <iostream>
using namespace std;
#include "polyb.h"           // include file을 바꾸었음
int main() {
   Polynomial p1, p2;
   cin >> p1 >> p2; // 2개의 다항식을 읽어들인다.
   Polynomial p3 = p1 * p2;   //  hw2a.cpp에서 +를 *로 바꾸었음
   cout << p1 << p2 << p3;

   /*
    3x^5+2x^3-4
    x^8-7x^5-x^3-3
    3x^13+2x^11-21x^10-21x^8-2x^6+19x^5-2x^3+12
   */
}
