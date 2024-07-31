#include <bits/stdc++.h>

using namespace std;

int cnt{0};
void merge(vector<int> &arr, int low, int mid, int high){
    int i = low;
    int j = mid+1;
    vector<int> ans;
    while(i <= mid && j <= high){
        if (arr[i] < arr[j]){
            ans.push_back(arr[i]);
            i++;
        }
        else{
            ans.push_back(arr[j]);
            cnt+=(mid - i + 1);
            j++;
        }
    }
    while (i <= mid){
        ans.push_back(arr[i]);
            i++;
    }
    while (j <= high){
        ans.push_back(arr[j]);
        j++;
    }
    int m{0};
    for (int i = low; i <= high; i++){
        arr[i] = ans[m++];
    }
}

void merge_sort(vector<int> &arr, int low, int high){
    if (low >= high)
        return;
    int mid = (low + high)*0.5;

    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    merge_sort(arr, 0, arr.size()-1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n" << cnt;
}