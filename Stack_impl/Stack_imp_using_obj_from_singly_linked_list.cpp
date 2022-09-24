#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<70> Mask; // for bit mask operations
 
#define FORI(s, e) for(int i = s; i < e; i++) 
 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e6 + 7; // means 1 million + 1 == 1000001;
const ll prime_mod = 1e9 + 7;

// set < vector<int>, greater<vector<int>> > res;
// note that when the set is a vector of values the vector will be sorted and the values 


template <class detect>
class s_linked_list {
private:
    int size_cnt = 0;
    struct node{
        detect val;
        node* nxt;
        node() : nxt(nullptr){

        } // constructor like in class
        node(detect v) : val(v), nxt(nullptr){

        }
    };
    node* head_ptr = nullptr ;
    node* tail_ptr = nullptr ;
public:
    void insert(node* curr, detect v){
        node* new_node = new node(v); // you are here allocating memory and word new returns an address for that locatin
        new_node->nxt = curr->nxt;
        // new_node->val = v; you already give a value for that parameter in the initilization list
        curr->nxt = new_node;
        
        if(new_node->nxt == nullptr) tail_ptr = new_node; // if the new node is the last node
        size_cnt++;
    }

    void push_front(detect v){
        node* new_node = new node(v);
        new_node->nxt = head_ptr;
        if(head_ptr == nullptr) tail_ptr = new_node;
        head_ptr = new_node;
        size_cnt++;
    }

    void push_back(detect v){
        if(tail_ptr == nullptr) push_front(v); // we are reusing our code instead of writing it again
        else insert(tail_ptr, v);
    }

    detect front() const{
        // you must write exception handling when the list empty
        return head_ptr->val;
    }

    detect back() const{
        // you must write exception handling when the list empty
        return tail_ptr->val;
    }

    void pop_front(){
        if(head_ptr != nullptr){
            node* temp = head_ptr;
            head_ptr = head_ptr->nxt;
            delete temp;
            size_cnt--;
        }
    }

    int size() const{
        return size_cnt;
    }
    bool is_empty(){
        return head_ptr == nullptr; // size == 0; // tail_ptr == nullptr;
    }

    void clear(){
        node* temp_ptr = head_ptr;
        while(temp_ptr != nullptr){
            head_ptr = head_ptr->nxt;
            delete temp_ptr; // free memory but not deleting the pointer itself
            temp_ptr = head_ptr;
        }
        size_cnt = 0;
        head_ptr = tail_ptr = nullptr;

        // or you can do just this
        /* while(size_cnt){
            pop_front();
        } */
    }

    node* head_ret() const{ // function will return a pinter that have an address of a node
        return head_ptr; 
    }
    node* tail_ret() {
        return tail_ptr;
    }

    void display(){
        
        node* temp_val = head_ptr;
        while(temp_val != nullptr){
            cout<<temp_val->val<<' ';
            temp_val = temp_val->nxt;
        }
        cout<<'\n';
        temp_val = nullptr;
    }

    ~s_linked_list(){ clear();}

};

template <class detect>
class Stack{ // push_front, front, back, empty, pop_front, size, clear, display
    // using an object from linked list we can create our stack;
    // but won't be a random access
    // we here will use approach push front and pop front and will apply LIFO principle

    s_linked_list <detect> sll;

public:
    void push(detect val){
        sll.push_front(val);
    }   

    detect top(){
        return sll.front();
    }

    detect back(){
        return sll.back();
    }

    void pop(){
        sll.pop_front();
    }

    bool is_empty(){
        return sll.is_empty();
    }

    int size(){
        return sll.size();
    }

    void clear(){
        sll.clear();
    }

    void display(){
        sll.display();
    }

    ~Stack(){
        clear();
    }
};

int main(){
   
    Stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.size()<<'\n';
    s.display();
    s.pop();
    cout<<s.top()<<'\n';
    cout<<s.back()<<'\n';
    cout<<s.size()<<'\n';
    s.push(8);
    s.display();
    cout<<s.size()<<'\n';
    s.clear();
    cout<<(s.is_empty() ? "Stack is empty\n" : "Stack is not empty\n");

    
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<s.size()<<'\n';
    s.display();

    return 0;
}