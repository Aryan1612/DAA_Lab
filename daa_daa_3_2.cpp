#include <bits/stdc++.h>

using namespace std;

int counting(vector<int> &arr, int pages){
    int students{1};
    int student_pages{0};
    for (int i = 0; i < (int) arr.size(); i++){
        if (student_pages+arr[i] <= pages){
            student_pages+=arr[i];
        }
        else{
            student_pages = arr[i];
            students++;
        }
    }
    return students;
}
int search(vector<int> &arr, int low, int high, int students){
    while(low <= high){
        int mid = (low+high)/2;
        if (counting(arr, mid) <= students){
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return low;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (m > n){
        cout << "not possible\n";
        return 0;
    }
    else{
        sort(arr.begin(), arr.end());
        int sum{0};
        int max_e{INT_MIN};
        for (int i = 0; i < n; i++){
            sum += arr[i];
            max_e = max(arr[i], max_e);
        }
        cout << search(arr, max_e, sum, m);
    }

}