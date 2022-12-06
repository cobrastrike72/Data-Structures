#include <iostream>
#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"
using namespace std;



int main() {

    BinarySearchTree<int> tree;
//    tree.insert(100);
////    tree.insert(100); // well give you an exception since the value already exist
//    tree.insert(50);
//    tree.insert(60);
//    tree.insert(70);
//    tree.insert(20);
//    tree.insert(30);
//    tree.remove(20);

    int arr[] = {20, 15, 13, 12, 14, 18, 17, 16, 19, 25, 23, 21, 22, 24, 28, 27, 30};
    int n = 17;
    for(int i = 0; i < n; i++)
        tree.insert(arr[i]);

    tree.remove(20); // you here are removing the root and the new root should be 21 the minimum value in the right subtree you can make sure of this by doing traverse using PreOrder traverse
    cout << "InOrder: "; // root in between
    tree.traverse(Order::InOrder); // will print your data sorted
    cout << '\n';
    cout << "PreOrder: "; // root in the beginning
    tree.traverse(Order::PreOrder);
    cout << '\n';
    cout << "PostOrder: "; // root in the end
    tree.traverse(Order::PostOrder);
    cout << '\n';

    Node<int>* node = new Node(10); // this is dynamic allocation; you have to assign to the node to a pointer you are creating an object using the dynamic way
    cout << node->data << '\n';
    cout << node->left << '\n';
    cout << node->right << '\n';

    Node<int> node2(10); // this is not dynamic allocation; you just have to give the object a name
    cout << node2.data << '\n';
    cout << node2.left << '\n';
    cout << node2.right << '\n';


    int check_value ; cin >> check_value;
    cout << (tree.contain(check_value) ? "Existed Value" : "Non-existed Value") << '\n';

    return 0;
}
