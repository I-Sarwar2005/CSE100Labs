#include <iostream>
#include <vector>

using namespace std;

    vector<int> merge(vector <int>& L, vector<int>& R){
        vector<int> merged(L.size() + R.size());
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < L.size() && j < R.size()){
            if (L[i] <= R[j]){
                merged[k] = L[i];
                i++;
                k++;
            }else {
                merged[k] = R[j];
                j++;
                k++;
            }
        }
        while (i < L.size()){
            merged[k] = L[i];
            i++;
            k++;
        }

        while (j < R.size()){
            merged[k] = R[j];
                j++;
                k++;
            } 
        return merged;
    }

    vector<int> mergeSort(vector<int>& arr){
        int n = arr.size();
        if (n<= 1){
            return arr;
        }
        vector <int> L(n/2);
        vector <int> R(n - n/2);
        for (int i = 0; i< n/2; i++){
            L[i] = arr[i];
        }
        for (int i = 0; i < n - n/2; i++){
            R[i] = arr[n/2 + i];
        }

        L = mergeSort(L);
        R = mergeSort(R);

        return merge(L,R);
    }

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> sortedArr = mergeSort(arr);
    for (int j = 0; j < n; j++){
        cout << sortedArr[j] << ";";
    }

}