#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0 ; i < n; i++)
        cin >> arr[i];
    int max1{INT_MIN}, max2{INT_MIN}, max3{INT_MIN},
    min1{INT_MAX}, min2{INT_MAX};
    
    for (int num:arr){
        if (num > max1){
            max3 = max2;
            max2 = max1;
            max1 = num;
        }
        else if (num > max2){
            max3 = max2;
            max2 = num;
        }
        else if (num > max3){
            max3 = num;
        }
        
        if (num < min1){
            min2 = min1;
            min1 = num;
        }
        else if (num < min2){
            min2 = num;
        }
    }
    cout << max(max1*max2*max3 , max1*min1*min2);
}