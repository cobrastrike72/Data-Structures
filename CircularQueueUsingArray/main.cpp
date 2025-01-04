#include <iostream>
#include <string.h>

using namespace std;


class CirularQueue{
    int* arr;
    int front; // for pop
    int rear; // for push
    int siz;

public:
    CirularQueue(){
        siz = 5;
        rear = front = -1;
    }
    CirularQueue(int _size){
        siz = _size;
        rear = front = -1;
    }

    bool isFull(){
        return (front == rear + 1 ) || (front == 0 && rear == siz - 1);
    }

    bool isEmpty(){
        return front == -1;
    }

    void Enqueue(int _val){
        if(isFull()){
            cout << "Sorry your array is full!\n";
        }
        // 3 cases
        if(rear == -1){// first case queue is empty
            rear = front = 0;
        }
        else if(rear == siz - 1){ // rear at the end of the array and there's places in the begining of the array so make it turn around
            rear = 0;
        }
        else{ // in the middle
            rear++;
        }

        arr[rear] = _val;
    }

    bool dequeue(int& output){
        if(isEmpty()){
            cout << "Sorry the array is empty!\n";
            return false;
        }

        output = arr[front];
        // make the front ready for new dequeue operation
        if(front == rear){ // means it was the last value in the queue
            front = rear = -1; // reset
        }
        else if(front == siz -1){ // make it turn around
            front = 0;
        }
        else{
            front++;
        }

        return true;
    }





};
int main() {

    CirularQueue cq;
    cq.Enqueue(5);
    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);
    cq.Enqueue(40);
    int outputVal;
    cout << (cq.dequeue(outputVal) ? outputVal : -1) << "\n";
    cout << (cq.dequeue(outputVal) ? outputVal : -1) << "\n";
    cq.Enqueue(50);
    cout << (cq.dequeue(outputVal) ? outputVal : -1) << "\n";
    cout << (cq.dequeue(outputVal) ? outputVal : -1) << "\n";
    cout << (cq.dequeue(outputVal) ? outputVal : -1) << "\n";
    cout << (cq.dequeue(outputVal) ? outputVal : -1) << "\n";

    cout << (cq.dequeue(outputVal) ? outputVal : -1) << "\n";
    cout << (cq.dequeue(outputVal) ? outputVal : -1) << "\n";

    return 0;
}
