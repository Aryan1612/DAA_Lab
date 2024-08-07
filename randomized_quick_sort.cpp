#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int low, int high){

    int pivot = rand()%(high-low+1) + low;
    int x = arr[pivot];
    swap(arr[pivot], arr[low]);
    int i = low;
    for (int j = low+1; j <= high; j++){
        if (arr[j] <= x){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i]);
    return i;
}

void quick_sorting(vector<int> &arr, int low, int high){
    if (low >= high)    return;
    int pi = partition(arr, low, high);
    quick_sorting(arr, low, pi-1);
    quick_sorting(arr, pi+1, high);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quick_sorting(arr, 0, n-1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}