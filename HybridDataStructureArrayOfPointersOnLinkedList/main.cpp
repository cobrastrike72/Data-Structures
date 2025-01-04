#include <iostream>
#include <string.h>

using namespace std;

#define Dawood ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct node{
    int Id;
    char name[50];
    int Age;

    node* prev;
    node* next;
};

class LinkedLits{
    node* head;
    node* tail;

public:
    LinkedLits(){
        head = NULL;
        tail = NULL;
    }
    void add(int _id, char _name[], int _age){
        node* temp;
         temp = new node();
            temp->Id = _id;
            strcpy(temp->name, _name);
            temp->Age = _age;
            temp->prev = NULL;
            temp->next = NULL;
        if(head == NULL){
            temp->prev = NULL;
                temp->next = NULL;
            tail = head = temp;
        }
        else{

            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }
    private:
    node* findHelper(int _id){
        node* temp = head;
        while(temp && temp->Id != _id ){
            temp = temp->next;
        }



        return temp;
    }

    node* findHelperByName( char _name[]) {
        node* temp = head;
        while (temp && strcmpi(temp->name, _name) != 0) {
            temp = temp->next;
        }
        return temp;
    }
    public:
    node Find(int _id){
        node* temp = findHelper(_id);
        node res;
        if(!temp){

            res.Id = -1;
            strcpy(res.name, "No Name");
            res.Age = -1;
            res.prev = NULL;
            res.next = NULL;
        }
        else{
             res.Id =temp->Id;
            strcpy(res.name, temp->name);
            res.Age = temp->Age;
            res.prev = NULL;
            res.next = NULL;
        }

        return res;
    }
    node FindByName(char _name[]) {
        node* temp = findHelperByName(_name);
        node res;
        if (!temp) {
            res.Id = -1;
            strcpy(res.name, "No Name");
            res.Age = -1;
            res.prev = NULL;
            res.next = NULL;
        } else {
            res.Id = temp->Id;
            strcpy(res.name, temp->name);
            res.Age = temp->Age;
            res.prev = NULL;
            res.next = NULL;
        }
        return res;
    }

    bool delNode(int _id){
         node* tempPointerForNode = findHelper(_id);
        if (!tempPointerForNode) {
            cout << "Cannot delete because the ID does not exist!\n";
            return false;
        } else if (tempPointerForNode == head && tempPointerForNode == tail) {  // Single node case
            head = tail = NULL;
            delete tempPointerForNode;
            return true;
        } else if (tempPointerForNode == head) {
            head = tempPointerForNode->next;
            head->prev = NULL;
            delete tempPointerForNode;
            return true;
        } else if (tempPointerForNode == tail) {
            tail = tempPointerForNode->prev;
            tail->next = NULL;
            delete tempPointerForNode;
            return true;
        } else {
            tempPointerForNode->prev->next = tempPointerForNode->next;
            tempPointerForNode->next->prev = tempPointerForNode->prev;
            delete tempPointerForNode;
            return true;
        }
    }

    bool delNodeByName( char* _name) {
        node* tempPointerForNode = findHelperByName(_name);
        if (!tempPointerForNode) {
            cout << "Cannot delete because the name does not exist!\n";
            return false;
        } else if (tempPointerForNode == head && tempPointerForNode == tail) {  // Single node case
            head = tail = NULL;
            delete tempPointerForNode;
            return true;
        } else if (tempPointerForNode == head) {
            head = tempPointerForNode->next;
            head->prev = NULL;
            delete tempPointerForNode;
            return true;
        } else if (tempPointerForNode == tail) {
            tail = tempPointerForNode->prev;
            tail->next = NULL;
            delete tempPointerForNode;
            return true;
        } else {
            tempPointerForNode->prev->next = tempPointerForNode->next;
            tempPointerForNode->next->prev = tempPointerForNode->prev;
            delete tempPointerForNode;
            return true;
        }
    }


    bool insertNodeAfter(int _prvId, int _id, char _name[], int _age) {
        node* tempNode = findHelper(_prvId);

        if (tempNode) {
            node* newNode = new node();
            newNode->Id = _id;
            newNode->Age = _age;
            strcpy(newNode->name, _name);

            newNode->prev = tempNode;
            newNode->next = tempNode->next;

            if (tempNode->next) {  // Ensure linking for non-tail nodes
                tempNode->next->prev = newNode;
            } else {  // If we're inserting after the tail
                tail = newNode;
            }

            tempNode->next = newNode;
            return true;
        }

        cout << "Cannot insert because the ID does not exist!\n";
        return false;
    }

    bool isEmpty(){
        return head == NULL;
    }

    void Print(){
        node* temp = head;
        while(temp ){
             cout << "ID: " << temp->Id << ", Name: " << temp->name << ", Age: " << temp->Age << endl;
            temp = temp->next;
        }
    }

    int getCount(){
        int cnt = 0;
        node* temp = head;
        while(temp ){
                cnt++;
             //cout << "ID: " << temp->Id << ", Name: " << temp->name << ", Age: " << temp->Age << endl;
            temp = temp->next;
        }
        return cnt;
    }

    ~LinkedLits(){
        node* temp = tail;
        while(temp){
                tail= tail->prev;
            delete temp;
            temp = tail;
        }
    }
};

class HybridDataStructure{

    LinkedLits** arr;
public:
    HybridDataStructure(){
        arr = new LinkedLits*[26];
        for(int i = 0; i < 26; i++){
            arr[i] = new LinkedLits();
        }
    }

    void add(int id, char name[], int age){
        char ch = name[0];
        int idx = int(ch);
        if(ch - 'A' > 32) {
            idx =ch - 32;
        }
        arr[idx - 'A']->add(id, name, age);
    }

    void displayWholeLinkedListByChar(char ch){
        int idx = int(ch);
        if(ch - 'A' > 32){
            idx = idx - 32;
        }
        arr[idx - 'A']->Print();
    }

    void deleteItemByName(char name[]){
        char ch = name[0];
        int idx = int(ch);
        if(ch - 'A' > 32) {
            idx =ch - 32;
        }
        arr[idx - 'A']->delNodeByName(name);
    }

    void displayNodeByName(char name[]){
        char ch = name[0];
        int idx = int(ch);
        if(ch - 'A' > 32) {
            idx =ch - 32;
        }
        node n  = arr[idx - 'A']->FindByName(name);
        cout << "Employee Id <" << n.Id << ">, Employee Name <" << n.name << ">, Employee Age <" << n.Age << ">\n";
    }

    ~HybridDataStructure(){

        for(int i = 0; i < 26; i++){
            delete arr[i];
        }

        delete[] arr;

    }

};


int main()
{

    Dawood
 
    HybridDataStructure hb;
 
    hb.add(1, "Dawood", 32);
    hb.add(2, "dod", 32);
    hb.add(3, "ibra", 33);
    hb.add(4, "ihab", 43);
 
    hb.displayWholeLinkedListByChar('D');
    cout << "\n______________________________________\n";
    hb.displayWholeLinkedListByChar('I');
    cout << "\n______________________________________\n";
    hb.displayNodeByName("Dawood");
 
    hb.deleteItemByName("Dod");
    cout << "\n______________________________________\n";
    hb.displayWholeLinkedListByChar('D');

    return 0;
}
