// Header file
// Created by Mohamed Nasr on 12/6/2022.
//

#ifndef BINARY_SEARCH_TREE_BINARYSEARCHTREE_H
#define BINARY_SEARCH_TREE_BINARYSEARCHTREE_H

#include <iostream>
#include <cassert>
using namespace std;

enum Order
{ // all these value is just a representation for indices InOrder for 0 and PreOrder for 1 and PostOrder for 2
    InOrder,
    PreOrder,
    PostOrder
};


template<class detect>
class Node{
public: // or u can do this structure using struct since it's public by default but in this case you have to declare the struct in inside bst class to know detect datatype from it but what are we doing here is better for abstraction
    detect data;
    Node<detect>* left;
    Node<detect>* right;

    Node();
    Node(detect);
    ~Node();
};



template<class detect>
class BinarySearchTree {

private:
    Node<detect>* root;

public:
    BinarySearchTree();

    bool contain(detect);
    void insert(detect);
    void traverse(Order);
    void remove(detect);

    ~BinarySearchTree();

private: // helper function not for the user
    void inOrder(Node<detect>*);
    void preOrder(Node<detect>*);
    void postOrder(Node<detect>*);

    Node<detect>* findNode(detect); // will return a pointer to node
    Node<detect>* findMIn(Node<detect>*); // to find the minimum in the right subtree to replace the root
    Node<detect>* findParent(detect);

};



#endif //BINARY_SEARCH_TREE_BINARYSEARCHTREE_H
