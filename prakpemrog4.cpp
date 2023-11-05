#include <iostream>
#include <iomanip>

using namespace std;

struct rice {
    double CperW;
    int w;
    int c;
};

void selectionSort(rice rices[], int n){
    for(int i = 0; i < n-1; i++){
        int max = i;
        for(int j = i+1; j < n; j++){
            if(rices[j].CperW > rices[max].CperW || (rices[j].CperW == rices[max].CperW && rices[j].c > rices[max].c)){
                max = j;
            }
        }

        if(max != i){
            swap(rices[i], rices[max]);
        }
    }
}

int main(){
    int n, x;
    cin >> n >> x;

    rice rices[n];
    for(int i = 0; i < n; i++){
        cin >> rices[i].w;
    }

    for(int i = 0; i < n; i++){
        cin >> rices[i].c;
    }

    for(int i = 0; i < n; i++){
        rices[i].CperW = static_cast<double>(rices[i].c)/rices[i].w;
    }

    selectionSort(rices, n);

    int wCount = 0;
    double totalPrice = 0;

    for(int i = 0; i < n; i++){
        if(wCount + rices[i].w <= x){
            wCount += rices[i].w;
            totalPrice += rices[i].c;
        }
        else{
            totalPrice += rices[i].CperW*(x - wCount);
            break;
        }
    }

    cout << fixed << setprecision(5) << totalPrice << endl;

    return 0;
}
