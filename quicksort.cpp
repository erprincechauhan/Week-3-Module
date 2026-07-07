# include <bits/stdc++.h>
using namespace std;

int quicks(int arr[], int low, int high){
    int pivot = arr[low];   // pivot is the element to sort
    int i = low;  // initial value
    int j = high; // final value
    while(i < j){
        while(arr[i] <= pivot && i <= high -1){  // here we find for the element which is greater than pivot and take the pointer i to it.
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){ // here we find the element which is smaller than pivot and take the pointer j to it.
            j--;
        }

        if (i < j){
            swap(arr[i], arr[j]); // after finding the greater element than pivot i and smaller element than pivot j we swap them.
        }
    }// this loop does it until i < j which means until the both pivots cross each other.

    swap(arr[low], arr[j]);  // then we swap the pivot to its original place.

    return j; // j is the partition index.

}

void quickSort(int arr[], int low, int high){
    if (low < high) {
        int mid = quicks(arr, low, high); // partition index.
        quickSort(arr, low, mid - 1);  // divide the left part.
        quickSort(arr, mid + 1, high); // divide the right part.
    }
}

int main (){
    int n;
    cout << "Enter the size of array: ";
    cin >> n ;

    int arr[n];
    cout << "Enter the elements of array: "<< endl;
    for (int i = 0 ; i < n;i++ ){
        cin >> arr[i];
    }

    int low = 0;
    int high = n - 1;

    quickSort(arr, low, high);

    cout << "Sorted: ";
    for (int i = 0 ; i < n;i++ ){
        cout << arr[i] << " ";
    }

    return 0;
}


/*
-Time Complexity = O(nlogn)
-Space Complexity 
Best: O(1)
Average: O(log n)
Worst: O(n)
*/