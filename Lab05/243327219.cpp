#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<vector<int>>& arr, int index) {
    int n = arr.size();
    vector<vector<int>> result(n);
    int count[4] = {0};

    for (int i = 0; i < n; i++){
        count[arr[i][index]]++;
    }

    for (int i = 1; i < 4; i++){
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        result[count[arr[i][index]] - 1] = arr[i];
        count[arr[i][index]]--;
    }

    for (int i = 0; i < n; i++){
        arr[i] = result[i];
    }
}  

void radixSort(vector<vector<int>>& arr) {
    for (int i = 9; i >= 0; i--){
        countingSort(arr, i);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arrs(n, vector<int>(10));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            cin >> arrs[i][j];
        }
    }

    radixSort(arrs);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arrs[i][j] << ";";
        }
        cout << endl;
    }

    return 0;
}


