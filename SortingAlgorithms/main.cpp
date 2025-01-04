#include <iostream>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSorty(int arr[], int s){
    int tempMinIdx;
    for(int i = 0; i < s - 1; i++){
            tempMinIdx = i;
        for(int j = i + 1; j < s; j++){
            if(arr[tempMinIdx] > arr[j]){
                tempMinIdx = j;
            }
        }
        swap(arr[i], arr[tempMinIdx]);
    }
}

void insertionSort(int arr[], int s){
    int key;
    for(int i=1 ; i < s; i++){

         key = arr[i];
         int j = i - 1;
         while(j >= 0 && arr[j] > key){
           arr[j + 1] = arr[j];
            j--;
         }
        arr[j + 1] = key;

    }
}

void bubbleSort(int arr[],int s){
    bool flag = false;
    for(int i = 1; i < s; i++){

        for(int j = 0; j <  s -1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if(!flag){
                cout << "array is already sorted\n";
            break;
        }
    }

}

int main()
{
   int arr[5] = {3, 4, 1, 2, 5};
   //int arr[5] = {1, 2, 3, 4, 5};
  // bubbleSort(arr, 5);

  //selectionSorty(arr, 5);
  insertionSort(arr, 5);
   for(int i =0; i < 5; i++)
        cout << arr[i]<< " ";
   cout << "\n";
    return 0;
}
