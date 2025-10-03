#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMaxCrossingSubarray(vector<int>& arr, int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    int rightSum = INT_MIN;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += arr[j];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}

int findMaximumSubarray(vector<int>& arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }
    int mid = (low + high) / 2;

    int leftSum = findMaximumSubarray(arr, low, mid);
    int rightSum = findMaximumSubarray(arr, mid + 1, high);
    int crossSum = findMaxCrossingSubarray(arr, low, mid, high);

    return max({leftSum, rightSum, crossSum});
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = findMaximumSubarray(arr, 0, n - 1);
    cout << result;
    return 0;
}
