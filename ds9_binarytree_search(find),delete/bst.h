#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <queue>
using namespace std;

template <class K, class E>
struct Node {
    Node(K ky, E el, Node<K, E> *left=0, Node<K, E> *right=0) 
    : key(ky), element(el), leftChild(left), rightChild(right) { }

    Node<K, E> *leftChild;
    K key;
    E element;
    Node<K, E> *rightChild;
};


template <class K, class E>
struct BST {
public:
    BST() { root = 0; } // empty BST
    void Insert(K &newkey, E &el) { Insert(root, newkey, el); }
    void Delete(K &oldkey){ Delete(root, oldkey); }    // 구현해야하는 함수2
    void Delete(Node<K, E>* &ptr, K &oldkey);
    void Preorder() { Preorder(root); }
    void Inorder() { Inorder(root); }
    void Postorder() { Postorder(root); }
    void Levelorder();
    bool Find(const K&, E&);                            // 구현해야하는 함수1

private:
    void Visit(Node<K, E> *);
    void Insert(Node<K, E>* &, K &, E &);
    void Preorder(Node<K, E> *);
    void Inorder(Node<K, E> *);
    void Postorder(Node<K, E> *);
    Node<K, E> *root;
};  


template <class K, class E>
bool BST<K, E>::Find(const K& k, E& e)
{
    Node<K, E> *ptr = root;
    while (ptr)
        if (k < ptr->key) ptr = ptr->leftChild;
        else if (k > ptr->key) ptr = ptr->rightChild; /*구현!*/
        else { e = ptr->element; return true; }
    return false;
}

template <class K, class E>
void BST<K, E>::Delete(Node<K, E>* &ptr, K &oldkey)
{
    Node<K, E> *tmpptr; Node<K, E> *tmpdaddyptr;
    if (ptr == 0) return;
    if (oldkey < ptr->key)
        Delete(ptr->leftChild, oldkey);
    else if (oldkey > ptr->key)
        Delete(ptr->rightChild, oldkey);
    else
    if (!ptr->leftChild && !ptr->rightChild)
        { delete ptr; ptr = 0; return; }
    else if(ptr->leftChild && !ptr->rightChild)
    {tmpptr = ptr; ptr = ptr->leftChild; delete tmpptr; return;}
    else if (!ptr->leftChild && ptr->rightChild)
    {tmpptr = ptr; ptr = ptr->rightChild; delete tmpptr; return;} 
    else {
        Node<K, E> *rc = ptr->rightChild;
        if (!rc->leftChild)
        {ptr->key = rc->key;
        ptr->element = rc->element;
        ptr->rightChild = rc->rightChild;
        delete rc;
        return;}	
        else
        {tmpptr = rc;
        while(tmpptr->leftChild){
            tmpdaddyptr = tmpptr;
            tmpptr = tmpptr->leftChild;
            }
        ptr->key = tmpptr->key;
        ptr->element = tmpptr->element;
        tmpdaddyptr->leftChild = tmpptr->rightChild;
        delete tmpptr;
        return;
        } 
    
    }
}

template <class K, class E>
void BST<K, E>::Visit(Node<K, E> *ptr)
    { cout << ptr->key << ":" << ptr->element << " "; }

template <class K, class E>
void BST<K, E>::Insert(Node<K, E>* &ptr, K &newkey, E &el) { //Insert의 helper함수
    if (ptr==0) ptr = new Node<K, E>(newkey, el);
    else if (newkey < ptr->key) Insert(ptr->leftChild, newkey, el);
    else if (newkey > ptr->key) Insert(ptr->rightChild, newkey, el);
    else ptr->element = el; // Update element
}
template <class K, class E>
void BST<K, E>::Preorder(Node<K, E> *currentNode) { //Preorder의 helper함수
    if (currentNode) {
        Visit(currentNode);
        Preorder(currentNode->leftChild);
        Preorder(currentNode->rightChild);
    }
}

//..... Inorder, Postorder의 helper함수를 구현하시오.
template <class K, class E>
void BST<K, E>::Inorder(Node<K, E> *currentNode){
    if (currentNode){
        Inorder(currentNode->leftChild);
        Visit(currentNode);
        Inorder(currentNode->rightChild);
    }
}


template <class K, class E>
void BST<K, E>::Postorder(Node<K, E> *currentNode){
    if (currentNode){
        Postorder(currentNode->leftChild);
        Postorder(currentNode->rightChild);
        Visit(currentNode);
    }
}


//..... Levelorder(교재p266 참조하되 STL 큐를 이용)를 구현하시오.
template <class K, class E>
void BST<K, E>::Levelorder(){
    queue<Node<K, E>*> q;                             //QUEUE!
    Node<K, E> *currentNode = root;
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