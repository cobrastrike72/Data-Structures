#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<70> Mask; // for bit mask operations
 
#define FORI(s, e) for(int i = s; i < e; i++) 
 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e6 + 7; // means 1 million + 1 == 1000001;
const ll prime_mod = 1e9 + 7;
/* ------------------------------------------------------------------------- */

const int siz = 7919; // it's a prime number.
pair<int, int> hash_table[siz]; // the hash table's datatype will be a pair of int

int hash_fun(int input_val){
    int prime1 = 1861, prime2 = 4289;
    return ((input_val * prime1) + prime2)% siz; // you have to mod by size so the hash function don't give you an index out of range

}
void insert(int input_val){
    int indx = hash_fun(input_val);
    hash_table[indx].first = indx;
    hash_table[indx].second++;
}
pair<int, int> at(int input_val){

    int indx = hash_fun(input_val);
    if(hash_table[indx].second)
        return hash_table[indx];
    else return {-1, -1};
}

int main(){
    int cnt ; cin>>cnt;
    while(cnt--){
        int val; cin>>val;
        insert(val);
    }
    
    int q; cin>>q;
    while(q--){
        int val; cin>>val;
        pair<int, int> ans = at(val);
        cout<<"val "<<val<<'\n';
        cout<<"its hash or index "<< ans.first <<'\n';
        cout<<"its frequency "<< ans.second <<'\n';
        cout<<"--------------------------------------\n";
    }

    return 0;
}