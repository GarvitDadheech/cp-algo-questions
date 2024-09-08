#include <bits/stdc++.h>
using namespace std;

void calculatePrefixSum(const vector<vector<char>>& A, vector<vector<int>>& pre, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i][j] = (A[i][j] == '*') ? 1 : 0;
            if (i > 0) pre[i][j] += pre[i-1][j];
            if (j > 0) pre[i][j] += pre[i][j-1];
            if (i > 0 && j > 0) pre[i][j] -= pre[i-1][j-1];
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<char>> A(n, vector<char>(n));
    vector<vector<int>> pre(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    calculatePrefixSum(A, pre, n, n);

    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--; x1--; y2--; x2--;
        int result = pre[y2][x2];
        if (y1 > 0) result -= pre[y1-1][x2];
        if (x1 > 0) result -= pre[y2][x1-1];
        if (y1 > 0 && x1 > 0) result += pre[y1-1][x1-1];

        cout << result << endl;
    }

    return 0;
}
