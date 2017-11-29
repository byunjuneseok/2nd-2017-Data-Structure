#include <iostream>
#include "list.h"
ostream& operator<<(ostream& os, IntList& il)
{
   Node *ptr = il.first;
    while (ptr != 0) {
        os << ptr->data << " "; ptr = ptr->link; }
    os << endl;
    return os;
}

void IntList::Push_Back(int e)
{
    if (!first)
        first = last = new Node(e);
    else {
        last->link = new Node(e);
        last = last->link;
    }
}

void IntList::Push_Front(int e)
{
	if (!first) //빈리스트
		first = last = new Node(e);
	else {
		Node *tmp;
		tmp = first;
		first = new Node(e);
		first->link = tmp;
	}
}

void IntList::Insert(int e)
{
	if (!first) //빈리스트
	{
		first = last = new Node(e);
	}
	else if (first->data > e) //맨 앞에 Node(e)를 새로 만들어야 하는 경우.
	{
		Push_Front(e);
	}
	else if (first->data != e) // p->data <= e <= q->data일 경우 검색
	{
		Node *p;
		Node *q;
		p = first;
		q = first->link;
		while(1)
		{
			if((p->data==e)||(q->data==e)) break;
			if ((p->data <=e) && (e <= q->data))
			{
				p->link = new Node(e);
				(p->link)->link = q;
				break;
			}
			p = q;
			q = q->link;
			if (p==last)
			{
				Push_Back(e);
				break;
			}
		}
	
	}
}

void IntList::Delete(int e)
{
	if(first->data == e)
	{
		first = first->link;
	}
	else{
		Node *p;
		Node *q;
		p = first;
		q = first->link;
		while(1)
		{
			if(q->data == e)
			{
				p->link = q->link;
				break;
			}
			p = q;
			q = q->link;
			
		}
	}
}