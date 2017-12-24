#include <iostream>
using namespace std;

template <class T>
void PrintArray(T *a, const int n)
{
    for (int i = 1; i <= n; i++)
    cout << a[i] << " ";
    cout << endl;
}

template <class T>
void Adjust(T *a, const int root, const int n)
{
// 자료는 a[1:n]에 저장되어 있고, root의 좌측 트리와 우측 트리가 Heap인
// 상태에서 root를 포함하여 heap가 되게한다.
    T e = a[root];

    int j;
    for (j = 2*root; j <= n; j *= 2) {
    if (j < n && a[j] < a[j+1]) j++;
    if (e >= a[j]) break;
    a[j/2] = a[j];
    }
    a[j/2] = e;
}

template <class T>
void HeapSort(T *a, const int n)
{
    for (int i = n/2; i >= 1; i--) // heapify
    Adjust(a, i, n);

    for (int i = n-1; i >= 1; i--)
    {
    swap(a[1], a[i+1]); // i+1째 위치에 정렬이 제일 큰 값을 저장
    Adjust(a, 1, i); // a[1]의 자료 이동으로 a[1:i]를 heap로 바꿈
    }
}

int main()
{
    int a[] = { 0, 26, 5, 77, 1, 61, 11, 59, 15, 48, 19 }; //0번째는 사용안됨

    int n = sizeof(a) / sizeof(int) - 1; // 0번째 성분 제외
    cout << "Before Sorting : "; PrintArray(a, n);
        HeapSort(a, n);
    cout << "After Sorting  : "; PrintArray(a, n);
}