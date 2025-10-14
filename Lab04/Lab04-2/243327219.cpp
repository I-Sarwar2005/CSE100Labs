#include <iostream>
#include <vector>
#include <cstdlib> 

using namespace std;

int partition(vector<int> &arr, int p, int r) {
    int pivot = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int randPartition(vector<int> &arr, int p, int r) {
    int randPivot = p + rand() % (r - p + 1);
    swap(arr[randPivot], arr[r]);
    return partition(arr, p, r);
}

void randQuickSort(vector<int> &arr, int p, int r) {
    if (p < r) {
        int q = randPartition(arr, p, r);
        randQuickSort(arr, p, q - 1);
        randQuickSort(arr, q + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    randQuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << ";";
    }

    return 0;
}
