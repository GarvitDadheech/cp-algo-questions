#include<bits/stdc++.h>
using namespace std;


int minCoins(vector<int> &A,int currSum,int x,int n,vector<int> &dp) {
    if(currSum>x) {
        return 1e9+7;
    }
    if(currSum==x) {
        return 0;
    }
    if(dp[currSum]!=-1) {
        return dp[currSum];
    }
    int ans = 1e9+7;
    for(int i=0;i<n;i++) {
        ans = min(ans,1+minCoins(A,currSum+A[i],x,n,dp));
    }
    return dp[currSum] = ans;
}

int main() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> A(n);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> dp(x+1,-1);
    int result = minCoins(A,0,x,n,dp);
    if(result==1e9+7) {
        cout << -1 << endl;
    }
    else {
        cout << result << endl;
    }
    return 0;
}