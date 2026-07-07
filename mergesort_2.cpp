# include <bits/stdc++.h>
using namespace std;

void mergeEle(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high){  // iterating through the arrays to merge them in sorted order.
        if(arr[left] <=  arr[right]){
            temp.push_back(arr[left]);
            left++;
        }   
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while( left <= mid){ // if only left array's element are remaining after itereation.
        temp.push_back(arr[left]);
        left++;
    }

    while( right <= high){ // if only right array's element remaining after iteration.
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++){  // entering the sorted array elements into original array.
        arr[i] = temp[i-low];
    }

}

void mergeSort(vector<int> &arr, int low, int high){
    if (low >= high) return;
    int mid = (low + high)/2;  
    mergeSort(arr,low,mid);      // divides the left side until only one element is remaining. here mid is acting as high to divide.
    mergeSort(arr,mid+1,high);   // divides the right side until only one element is remaining. here mid+1 is acting as low.
    mergeEle(arr,low,mid,high);
}

int main(){
    int n ;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    vector<int> arr;
    cout << "Enter the elements of array: "<< endl;
    for (int i = 0 ; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    } 
    int low = 0; 
    int high = n-1 ;
    mergeSort(arr,low,high);

    cout <<"Sorted: " ;
    for (auto it: arr){
        cout << it << " ";
    }
        cout << endl;

    // Median
    int median;
    if (n % 2 == 1)
        median = arr[n / 2];
    else
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2;

    cout << "Median: " << median << endl;

    // Count elements greater than median
    int count = 0;
    for (int x : arr)
        if (x > median)
            count++;

    cout << "Orders Above Median: " << count << endl;

    // Difference
    cout << "Difference: " << arr[n - 1] - arr[0] << endl;

    return 0;
}



/*

-Time Complexity
Merge Sort: O(n log n)
Median: O(1)
Count Above Median: O(n)
Difference: O(1)

Overall Time Complexity of merge sort : O(n log n)

Space Complexity
O(n) (temporary arrays used during merging)

*/
