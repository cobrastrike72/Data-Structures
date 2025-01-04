#include <iostream>
#include <cstring> // For strcpy

using namespace std;


struct Node{
    int id;
    char name[50];
    int age;

    Node* prev;
    Node* next;
};

class LinkedList{

    Node* head;
    Node* tail;

public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }


    void append(int _id, char _name[], int _age ){

        Node* tempNode = new Node();
        tempNode->id = _id;
        strcpy(tempNode->name, _name);
        tempNode->age = _age;
        tempNode->prev = NULL;
        tempNode->next = NULL;


        if(head == NULL){ // the ls was empty
            head = tempNode;
            tail = head;
            head->prev = head;
            head->next = head;
        }
        else{
            tail->next = tempNode;
            tempNode->prev = tail;
            tail = tempNode;
            tail->next = head;
            head->prev = tail;
        }

    }

private:
    Node* searchById(int _id){
        Node* tempNode = head;
        if(head == NULL){
            cout << "Sorry your LinkedList is Empty!!\n";
            return NULL;
        }
        do {
            if(tempNode->id == _id) return tempNode;
            tempNode = tempNode->next;
        }while(tempNode != head);

        return NULL;
    }


public:

    Node deleteNodeById(int _id){
        Node* tempNode = searchById(_id);
        Node returnedNode;
        if(tempNode == NULL){
            returnedNode.id = -1;
            strcpy(returnedNode.name, "No Name");
            returnedNode.age = -1;
            return returnedNode;
        }
        tempNode->prev->next = tempNode->next;
        tempNode->next->prev = tempNode->prev;

        if(tempNode == head && head == tail){ // if it was only one node in the linked list
            head = tail = NULL;
        }
        else if(tempNode == head){ // if you want to delete the first node but (there's other nodes in the DS)
            head = tempNode->next;
        }
        else if(tempNode == tail){ // if you wanna delete the tail node
            tail = tempNode->prev;
        }
        returnedNode.id = tempNode->id;
        returnedNode.age = tempNode->age;
        strcpy(returnedNode.name, tempNode->name);

        delete tempNode; // delete the pointer
        return returnedNode;
    }

    void insert(int _insertionId, int _id, char _name[], int _age){
        if(head == NULL){
            append(_id, _name, _age);
        }
        Node* tempNode = searchById(_insertionId);
        if(tempNode != NULL){

            if(tempNode == tail){
                append(_id, _name, _age);
            }
            else{
                Node* newNode = new Node();
                newNode->next = tempNode->next;
                newNode->prev = tempNode;
                tempNode->next->prev = newNode;
                tempNode->next = newNode;

                newNode->id = _id;
                newNode->age = _age;
                strcpy(newNode->name, _name);
            }
        }

    }
    void display(){
        Node* tempNode = head;
        if(tempNode == NULL){
            cout << "Your Linked List is empty!!\n";
            return;
        }
        do{
            cout << "Name: " << tempNode->name << ", Id: " << tempNode->id << ", Age: " << tempNode->age << "\n";
            tempNode = tempNode->next;
        } while (tempNode != head);
    }

    ~LinkedList(){
        Node* currentNode = head;
        if(currentNode != NULL){
            Node* tempNode = currentNode;
            do{
                currentNode = currentNode->next;
                delete tempNode;
                tempNode = currentNode;
            } while (tempNode != head);
        }
    }
};

int main() {

    LinkedList ls;
    ls.append(1, "Dawood", 32);
    ls.append(2, "Dod", 34);
    ls.append(3, "Sarah", 43);

    ls.append(4, "Ihab", 34);
    ls.append(5, "Ibra", 43);

     ls.display();
    ls.deleteNodeById(2);

    cout << "\n________________________________________________________\n";
    ls.display();

    ls.deleteNodeById(5);
    cout << "\n________________________________________________________\n";
    ls.display();

    ls.deleteNodeById(1);
    cout << "\n________________________________________________________\n";
    ls.display();

    ls.append(8, "ahmad", 34);
    cout << "\n________________________________________________________\n";
    ls.display();

    ls.deleteNodeById(8);
    cout << "\n________________________________________________________\n";
    ls.display();

    ls.deleteNodeById(3);
    cout << "\n________________________________________________________\n";
    ls.display();

    ls.deleteNodeById(4);
    cout << "\n________________________________________________________\n";
    ls.display();


    ls.append(30, "Saleh", 34);
    cout << "\n________________________________________________________\n";
    ls.display();

    ls.append(31, "Mahmoud", 34);
    cout << "\n________________________________________________________\n";
    ls.display();

    ls.append(32, "Farouk", 34);
    cout << "\n________________________________________________________\n";
    ls.display();

    ls.deleteNodeById(31);
    cout << "\n________________________________________________________\n";
    ls.display();

    ls.insert(30, 33, "Jude", 23);
    cout << "\n________________________________________________________\n";
    ls.display();

    ls.insert(32, 34, "Vini", 23);
    cout << "\n________________________________________________________\n";
    ls.display();

    ls.insert(34, 35, "Vede", 23);
    cout << "\n________________________________________________________\n";
    ls.display();



    return 0;
}
