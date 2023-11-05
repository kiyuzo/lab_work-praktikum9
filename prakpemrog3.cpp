#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace chrono;

//BUBBLE SORT (caused i used bubble sort in the first problem)
void ascendBubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void descendBubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// STL SORT
void ascendSTLsort(int arr[], int n){
    sort(arr, arr + n);
}

void descendSTLsort(int arr[], int n){
    sort(arr, arr + n, greater<int>());
}


// GENERATE RANDOM ARRAY ELEMENT
void generateRandomArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; // range of int 1 - 100
    }
}

// MEASURE THE RUNNING TIME
template <typename Func>
long long measureExecutionTime(Func func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}

int main(){
    int n;
    cout << "Please enter the max amount of data to be generated : ";
    cin >> n;

    int arr[n];
    generateRandomArray(arr, n);

    cout << "Sorting Method      Ascend/Descend      Running Time" << endl;

    // BUBBLE
    cout << "   Bubble              Ascend           " << measureExecutionTime([&] { ascendBubbleSort(arr, n);
    }) << " miliseconds" << endl;

    cout << "   Bubble              Descend          " << measureExecutionTime([&] { descendBubbleSort(arr, n);
    }) << " miliseconds" << endl;

    //STL
    cout << "    STL                Ascend           " << measureExecutionTime([&] { ascendSTLsort(arr, n);
    }) << " miliseconds" << endl;

    cout << "    STL                Descend          " << measureExecutionTime([&] { descendSTLsort(arr, n);
    }) << " miliseconds" << endl;

    return 0;
}
