#include <iostream>
using namespace std;

template <class T>
class Maxheap {
public:
    Maxheap(int); // constructor
    void Push(const T& e);
    void Pop();
    bool IsEmpty() { return heapSize == 0; }
    T Top() { return this->heap[1]; }   //구현해야함.
private:
    void ChangeSize1D(int*, int, int);
    T *heap;		// element array 
    int heapSize;	// #elements in heap
    int capacity;	// size of the array heap 
template <class T2> friend ostream& operator<<(ostream&,Maxheap<T2>&);
}; 

template <class T>
ostream& operator<<(ostream& os, Maxheap<T>& H) {
    os << "<Heap Contents>  ";
    for (int i = 1; i <= H.heapSize; i++)
        os << i << ":" << H.heap[i] << " ";
    os << endl;
}

/*constructor와 Push와 Pop과 ChangeSize1D  함수의 구현(교재 이용)*/
template <class T>
Maxheap<T>::Maxheap(int theCapacity = 10){
    if (theCapacity < 1) throw "capacity must be >= 1.";
    capacity = theCapacity;
    heapSize = 0;
    heap = new T[capacity + 1];     //heap[0]은 사용되지 않음.
}

template <class T>
void Maxheap<T>::Push(const T& e){
    //최대 히프에 e 를 삽입한다.
    if (heapSize == capacity){
        ChangeSize1D(heap, capacity, 2*capacity);
        capacity *= 2;
    }
    int currentNode = ++heapSize;
    while(currentNode != 1 && heap[currentNode / 2] < e){
        //루트로 올라감.
        heap[currentNode] = heap[currentNode / 2];
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template <class T>
void Maxheap<T>::Pop(){
    if (IsEmpty()) throw "Heap is empty. Can't delete.";
    heap[1].~T();   //최대 원소 삭제

    //히프의 마지막 원소를 제거합니다.
    T lastE = heap[heapSize--];

    //trickle down.
    int currentNode = 1;
    int child = 2;      //currentNode 의 자식
    while(child <= heapSize){
        //child 를 currentNode의 큰 자식으로 설정
        if (child < heapSize && heap[child] < heap[child + 1]) child++;

        //currentNode에 lastE를 삽입할 수 있는가?
        if (lastE >= heap[child]) break;    //yes

        //nooo...
        heap[currentNode] = heap[child]; // 자식으로 이동
        currentNode = child;
        child *= 2;
    }
    heap[currentNode] = lastE;
}

template <class T>
void Maxheap<T>::ChangeSize1D(int *a,int oldSize,int newSize){
    int *temp = new int[newSize];
    int num = min(oldSize,newSize);
    copy(a, a+num, temp);
    delete []a;
    a = temp;
}