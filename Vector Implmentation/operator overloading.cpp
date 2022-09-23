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

class Employss{
    int x, y; string name;
public:
    Employss(int s, int k, string str): x(s), y(k), name(str){}
    Employss();

    // operator overloading 

    string operator +(Employss & emp) const{
        return this->name + emp.name;
    }
};

int main(){


    Employss emp1(5, 7, "Mohamed Nasr ");
    Employss emp2(4, 3, "Hamed Nasr");

    cout<< emp1 + emp2 <<'\n';
    return 0;
}