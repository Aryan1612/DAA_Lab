#include <bits/stdc++.h>

using namespace std;

int findMedian(vector<int>& arr, int start, int size) {
    vector<int> temp(arr.begin() + start, arr.begin() + start + size);
    sort(temp.begin(), temp.end());
    return temp[size / 2];
}

int partition(vector<int>& arr, int left, int right, int pivot) {
    int pivotIndex = left;
    for (int i = left; i <= right; i++) {
        if (arr[i] == pivot) {
            pivotIndex = i;
            break;
        }
    }
    swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

int select(vector<int>& arr, int left, int right, int i) {
    if (left == right) return arr[left];

    int n = right - left + 1;
    int numGroups = (n + 4) / 5; 
    vector<int> medians(numGroups);

    for (int j = 0; j < numGroups; ++j) {
        int groupStart = left + j * 5;
        int groupSize = min(5, right - groupStart + 1);
        medians[j] = findMedian(arr, groupStart, groupSize);
    }

    int medianOfMedians;
    if (numGroups == 1) {
        medianOfMedians = medians[0];
    } else {
        medianOfMedians = select(medians, 0, numGroups - 1, numGroups / 2);
    }

    int pivotIndex = partition(arr, left, right, medianOfMedians);

    int k = pivotIndex - left;

    if (i == k) return arr[pivotIndex];
    else if (i < k) return select(arr, left, pivotIndex - 1, i);
    else return select(arr, pivotIndex + 1, right, i - k - 1);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = select(arr, 0, n - 1, k - 1);
    cout << result << endl;
    return 0;
}