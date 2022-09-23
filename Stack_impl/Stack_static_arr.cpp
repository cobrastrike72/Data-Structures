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


const int max_size = 100;

template <class detect> 
class Stack{
private:
    int top;
    detect arr[max_size];
    int size;

public:
    Stack(): top(-1), size(0){}
    void puch(detect val){
        if(top >= max_size - 1) cout<<"Sorry stack is completed\n";
        else{
            // top++;
            // arr[top] = val;
            arr[++top] = val;
            size++;
        }
    }

    void pop(){
        if(size == 0) cout<<"sorry stack is already empty\n";
        else top--, size--;
    }

    detect Top(){
        
        return arr[top];
       
    }

    void clear(){
        size = 0;
        top = -1;
    }

    int Size()const { return size;}
};




void solve(){ 
    Stack <string> s;
    s.puch("Mohamed");
    s.puch("Nasr");
    s.puch("Mohamed");
    s.puch("Mahomud");
    cout<<s.Top()<<'\n';

    cout<<s.Size()<<'\n';
    s.pop();
    cout<<s.Top()<<'\n';
    cout<<s.Size()<<'\n';
    s.clear();
    cout<<s.Size()<<'\n';
    s.pop();
    // cout<<"-------------------------------------\n";
    // cout<<s.Top()<<'\n';

    

}



 
int main()
{
    // freopen("contest.in","rt",stdin);
    FAST
    // preprocessing
    
    // int t; cin>>t;  
    // while(t--)
        solve();
        
    // Mask mask = 4747;
    // cout<<mask<<'\n';
    // Mask mask2 = 7474;
    // printing is from right to left in the binary representation
    // cout<<mask2<<'\n';
 
    return 0;
 
} 





