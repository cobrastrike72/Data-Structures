#include <iostream>
using namespace std;

class MinStack {
    int size = 0;
    int capcity = 0;
    int* arr;
    int* mim; 
public:
    MinStack() {
        arr = nullptr;
        mim = nullptr;
    }
    
    void push(int val) {
        create();
        arr[size] = val;
        if(size != 0) mim[size] = min(mim[size - 1], val);
        else mim[size] = val;
        size++;
    }
    
    void pop() {
        size--;
    }
    
    int top() {
        return arr[size - 1];
    }
    
    int getMin() {
        return mim[size - 1];
    }

private: 
	// helper functions
    void create(){
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

    int min(int x, int y){
        if(x > y) return y;
        return x;
    }

    void clear(){
        delete[] arr;
        delete[] mim;
        arr = nullptr, mim = nullptr;
    }

public:

    ~MinStack(){
        clear();
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
    st.push(5);
    st.push(4);
    st.push(8);
    st.push(6);
    st.push(2);
    st.push(1);
     
    cout << "current top is: " <<st.top() << '\n';
    cout << "current min is: " << st.getMin() << '\n';
    st.pop();
    cout << "current top is: " <<st.top() << '\n';
    cout << "current min is: " << st.getMin() << '\n';
    st.pop();
    cout << "current top is: " <<st.top() << '\n';
    cout << "current min is: " << st.getMin() << '\n';
    st.pop();
    cout << "current top is: " <<st.top() << '\n';
    cout << "current min is: " << st.getMin() << '\n';
    st.pop();
    cout << "current top is: " <<st.top() << '\n';
    cout << "current min is: " << st.getMin() << '\n';
    st.pop();
    cout << "current top is: " <<st.top() << '\n';
    cout << "current min is: " << st.getMin() << '\n';
    st.pop();
    
	/*
		output should be
		current top is: 1
		current min is: 1
		current top is: 2
		current min is: 2
		current top is: 6
		current min is: 4
		current top is: 8
		current min is: 4
		current top is: 4
		current min is: 4
		current top is: 5
		current min is: 5
	*/
	
    
	

	return 0;
}
