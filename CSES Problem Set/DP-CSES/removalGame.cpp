#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxScore(vector<int>& A, int first, int last, bool chancePlayer1, vector<vector<long long>>& dp) {
    if (first > last) {
        return 0;
    }
    
    if (dp[first][last] != -1) {
        return dp[first][last];
    }

    if (chancePlayer1) {
        long long pickFirst = A[first] + maxScore(A, first + 1, last, false, dp);
        long long pickLast = A[last] + maxScore(A, first, last - 1, false, dp);
        dp[first][last] = max(pickFirst, pickLast);
    } else {
        long long pickFirst = maxScore(A, first + 1, last, true, dp);
        long long pickLast = maxScore(A, first, last - 1, true, dp);
        dp[first][last] = min(pickFirst, pickLast);
    }
    
    return dp[first][last];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    vector<vector<long long>> dp(n, vector<long long>(n, -1));
    
    cout << maxScore(A, 0, n - 1, true, dp) << endl;
    
    return 0;
}
