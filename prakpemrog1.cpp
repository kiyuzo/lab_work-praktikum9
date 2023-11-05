#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Please input the size of the array : ";
    cin >> n;

    int arr[n];
    cout << "Please input your numbers separated by spaces : ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "The median of your array is : ";
    if(n%2 != 0){ // odd
        cout << arr[n/2];
    }
    else if(n%2 == 0){ // even
        cout << (arr[n/2] + arr[n/2 - 1])/2.0;
    }

    return 0;

}
