#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<70> Mask; // for bit mask operations
 
#define FORI(s, e) for(int i = s; i < e; i++) 
 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e6 + 7; // means 1 million + 1 == 1000001;
const ll prime_mod = 1e9 + 7;
/* ------------------------------------------------------------------------- */
// open addressing (closed hashing) to avoid collision the first technique which handle the collision in the same array itself by u have atleast to make your table size by 2 * n not only n
 
const int siz = 7919; // it's a prime number.

class Hash_Table{

    int key[siz] = {0}, value[siz];
public:
    Hash_Table(){}
    
    int hash_fun(int id){
        int prime1 = 1861, prime2 = 4289;
        return ((id * prime1) + prime2)% siz; // you have to mod by size so the hash function don't give you an index out of range
    }

    int hash_fun2(int id){ // only used when collision happened
        int prime1 = 5281, prime2 = 919;
         return ((id * prime1) + prime2)% siz;
    }

    void insert(int id, int val){
        int hash_code = hash_fun(id);
        // int need_another_hash = hash_fun2(id);
        while(!(key[hash_code] == id || key[hash_code] == 0)){
            hash_code = (hash_code + 1) % siz; // instead of using increase by one if you don't find the index of the hashcode not available we can use another hash function
            // hash_code = (hash_code + need_another_hash) % siz;
            // you will iterate untill you find an available index to avoid collision
        }
        key[hash_code] = id;
        value[hash_code] = val;
    }    

    pair<int, int> at(int id){
        int hash_code = hash_fun(id);
        // int need_another_hash = hash_fun2(id);
        // this loop will excute only if the 2 conditions inside evaluated by 0;
        while(!(key[hash_code] == id || key[hash_code] == 0)){ // we assume that there's no id is 0
            hash_code = (hash_code + 1) % siz; // instead of using increase by one if you don't find the index of the hashcode not available we can use another hash function
            // hash_code = (hash_code + need_another_hash) % siz;
            // you will iterate untill you find an available index to avoid collision
        }
        if(key[hash_code] == id) return {hash_code, value[hash_code]};
        return {-1, -1};
    }

    ~Hash_Table(){}
};


int main(){

    Hash_Table ht; // taking an object
    int cnt ; cin>>cnt;
    while(cnt--){
        int id, val; cin>>id>>val;
        ht.insert(id, val);
    }
    
    int q; cin>>q;
    while(q--){
        int id; cin>>id;
        pair<int, int> ans = ht.at(id);
        cout<<"id "<<id<<'\n'; 
        cout<<"its hash_code or index in the array "<< ans.first <<'\n';
        cout<<"its value "<< ans.second <<'\n';
        cout<<"--------------------------------------\n";
    }

    return 0;
}