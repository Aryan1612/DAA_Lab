#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(n);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int l1{0}, l2{0}, prev{-1};
    while(l1 < m && l2 < n){
        if (a[l1] < b[l2]){
            if (prev != a[l1] || prev == -1){
                cout << a[l1] << " ";
                prev = a[l1];
                l1++;
            }
            else
                l1++;
        }
        else if (a[l1] >= b[l2]){
            if (prev != b[l2] || prev == -1){
                cout << b[l2] << " ";
                prev = b[l2];
                l2++;
            }
            else
                l2++;
        }
    }
    l1 =0, l2 = 0, prev = -1;
    cout << "\n";
    while(l1 < m && l2 < n){
        if (a[l1] < b[l2]){
            l1++;
        }
        else if (a[l1] > b[l2]){
            l2++;
        }
        else{
            if (prev != b[l2] || prev == -1){
                prev = b[l2];
                cout << b[l2] << " ";
            }
            l1++, l2++;
        }
        
    }
    
}
