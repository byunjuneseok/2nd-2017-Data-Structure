#include <iostream>
#include "list.h"
int main()
{
	IntList il;
	il.Push_Back(5); il.Push_Back(7); il.Push_Back(9);   cout << il;
	il.Push_Front(4); il.Push_Front(3);   cout << il;

	il.Insert(6); il.Insert(10); il.Insert(2);
	il.Insert(5); il.Insert(2); il.Insert(10);// already existing ones
	cout << il;
	il.Delete(6); il.Delete(10); il.Delete(2);
	cout << il;
}