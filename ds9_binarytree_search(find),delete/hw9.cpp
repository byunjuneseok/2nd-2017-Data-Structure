#include "bst.h"  // include file명이 바뀌었음
int main()
{
    BST<string, double> tree;
    string command, str; double dval;

    while (cin >> command)
        if (command == "insert") {
            cin >> str >> dval; tree.Insert(str, dval); }
        else if (command == "delete") {
            cin >> str; tree.Delete(str); }
        else if (command == "print") {
            cout << endl << "Inorder traversal :   "; tree.Inorder();
            cout << endl << "Postorder traversal : "; tree.Postorder();
            cout << endl;
        }
    else if (command == "find") {
        cin >> str;
        if (tree.Find(str, dval))
            cout << "The value of " << str << " is " << dval << endl;
        else cout << "No such key : " << str << endl;
        }
    else
        cout << "Invalid command : " << command << endl;
}