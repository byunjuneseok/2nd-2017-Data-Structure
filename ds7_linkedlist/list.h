using namespace std;

struct Node
{
    Node(int d = 0, Node *l = 0) : data(d), link(l) { }		//Node (0, 0)
    int data;
    Node *link;
};
struct IntList
{
    IntList() { last = first = 0; }
    void Push_Back(int);										// 리스트 뒤에 삽입
    void Push_Front(int);									// 리스트 앞에 삽입
    void Insert(int);										// 정렬되어 있다는 가정 하에 제 위치에 삽입
    void Delete(int);										// 리스트의 원소 삭제
    Node *first;												// 첫 노드를 가리킴
    Node *last;												// 마지막 노드를 가리킴
};
ostream& operator<<(ostream&, IntList&);
	