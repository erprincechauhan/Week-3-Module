#include <bits/stdc++.h>
using namespace std;

// Partition function (Descending Order)
int partition(vector<long long>& arr, int low, int high) {
    long long pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {   // Descending order
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort
void quickSort(vector<long long>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the size of vector: ";
    cin >> n;

    vector<long long> arr(n);

    long long sum = 0;
    cout << "Enter the elements of vector: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    quickSort(arr, 0, n - 1);

    // Sorted values
    cout << "Sorted: ";
    for (long long x : arr)
        cout << x << " ";
    cout << endl;

    // Top 5 values
    cout << "Top 5: ";
    long long topSum = 0;

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
        topSum += arr[i];
    }
    cout << endl;

    // Average of Top 5
    cout << "Average of Top 5: " << topSum / 5.0 << endl;

    // Overall Average
    double overallAverage = (double)sum / n;

    int count = 0;
    for (long long x : arr)
        if (x > overallAverage)
            count++;

    cout << "Values Above Overall Average: " << count << endl;

    return 0;
}

/*
-Time Complexity
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n²)

-Space Complexity
Average: O(log n) (recursion stack)
Worst: O(n)
*/