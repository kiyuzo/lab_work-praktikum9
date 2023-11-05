#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace chrono;

// INSERTION SORT
void ascendInsertSort(int arr[], int n) {
    for(int j = 1; j < n; j++) {
        int i = j-1;
        int temp = arr[j];
        while(i >= 0 && arr[i] > temp) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = temp;
    }
}

void descendInsertSort(int arr[], int n) {
    for(int j = 1; j < n; j++) {
        int i = j-1;
        int temp = arr[j];
        while(i >= 0 && arr[i] < temp) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = temp;
    }
}

// SELECTION SORT
void ascendSelectSort(int arr[], int n){
    for(int i = 0; i < n-1; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if(min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void descendSelectSort(int arr[], int n){
    for(int i = 0; i < n-1; i++) {
        int max = i;
        for(int j = i+1; j < n; j++) {
            if (arr[j] > arr[max]) {
                max = j;
            }
        }
        if(max != i) {
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
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

    // INSERTION
    cout << "  Insertion            Ascend           " << measureExecutionTime([&] { ascendInsertSort(arr, n);
    }) << " miliseconds" << endl;

    cout << "  Insertion            Descend          " << measureExecutionTime([&] { descendInsertSort(arr, n);
    }) << " miliseconds" << endl;
    

    // SELECTION
    cout << "  Selection            Ascend           " << measureExecutionTime([&] { ascendSelectSort(arr, n);
    }) << " miliseconds" << endl;

    cout << "  Selection            Descend          " << measureExecutionTime([&] { descendSelectSort(arr, n);
    }) << " miliseconds" << endl;

    return 0;
}
