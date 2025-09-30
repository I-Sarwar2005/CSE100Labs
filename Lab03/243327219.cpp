#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Helper to find max crossing subarray
int findMaxCrossingSubarray(const vector<int>& A, int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += A[j];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

// Divide-and-conquer max subarray
int findMaximumSubarray(const vector<int>& A, int low, int high) {
    if (low == high) {
        return A[low]; // base case: single element
    }

    int mid = (low + high) / 2;

    int left_sum = findMaximumSubarray(A, low, mid);
    int right_sum = findMaximumSubarray(A, mid + 1, high);
    int cross_sum = findMaxCrossingSubarray(A, low, mid, high);

    return max({left_sum, right_sum, cross_sum});
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int result = findMaximumSubarray(A, 0, n - 1);
    cout << result;
    return 0;
}
