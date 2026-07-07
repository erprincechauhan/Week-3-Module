#include <bits/stdc++.h>
using namespace std;

// Heapify function
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(vector<int>& arr, int n) {

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    cout << "Enter the size of vector: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of vector: ";

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    heapSort(arr, n);

    cout << "Sorted: ";
    for (int x : arr){
        cout << x << " ";
    }
    return 0;
}

/*
-Time Complexity: O(n log n)
 `
-Space Complexity
Auxiliary Space: O(1)
Recursive heapify call stack: O(log n)
*/