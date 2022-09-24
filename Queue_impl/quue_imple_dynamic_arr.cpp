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
class Queue{
    detect* data_ptr;
    int size, capcity, str, cnt;

public:
    Queue(): data_ptr(nullptr), size(0), capcity(0), str(0), cnt(0){}  

    void push(detect val){
        if(data_ptr == nullptr || size == capcity){
            detect* temp_ptr = new detect[2 * size + (size == 0)];
            copy(temp_ptr);
            delete[]data_ptr; // to free the allocated memory first
            data_ptr = temp_ptr;
            temp_ptr = nullptr;
        }
        data_ptr[cnt++] = val;
        size++;
    } 

    void copy(detect* temp){
        if(data_ptr != nullptr){
            FORI(str, size) temp[i] = data_ptr[i];
        }
    }

    void pop(){
        size--, str++;
    } 

    bool is_empty(){
        return size == 0;
    }

    void clear(){
        size = capcity = cnt = str = 0;
        delete[]data_ptr;
    }

    detect get_front(){
        return data_ptr[str];
    }

    detect get_back(){
        return data_ptr[cnt - 1];
    }
    int Size(){
        return size;
    }
    ~Queue(){
        // delete[]data_ptr;
    }
};


int main(){

    Queue <int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.get_front()<<'\n';
    cout<<q.get_back()<<'\n';

    cout<<"size is "<< q.Size()<<'\n';

    q.pop();

    cout<<q.get_front()<<'\n';
    cout<<q.get_back()<<'\n';

    cout<<"size is "<< q.Size()<<'\n';

    q.clear();
    cout<<(q.is_empty() ? "Yes, it's empty\n" : "No, it's not empty\b");
    return 0;
}