#include <iostream>

using namespace std;


int binarySearch(int arr[], int size, int val){
    int left = 0, right = size - 1;
    int mid =( left + right) /2;

    while(left <= right){
        mid =( left + right) /2;
        if(arr[mid] == val) return mid;
        else if(arr[mid] < val){
            left = mid + 1;
        }
        else right = mid - 1;

    }

    return -1;
}

int binarySearchRecursive(int arr[], int left, int right, int val){

    if(left > right) return -1;
    int mid = (left + right) / 2;
    if(arr[mid] == val) return mid;

    if(arr[mid] < val) return binarySearchRecursive(arr, mid + 1, right, val);
    return binarySearchRecursive(arr,left, mid - 1, val);

}

int main()
{
   int arr[5] = {1, 2, 3, 4, 5};

   cout << "index of your element using binary search using while loop: " << binarySearch(arr, 5, 4);
   cout << "\n";
   cout << "index of your element using binary search using recursive function: " << binarySearchRecursive(arr, 0, 5, 4);
   cout << "\n";
    return 0;
}
