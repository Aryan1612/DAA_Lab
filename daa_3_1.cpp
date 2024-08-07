#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m1, n1, m2, n2;
    cin >> m1 >> n1 >> m2 >> n2;
    vector<vector<int>> a(m1, vector<int> (n1));
    vector<vector<int>> b(m2, vector<int> (n2));

    for (int i = 0; i < m1; i++){
        for (int j = 0; j < n1; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < m2; i++){
        for (int j = 0; j < n2; j++)
            cin >> b[i][j];
    }
    vector<vector<int>> ans(m1, vector<int> (n2));
    if (n1 == m2){
        for (int i = 0; i < m1; i++){
            for (int j = 0; j < n2; j++){
                for (int k = 0; k < n1; k++){
                    ans[i][j] += a[i][k]*b[k][j];
                }
            }
        }
        for (int i = 0; i < m1; i++){
            for (int j = 0; j < n2; j++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
    else
        cout << "multiplication of given matrices not possible.\n";

}