#include <iostream>
#include <cstring> // For strcpy

using namespace std;

struct Node{
    int id;
    char name[50];
    int age;
    Node* next;
};

class LinkedList{
    Node* head;
    Node* tail;

public:
    LinkedList(){
        head = tail = NULL;
    }

    void append(int _id, char _name[], int _age)
    {
        Node* tempNode = new Node();
        tempNode->id = _id;
        tempNode->age = _age;
        strcpy(tempNode->name, _name);
        tempNode->next = NULL;

        if(head == NULL){
            head = tempNode;
            tail = tempNode;
        }
        else{
            tail->next = tempNode;
            tail = tempNode;
        }
    }


    Node* searchById(int _id){
        Node* tempNode = head;
        while(tempNode != NULL){
            if(tempNode->id == _id) return tempNode;
            tempNode = tempNode->next;
        }
        return NULL;
    }

    void deleteById(int _id)
    {
        Node* tempNode = searchById(_id);
        if(head == NULL){
            cout << "Sorry the DS is empty";
            return;
        }
        if(tempNode == NULL){
            cout << "there's no employee by that id";
            return;
        }

        if(tempNode == head && tail == head){
            tail = head = NULL;
        }
        else if(tempNode == head){
            head = head->next;
        }
        else if(tempNode == tail){
            Node* prvNode = head;
            while(prvNode->next != tempNode){
                prvNode = prvNode->next;
            }
            tail = prvNode;
            tail->next = NULL;
        }
        else{
            Node* prvNode = head;
            while(prvNode->next != tempNode){
                prvNode = prvNode->next;
            }
            prvNode->next = tempNode->next;
        }


        delete tempNode;

    }

    void insertAfter(int _prvId, int _id, char _name[], int _age){

        Node* tempNode = searchById(_prvId);
        if(tempNode == NULL) {
            cout << "Sorry your DS is empty!\n";
        }
        Node* newNode = new Node();
        newNode->id = _id;
        newNode->age = _age;
        strcpy(newNode->name, _name);
        newNode->next = NULL;


        if(head == NULL){
            head = tail = newNode;
        }
        else if(tempNode == tail){
            newNode->next = tempNode->next;
            tempNode->next = newNode;
            tail = newNode;
        }
        else{
            newNode->next = tempNode->next;
            tempNode->next = newNode;
        }
    }


    void display(){

        Node* tempPointer = head;
        while(tempPointer != NULL){
            cout << tempPointer->id <<":" << tempPointer->name << ":" << tempPointer->age << "\n";
            tempPointer = tempPointer->next;
        }
    }
};

int main(){
    LinkedList ls;

    ls.append(1, "Dawood", 23);
    ls.append(2, "Dood", 34);
    ls.append(3, "ibra", 34);

    ls.display();
    ls.insertAfter(2, 5, "ahmad", 34);
    cout << "\n________________________________________________\n";

    ls.display();

    ls.insertAfter(3, 10, "Ali", 32);

    cout << "\n________________________________________________\n";

    ls.display();

    ls.insertAfter(1, 11, "Sameh", 32);

    ls.deleteById(1);

    cout << "\n________________________________________________\n";

    ls.display();

    ls.deleteById(2);

    cout << "\n________________________________________________\n";

    ls.display();

    ls.deleteById(10);
    cout << "\n________________________________________________\n";

    ls.display();

    return 0;
}
