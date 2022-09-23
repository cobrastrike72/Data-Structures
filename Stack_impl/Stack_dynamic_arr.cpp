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
class Stack {
private:
    detect* data;
    int size, top, capcity;

public:
    Stack(): size(0), top(-1), capcity(0), data(nullptr){}

    void push(detect val){
        if(data == nullptr || size == capcity) {
            capcity = 2 * size + (size == 0);
            detect* temp_data = new detect[capcity]; // remember new returns always an address so you don't have to put & before new
            copy(temp_data);
            delete[]data;
            data = temp_data;
            temp_data = nullptr;
        }

        data[++top] = val;
        size++;
        // means
        // data[size] = val;
        // size++;
    }

    void copy(detect* temp){
        if(data != nullptr){
            FORI(0, size){
                temp[i] = data[i];
            }
        }
    }

    void pop(){
        size--, top--;
    }

    detect Top(){
        return data[top];
    }

    void clear(){
        size = 0, top = -1;
        delete[]data;
    }

    bool is_empty (){
        return size == 0;
    }

    int Size(){
        return size;
    }

    void display_stack(){
        FORI(0, size) {
            cout<<data[i]<<",\n"[i == size - 1];
        }
    }

    ~Stack(){
        delete[]data;
    }
};


void solve(){
    Stack <int> s;

    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display_stack();
    cout<<s.Top()<<'\n';
    cout<<s.Size()<<'\n';
    s.pop();
    s.push(10);
    s.display_stack();
    cout<<s.Top()<<'\n';
    cout<<s.Size()<<'\n';
    cout<<(s.is_empty() ? "stack is empty\n" : "stack is not empty\n");
    s.clear();
    cout<<s.Size()<<'\n';
    cout<<(s.is_empty() ? "stack is empty\n" : "stack is not empty\n");
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display_stack();
    cout<<s.Top()<<'\n';
    cout<<s.Size()<<'\n';
}

int main(){
    solve();
    return 0;
}