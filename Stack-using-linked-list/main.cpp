#include <iostream>
#include <string.h> // For strcpy, strncpy

using namespace std;

struct node {
    int Id;
    char name[50];
    int Age;
    node* prev;
};

class Stack {
    node* tail;

public:
    Stack() : tail(NULL) {}

    void add(int _id,  char _name[], int _age) {
        node* temp = new node();
        temp->Id = _id;
        strcpy(temp->name, _name);
        temp->Age = _age;
        temp->prev = tail;
        tail = temp;
    }

private:
    node* findHelper(int _id) {
        node* temp = tail;
        while (temp && temp->Id != _id) {
            temp = temp->prev;
        }
        return temp;
    }

public:
    node* Find(int _id) {
        return findHelper(_id);
    }

    bool Pop() {
        if (tail) {
            node* tempPtr = tail;
            tail = tail->prev;
            delete tempPtr;
            return true;
        }
        return false;
    }

    node Top() {
         node tempNode;

             if(tail){
                tempNode.Id = tail->Id;
                strcpy(tempNode.name, tail->name);
                tempNode.Age = tail->Age;
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
        if (!tail) {
            cout << "Sorry, your stack is empty!!\n";
            return;
        }
        node* temp = tail;
        while (temp) {
            cout << "ID: " << temp->Id << ", Name: " << temp->name << ", Age: " << temp->Age << endl;
            temp = temp->prev;
        }
    }
};

int main() {
    Stack s;
    s.Print();
    s.add(1, "Muhammad", 31);
    s.add(2, "Ahmad", 12);
    s.add(3, "Belal", 21);

    s.Print();
    if (s.Pop()) {
        cout << "It has been deleted successfully\n";
    } else {
        cout << "Sorry, stack is empty\n";
    }

    node n = s.Top();
    if (n.Id != -1) {
        cout << n.name << '\n';
    } else {
        cout << "Stack is empty.\n";
    }
     s.add(8, "braaaa", 21);
    s.Print();

    s.Pop();
    s.Pop();
    s.Pop();

    s.Print();
      s.add(88, "de7k", 21);
      s.Print();
    return 0;
}
