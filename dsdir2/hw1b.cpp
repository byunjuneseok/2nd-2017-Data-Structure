#include <iostream>
#include "rectb.h"		// 헤더화일이 변경되었음에 주의
using namespace std;
int main() {
   Rectangle r(2, 3, 6, 6), s(1, 2, 4, 6);

   cout << "<rectangle r> " << r
        << "<rectangle s> " << s;
   if (r < s)
      cout << "s is bigger";
   else if (r == s)
      cout << "Same Size";
   else cout << "r is bigger";
   cout << endl;
	return 0;
   }