#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef bitset<70> Mask; // for bit mask operations
 
#define FORI(s, e) for(int i = s; i < e; i++) 
 
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 2e6 + 7; // means 1 million + 1 == 1000001;
const ll prime_mod = 1e9 + 7;
/* ------------------------------------------------------------------------- */
// priority queue is implemented interanlly using heap and heap is just a complete binary tree

class Heap{ // descending order // the root is the minimum value
private:    
    vector <int> tree;
public:
    Heap(){}
    Heap(const vector<int> & vec) : tree(vec){
        int j = size() - 1;
        // you are here trying to reach the last parent node in the vector
        for(int i = (j - 1)/ 2; i >= 0; i--) sift_down(i); // to get the max on the top
    }

    void sift_down(int parent_indx){ // used in case we are poping
        int left_child_indx = parent_indx * 2 + 1;
        int right_child_indx = parent_indx * 2 + 2;
        int siz = int(tree.size());

        if(left_child_indx >= siz) return; // base case
        // we don't need to handle the right child's index because it will be already handled by the left child's index since the left child's index is always less than the right one

        if(right_child_indx < siz && tree[left_child_indx] < tree[right_child_indx])
            swap(tree[left_child_indx], tree[right_child_indx]); // that means that i'm sure that the left child node is always bigger than the right child node
    
        if(tree[left_child_indx] > tree[parent_indx]){
            swap(tree[left_child_indx], tree[parent_indx]);
            sift_down(left_child_indx); // recursive case
        }
    }

    void sift_up(int child_indx){ // used in case we're pushing
        if(child_indx == 0) return; // base case
        int parent_indx = (child_indx - 1) / 2;
        if(tree[parent_indx] < tree[child_indx]){
            swap(tree[parent_indx], tree[child_indx]);
            sift_up(parent_indx); // recursive case
        }
    }
    int const size(){
        return int(tree.size());
    }
    void push(int val){ // use sift up // O(log n);
        tree.push_back(val);
        sift_up(size() - 1);
    }

    void pop(){ // use sift down // O(log n)
        tree[0] = tree[size() - 1];
        tree.pop_back();
        sift_down(0);
    }

    bool empty(){
        return tree.empty();
    }

    void clear(){
        tree.clear();
    }

    int const top(){
        return tree[0];
    }
    ~Heap(){}
};

int main(){
    int n; cin>>n;
    vector <int> vec(n);
    FORI(0, n) cin>>vec[i];
    Heap pq(vec);
    cout<<"-----------------------------------------\n";
    while(!pq.empty()){
        cout<< pq.top()<<'\n';
        pq.pop();
    }
    cout<<"enddddddd\n";
    return 0;
}