#include <iostream>
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h> // For _getch()
using namespace std;

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
};




void goToXY(int column, int line){
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
                             GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void textattr(int i){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}




int main()
{
    char menu[9][20] = {"new", "display",  "Search by Id", "Search by Name", "delete by Id", "Delete by Name", "insert after Id", "No. of Emp", "exit"};
    LinkedLits ls;
    int selectedItem = 1;
    char ch;
    char tempChar;
    /*tempChar = _getch();

    tempChar = _getch();
    printf("%d", tempChar);
    _getch();*/
    int columnStep = 12, rowStep = 2;
    int flag = 0;
    do{
        system("cls");
        for(int i = 0; i < 20; i++){
            textattr(0x77);
            goToXY(14 + i, 14);
            printf(" ");
        }
        for(int i = 0; i < 20; i++){
            textattr(0x77);
            goToXY(14 + i, 25);
            printf(" ");
        }
         for(int i = 0; i < 11; i++){
            textattr(0x77);
            goToXY(14, 14 + i);
            printf("  ");
        }
        for(int i = 0; i < 11; i++){
            textattr(0x77);
            goToXY(14 + 18, 14 + i);
            printf("  ");
        }
        textattr(0x07);
        for(int i = 0; i < 9; i ++){
            goToXY(16, 15 + i);
            if(i == selectedItem)
                textattr(0x04);
            printf(menu[i]);
                textattr(0x07);
        }

        ch = _getch();
        switch(ch)
        {
            case -32:
                ch  = _getch();
                switch(ch)
                {
                    case 72:
                        selectedItem--;
                        if(selectedItem < 0) selectedItem = 8;
                           break;
                    case 80:
                        selectedItem++;
                        if(selectedItem > 8) selectedItem = 0;
                        break;

                    }
                break;

            case 71: // Home
                selectedItem = 0;
                break;
             case 79: // end
                 selectedItem = 8;
                 break;

            case 13: // enter
                    system("cls");
                    if(selectedItem == 0){
                        int id;
                        char name[50];
                        int age;
                        cout << "Please enter new emp data\n";
                        cout << "Please enter his id: ";
                        cin >> id;
                        cout << "\nPlease enter his Name: ";
                        cin >> name;
                        cout <<"\nPlease enter his Age: ";
                        cin >> age;
                        ls.add(id, name, age);
                        cout << "Your data has been saved successfully!\n";
                        _getch();
                    }
                    else if(selectedItem == 1){
                            if(ls.isEmpty()){
                                cout << "sorry, your database is empty!!\n";
                                _getch();
                            }
                            else{
                                 ls.Print();
                                _getch();
                            }
                       }
                    else if(selectedItem == 2){
                            int id;
                        cout << "please enter the id of your employee that you wanna fetch his data: ";
                        cin >> id;
                        cout << "\n";
                        node n = ls.Find(id);
                        if(n.Id != -1){
                            cout << "Employee is found!\nHis id is <" << n.Id << "> and his name is <" << n.name << "> and his age is <" << n.Age << ">\n";
                        }
                        else cout << "Employee is not found please enter a correct id!\n";
                        _getch();
                    }
                      else if(selectedItem == 3){
                            char _name[100] ;
                        cout << "please enter the name of your employee that you wanna fetch his data: ";
                        cin >> _name;
                        cout << "\n";
                        node n = ls.FindByName(_name);
                        if(strcmpi(_name, n.name) == 0){
                            cout << "Employee is found!\nHis id is <" << n.Id << "> and his name is <" << n.name << "> and his age is <" << n.Age << ">\n";
                        }
                        else cout << "Employee is not found please enter a correct name!\n";
                        _getch();
                    }
                    else if(selectedItem == 4){
                             int id;
                        cout << "please enter the id of your employee that you wanna delete his data: ";
                        cin >> id;
                        cout << "\n";
                        if(ls.delNode(id)){
                            cout << "employee data has been deleted successfully!\n";
                        }
                        else {
                            cout << "sorry, pleas enter a correct id!\n";
                        }
                        _getch();
                    }
                    else if(selectedItem == 5){
                              char _name[100] ;
                        cout << "please enter the name of your employee that you wanna delete his data: ";
                        cin >> _name;
                        cout << "\n";
                        if(ls.delNodeByName(_name)){
                            cout << "employee data has been deleted successfully!\n";
                        }
                        else {
                            cout << "sorry, pleas enter a correct name!\n";
                        }
                        _getch();
                    }
                    else if(selectedItem == 6){
                        int prev_id, id, age;
                        char name[50];
                        cout << "Please enter the Id of the employee you wanna insert your data after: ";
                        cin >> prev_id;
                        cout << "\n";
                        cout << "Please enter new emp data\n";
                        cout << "Please enter his id: ";
                        cin >> id;
                        cout << "\nPlease enter his Name: ";
                        cin >> name;
                        cout <<"\nPlease enter his Age: ";
                        cin >> age;
                        bool isdone = ls.insertNodeAfter(prev_id, id, name, age);
                        if(isdone){
                            cout << "your data has been saved successfully!\n";
                        }
                        else {
                            cout << "Sorry the id of the employee you wanna insert your data after doesn't exist!\n";
                        }
                        _getch();
                    }
                    else if(selectedItem == 7){
                        cout << "No of employee in your firm is: " << ls.getCount() << "\n";
                        _getch();
                    }
                    else{
                        cout << "End of the program!\n";
                        _getch();
                        flag = 1;
                    }



                break;

            case 27:
                flag = 1;
                break;
        }

    }while(flag == 0);



    return 0;
}



