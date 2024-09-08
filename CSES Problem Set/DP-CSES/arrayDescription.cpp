#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int n, m;
vector<int> A;
vector<vector<int>> dp;

int ways(int i, int prev) {
    if(i>=n) {
        return 1;
    }
    if(dp[i][prev]!=-1) {
        return dp[i][prev];
    }
    int ans = 0;
    if(A[i]==0) {
        for(int j=1;j<=m;j++) {
            if(i==0 || abs(prev-j)<=1) {
                ans = (ans%mod + ways(i+1,j)%mod)%mod;
            }
        }
    }
    else {
        if(i==0 || abs(prev-A[i])<=1) {
            ans = (ans%mod + ways(i+1,A[i])%mod)%mod;
        }
    }
    return dp[i][prev] = ans;
}
 
int main() {
    cin >> n >> m;
    A.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    dp.assign(n, vector<int>(m + 1, -1));
    cout << ways(0, 0) << endl;
    return 0;
}
