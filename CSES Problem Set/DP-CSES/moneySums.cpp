#include<bits/stdc++.h>
using namespace std;
set<int> ans;
vector<vector<int>> dp;
void moneySum(int indx,vector<int> &A,int currSum,int n) {
    if(indx>=n) {
        ans.insert(currSum);
        return;
    }
    if (dp[indx][currSum] != -1) {
        return;
    }
    moneySum(indx+1,A,currSum+A[indx],n);
    moneySum(indx+1,A,currSum,n);
    dp[indx][currSum] = 1; 
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    int sumA = 0;

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        sumA += A[i];
    }
    dp.assign(n, vector<int>(sumA + 1, -1));
    moneySum(0, A, 0, n);
    if (!ans.empty()) { 
        auto it = ans.begin();
        ans.erase(it);
    }
    cout << ans.size() << endl;
    for (int sum : ans) {
        cout << sum << " ";
    }
    return 0;
}