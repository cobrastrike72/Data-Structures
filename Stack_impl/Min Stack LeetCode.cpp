#include <iostream>
using namespace std;

class MinStack {
    int size = 0;
    int capcity = 0;
    int * arr;
    int* mim; 
public:
    MinStack() {
        arr = nullptr;
        mim = nullptr;
    }
    
    void push(int val) {
        creat();
        arr[size] = val;
        if(size != 0){
            if(val > mim[size - 1]) {mim[size] = mim[size - 1]; mim[size - 1] = val;}
            else mim[size] = val;
        }
        else mim[size] = val;
        size++;
    }
    
    void pop() {
        if(arr[size - 1] != mim[size - 1]) mim[size - 2] = mim[size - 1];
        size--;
    }
    
    int top() {
        return arr[size - 1];
    }
    
    int getMin() {
        return mim[size - 1];
    }

private:
    void creat(){
        if(size == capcity){
            capcity = size * 2 + (size == 0);
            int* temp = new int[capcity];
            int* temp2 = new int[capcity];
            for(int i = 0; i < size; i++){
                temp[i] = arr[i];
                temp2[i] = mim[i];
            }
            delete[] arr;
            delete[] mim;
            arr = temp;
            mim = temp2;
            temp = nullptr;
            temp2 = nullptr;
        }
    }

    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(){
    
    MinStack st;
    st.push(6);
    st.push(5);
    st.push(8);
    
    cout << "current top is: " <<st.top() << '\n';
    cout << "current min is: " << st.getMin() << '\n';
    st.pop();
    cout << "current top is: " <<st.top() << '\n';
    cout << "current min is: " << st.getMin() << '\n';
    st.pop();
    cout << "current top is: " <<st.top() << '\n';
    cout << "current min is: " << st.getMin() << '\n';
    st.pop();
    
	

	return 0;
}
