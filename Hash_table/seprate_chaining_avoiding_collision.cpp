#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<70> Mask; // for bit mask operations
 
#define FORI(s, e) for(int i = s; i < e; i++) 
 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e6 + 7; // means 1 million + 1 == 1000001;
const ll prime_mod = 1e9 + 7;
/* ------------------------------------------------------------------------- */
// seprate chaining to avoid collision the first technique which use the linked list to avoid the collision which will need more space or memory
 
const int siz = 7919; // it's a prime number.
class Hash_Table{
    list<pair<int, int>> hash_table[siz]; // array of linked lists to avoid collision which means the data type for the array will be the linked list and the datatype for the linked list will be pair(int)
public:

    int hash_fun(int input_val){
        int prime1 = 1861, prime2 = 4289;
        return ((input_val * prime1) + prime2)% siz; // you have to mod by size so the hash function don't give you an index out of range

    }
    void insert(int id, int val){
        int hash_code = hash_fun(id);
        for(auto &x : hash_table[hash_code]){
            if(x.first == id) x.second = val; // we will do overwrite if the id was the same bc we wanna update say for example the salary for that guy or that id
            return;
        }
        hash_table[hash_code].emplace_back(id, val); // note that the insertion in linked list is o(n) don't worry about that only worry when you need to access bc it takes O(n)
    }
    pair<int, int> at(int id){
        int hash_code = hash_fun(id);
        // because if there was more one element in the same place having same hash_code means same index
        for(auto &x : hash_table[hash_code]){
            if(x.first == id) return x;
        }
        return {-1, -1};
    }
};


int main(){

    Hash_Table ht;
    int cnt ; cin>>cnt;
    while(cnt--){
        int id, val; cin>>id>>val;
        ht.insert(id, val);
    }
    
    int q; cin>>q;
    while(q--){
        int id; cin>>id;
        pair<int, int> ans = ht.at(id);
        int hash_code = ht.hash_fun(id);
        cout<<"id "<<ans.first<<'\n'; //ans.first == id;
        cout<<"its hash_code or index in the array "<< hash_code <<'\n';
        cout<<"its value "<< ans.second <<'\n';
        cout<<"--------------------------------------\n";
    }

    return 0;
}