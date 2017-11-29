#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <queue>                                    //STL 의 QUEUE 사용!
using namespace std;

template <class T>                                  //class of Node (data, left, right pointer)
struct Node {
    Node(T d, Node<T> *left=0, Node<T> *right=0)
    : data(d), leftChild(left), rightChild(right) { }

    Node<T> *leftChild;
    T data;
    Node<T> *rightChild;
};


template <class T>
class Tree {                                        //whole tree
public:
    Tree() { root = 0; } // empty tree
    void Insert(T &value) { Insert(root, value); }  //inserting tree
    void Preorder() { Preorder(root); }             //VLR
    void Inorder() { Inorder(root); }               //LVR
    void Postorder() { Postorder(root); }           //LRV
    void Levelorder();

private:                                            // helper 함수들
    void Visit(Node<T> *);
    void Insert(Node<T>* &, T &);
    void Preorder(Node<T> *);
    void Inorder(Node<T> *);
    void Postorder(Node<T> *);

    Node<T> *root;
};


template <class T>
void Tree<T>::Visit(Node<T> *ptr) { cout << ptr->data << " "; }

template <class T>
void Tree<T>::Insert(Node<T>* &ptr, T &value) { //Insert의 helper함수
    if (ptr==0) ptr = new Node<T>(value);
    else if (value < ptr->data) Insert(ptr->leftChild, value);
    else if (value > ptr->data) Insert(ptr->rightChild, value);
    else cout << endl << "Duplicate value " << value << " ignored\n";
}

template <class T>
void Tree<T>::Preorder(Node<T> *currentNode) { //Preorder의 helper함수
    if (currentNode) {
        Visit(currentNode);
        Preorder(currentNode->leftChild);
        Preorder(currentNode->rightChild);
    }
}

//..... Inorder, Postorder의 helper함수를 구현하시오.
template <class T>
void Tree<T>::Inorder(Node<T> *currentNode){
    if (currentNode){
        Inorder(currentNode->leftChild);
        Visit(currentNode);
        Inorder(currentNode->rightChild);
    }
}


template <class T>
void Tree<T>::Postorder(Node<T> *currentNode){
    if (currentNode){
        Postorder(currentNode->leftChild);
        Postorder(currentNode->rightChild);
        Visit(currentNode);
    }
}

    
template <class T>
void Tree<T>::Levelorder(){
    queue<Node<T>*> q;
    Node<T> *currentNode = root;
    while(currentNode){
        Visit(currentNode); 
        if(currentNode->leftChild)
            q.push(currentNode->leftChild);
        
        if(currentNode->rightChild)
            q.push(currentNode->rightChild);
        
        if(q.empty()) return;
            currentNode = q.front();
        
        q.pop();
    }
}

#endif