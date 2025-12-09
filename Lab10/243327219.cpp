#include <iostream>
#include <vector>
#include <string>
using namespace std;

string printOP(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        return "A" + to_string(i);
    }
    return "(" + printOP(s, i, s[i][j]) + printOP(s, s[i][j] + 1, j) + ")";
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            m[i][j] = 1000000000; // Infinity
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[0][n-1] << endl;
    cout << printOP(s, 0, n-1) << endl;

    return 0;
}
