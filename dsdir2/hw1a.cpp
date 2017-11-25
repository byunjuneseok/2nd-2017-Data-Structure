#include <iostream>
#include "recta.h"

using namespace std;

int main() {
   Rectangle r(2, 3, 6, 6), s(1, 2, 4, 6);

   cout << "<rectangle r> "; r.Print();
   cout << "<rectangle s> "; s.Print();

   if (r.LessThan(s))
      cout << "s is bigger";
   else if (r.Equal(s))
      cout << "Same Size";
   else cout << "r is bigger";
   cout << endl;

   return 0;
}
