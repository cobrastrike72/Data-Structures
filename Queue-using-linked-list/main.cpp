#include <iostream>
#include <string.h> // For strcpy, strncpy

using namespace std;

struct node {
    int Id;
    char name[100];
    int Age;
    node* next;
};

class Queue {
    node* tail;
    node* head;

public:
    Queue() : tail(NULL), head(NULL) {}

    void Enqueue(int _id,  char _name[], int _age) {
        node* temp = new node();
        temp->Id = _id;
        strcpy(temp->name, _name);
        temp->Age = _age;
        temp->next = NULL;

        if(head == NULL){
             head = tail = temp;
        }
        else{
            tail->next = temp;
        }
        tail = temp;
    }

private:
    node* findHelper(int _id) {
        node* temp = tail;
        while (temp && temp->Id != _id) {
            temp = temp->next;
        }
        return temp;
    }

    node* Find(int _id) {
        return findHelper(_id);
    }
public:

    bool Dequue() {
        if (head) {
            node* tempPtr = head;
            head = head->next;
            if(head == NULL){
                tail = NULL;
            }
            delete tempPtr;
            return true;
        }
        return false;
    }

    node FirstNode() {
         node tempNode;

             if(head){
                tempNode.Id = head->Id;
                strcpy(tempNode.name, head->name);
                tempNode.Age = head->Age;
             }
             else{
                tempNode.Id = -1;
                strcpy(tempNode.name, "no name");
                tempNode.Age = -1;
             }
             return tempNode;
    }

    bool isEmpty() {
        return tail == NULL;
    }

    void Print() {
        if (!head) {
            cout << "Sorry, your queue is empty!!\n";
            return;
        }
        node* temp = head;
        while (temp) {
            cout << "ID: " << temp->Id << ", Name: " << temp->name << ", Age: " << temp->Age << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Queue s;
    if (s.Dequue()) {
        cout << "It has been deleted successfully\n";
    } else {
        cout << "Sorry, stack is empty\n";
    }
    s.Print();
    s.Enqueue(1, "Muhammad", 31);
    s.Enqueue(2, "Ahmad", 12);
    s.Enqueue(3, "Belal", 21);

    s.Print();

    if (s.Dequue()) {
        cout << "It has been deleted successfully\n";
    } else {
        cout << "Sorry, stack is empty\n";
    }
    s.Enqueue(4, "ihab", 43);

    node n = s.FirstNode();
    if (n.Id != -1) {
        cout << n.name << '\n';
    } else {
        cout << "Queue is empty.\n";
    }

    s.Print();

     if (s.Dequue()) {
        cout << "It has been deleted successfully\n";
    } else {
        cout << "Sorry, stack is empty\n";
    }

    s.Print();
    s.Dequue();
    s.Dequue();
    s.Dequue();
    s.Dequue();
    s.Print();
    s.Enqueue(22, "de7k", 23);
    s.Print();
    return 0;
}
