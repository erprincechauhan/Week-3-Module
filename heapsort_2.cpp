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
    double sum = 0;
    cout << "Enter the elements of vector: ";

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    heapSort(arr, n);

    cout << "Sorted: ";
    for (int x : arr){
        cout << x << " ";
    }
    cout << endl;

    // Fastest and Slowest
    cout << "Fastest: " << arr[0] << endl;
    cout << "Slowest: " << arr[n - 1] << endl;

    // Average
    double average = sum / n;
    cout << fixed << setprecision(2);
    cout << "Average: " << average << endl;

    // Count cases faster than average
    int count = 0;
    for (int x : arr){
        if (x < average){
            count++;
        }
    }
    cout << "Cases Faster Than Average: " << count << endl;

    // Percentage
    double percentage = (count * 100.0) / n;
    cout << "Percentage: " << percentage << "%" << endl;

    return 0;
}



/*
- Time Complexity : O(n log n)

- Space Complexity
Auxiliary Space: O(1) (in-place sorting)
Recursive heapify() call stack: O(log n)
*/