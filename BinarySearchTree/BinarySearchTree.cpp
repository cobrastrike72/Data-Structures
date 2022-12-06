//
// Created by Mohamed Nasr on 12/6/2022.
//

#include "BinarySearchTree.h"

template<class detect>
Node<detect>::Node() : data(0), right(nullptr), left(nullptr) {

}

template<class detect>
Node<detect>::Node(detect val) : data(val), right(nullptr), left(nullptr) {

}

template<class detect>
Node<detect>::~Node() {
    data = 0;
    left = nullptr;
    right = nullptr;
}


template<class detect>
BinarySearchTree<detect>::BinarySearchTree() : root(nullptr) {

}

template<class detect>
Node<detect>* BinarySearchTree<detect>::findNode(detect val) {
    Node<detect>* temp = root;
    while(temp != nullptr){
        if(temp->data == val){
            return temp;
        }
        else if(temp->data > val){
            temp = temp->left; // to search in the left subtree
        }
        else{
            temp = temp->right;
        }
    }
    return nullptr; // if this value isn't in our binary_tree
}

template<class detect>
bool BinarySearchTree<detect>::contain(detect val) {
    Node<detect>* check = findNode(val);
    return (check != nullptr);
}

template<class detect>
void BinarySearchTree<detect>::insert(detect val) {
    assert(!contain(val)); // if this value isn't in the tree do the following lines
    Node<detect>* newNode = new Node<detect>(val);
    if( root == nullptr){
        root = newNode;
    }
    else{
        Node<detect>* temp = root;
        while (true){
            if(val > temp->data){
                if(temp->right == nullptr){
                    temp->right = newNode;
                    break;
                }
                temp = temp->right;
            }
            else{
                if(temp->left == nullptr){
                    temp->left = newNode;
                    break;
                }
                temp = temp->left;
            }
        }
    }

}

template<class detect>
void BinarySearchTree<detect>::traverse(Order order) {
    if(order == Order::InOrder){
        inOrder(root);
    }
    else if(order == Order::PreOrder){
        preOrder(root);
    }
    else{
        postOrder(root);
    }
}

template<class detect>
void BinarySearchTree<detect>::inOrder(Node<detect> * node) {
    if(node == nullptr) return;
    inOrder(node->left);
    cout << node->data << ' ';
    inOrder(node->right);
}

template<class detect>
void BinarySearchTree<detect>::preOrder(Node<detect> * node) {
    if(node == nullptr) return;
    cout << node->data << ' ';
    preOrder(node->left);
    preOrder(node->right);
}

template<class detect>
void BinarySearchTree<detect>::postOrder(Node<detect> * node) {
    if(node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << ' ';
}

template<class detect>
Node<detect>* BinarySearchTree<detect>::findMIn(Node<detect> * node) {
    Node<detect>* temp = node;

    while( temp->left != nullptr){
        temp = temp->left;
    }

    return temp;
}

template<class detect>
Node<detect>* BinarySearchTree<detect>::findParent(detect val) {
    assert(contain(val)); // if that value in the tree do the following lines

    Node<detect>* a = root;
    Node<detect>* b = nullptr;

    while (a->data != val){
        b = a;
        if(val < a->data){
            a = a->left;
        }
        else{
            a = a->right;
        }
    }

    return b;
}

template<class detect>
void BinarySearchTree<detect>::remove(detect val) {

    assert(contain(val));
    Node<detect>* temp = findNode(val);

    if(temp->right == nullptr && temp->left == nullptr){ // case one node has no childs
        if(temp == root) root = nullptr;
        else{
            Node<detect>* parent = findParent(temp->data); // to assign its left/right pointer to nullptr depends on the case
            if(temp->data < parent->data){
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        delete temp;
        temp = nullptr;
    }

    else if(temp->left == nullptr && temp->right != nullptr){ // case two has right child
        if(temp == root){
            root = temp->right;
        }
        else{
            Node<detect>* parent = findParent(temp->data); // to assign its left/right pointer to nullptr depends on the case
            if(temp->data < parent->data){
                parent->left = temp->right; // bc you want to move right child of the node you want to delete to its place since the left child doesn't exist
            }
            else {
                parent->right = temp->right;
            }
        }
        delete temp;
        temp = nullptr;
    }

    else if(temp->left != nullptr && temp->right == nullptr){ // case three node has left child
        if(temp == root){
            root = temp->left;
        }
        else{
            Node<detect>* parent = findParent(temp->data); // to assign its left/right pointer to nullptr depends on the case
            if(temp->data < parent->data){
                parent->left = temp->left; // bc you want to move left child of the node you want to delete to its place since the right child doesn't exist
            }
            else {
                parent->right = temp->left;
            }
        }
        delete temp;
        temp = nullptr;
    }

    else { // case four the node has two child
        Node<detect>* min_node_in_right_sub_tree = findMIn(temp->right);

        detect data = min_node_in_right_sub_tree->data; // i just need it's value then delete it

        remove(min_node_in_right_sub_tree->data); // call the function again in case if it has a right child node to handle it

        temp->data = data;
    }
}

template<class detect>
BinarySearchTree<detect>::~BinarySearchTree() {
    while(root != nullptr) remove(root->data);
}

