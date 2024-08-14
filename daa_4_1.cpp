#include <bits/stdc++.h>

using namespace std;

int rand_select(vector<int> &arr, int p, int q,int i);
int parti(vector<int> &arr, int low, int high);

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << rand_select(arr, 0, n-1, n-k+1);
                                                                                                                                                                                                             
}
int rand_select(vector<int> &arr, int p, int q,int i){
    if (p == q)
        return arr[p];
    int r = parti(arr, p, q);
    int k = r-p+1;
    if (i == k)
        return arr[r];
    if (i < k)
        return rand_select(arr, p, r-1, i);
    else
        return rand_select(arr, r+1, q, i-k);
}

int parti(vector<int> &arr, int low, int high){
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