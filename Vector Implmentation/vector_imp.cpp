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

class Vector{
   int *data, size, capacity; // size and capacity aren't pointers it's just the variable data 
public:
    Vector(): data(nullptr), size(0), capacity(0){}
    Vector(int sz, int val): size(sz){
        data = new int[size]; // here you are trying to allocate a dynamic array and trying also to initilize it with ones
        FORI(0, size) data[i] = val;
        capacity = size ;
    }

    Vector(const Vector & vec){ // your are passing by reference for speending and const for not changing anything in the vector that is sent as an argument
        copy(vec);
    }

    Vector &operator =( const Vector & vec) { // we will use the above constructor to assign vector to vector instead of writing ever thing again
        copy(vec);
        return *this;
    }

    void copy(const Vector & vec){
        if(data != nullptr){ 
            delete[]data; // delete the sequnce you have allocated
            data = nullptr; // and then make pointer data point to null not pointing to any thing actually
        } // but why i would do this condition bc if the data were pointing to larger sequence that needed or less so you have to free that memory first and then point to another sequence to avoid memory leak
        
        capacity = size = vec.Size();
        data = new int[size];
        FORI(0, size) data[i] = vec.data[i];

    }

    int Size() const { return size; } // you must made as constant function the value that will be returned must be we did that way because when 
    // did call the object vec above was const then if you will go to use its function then it must be const also
    // if you are not passing an object as an argument then you won't need for that constant key word


    int Capcity() const { return capacity; } // we do the first char of the name of each function by upper letter bc there an attribute with the same name 
    // and this why you see function or attributes begin with __gcd() for an example


    bool empty() const { return (size == 0);}

    int back() const {
        // note you should do exception handling bc if the size was 0 means the vector was empty you should handle this
        return data[size - 1]; 
    }

    int front() const {
        // note you should do exception handling bc if the size was 0 means the vector was empty you should handle this
        return data[0];
    }

    void push_back(const int val){
        if (size == capacity){
            reserve( (capacity << 1) + (capacity == 0) ); // means multiply capcity by 2 and if the capcity was equall zero then the multiplication will not affect it so the next plus condition will handle it and make it one
        }
        data[size++] = val;
    }

    void reserve(int new_capcity){
        if(new_capcity < size) return; // becuase you already have size enough
        update_capcity(new_capcity);
    }
    
    void update_capcity(int new_cap){
        int* temp = new int[new_cap];
        FORI(0, size) temp[i] = data[i];
        FORI(size, new_cap) temp[i] = 0; // we did that step bc vector always initilize its values by 0s there's no garbage
        capacity = new_cap;
        swap(data, temp); // so data pointer will be point to the sequence that temp was pointing to and vice versa
        delete[]temp; // so we can avoid memory leak
        temp = nullptr; // to point to nothing to no address
    }

    void clear(){
        size = capacity = 0;
        if(data != nullptr) delete[]data;
        data = nullptr;
    }

    void insert(int indx, int val){
        int temp_size = size;
        push_back(back());
        for(int i = temp_size - 1; i >= indx ; i--){
            data[i + 1] = data[i];
        }
        data[indx] = val;
    }

    int operator [](int indx){
        return data[indx];
    }
};  

int main(){

    Vector x;
    x.push_back(1);
    x.push_back(9);
    x.push_back(2);
    x.push_back(10);
    x.push_back(7);

    int sz = x.Size();
    FORI(0, sz) cout<<x[i]<<' ';
    cout<<'\n';
    cout<<sz<<'\n';
    cout<<x.back()<<'\n';
    cout<<x.front()<<'\n';
    x.clear();
    cout<<x.Size()<<'\n';
    return 0;
}