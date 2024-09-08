#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int ways(vector<int> &A,int currSum,int x,int n,vector<int> &dp) {
    if(currSum>x) {
        return 0;
    }
    if(currSum==x) {
        return 1;
    }
    if(dp[currSum]!=-1) {
        return dp[currSum];
    }
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans = (ans%mod + ways(A,currSum+A[i],x,n,dp)%mod)%mod;
    }
    return dp[currSum]=ans;
}

// curSum: 0......x

// 1. reverse the direction

int waysIteration(vector<int> &A,int currSum,int x,int n,vector<int> &dp) {
    
    for(int curSum = x; currSum >= 0; currSum--)
    {
        if(currSum==x) {
            dp[currSum] = 1;
        }
        else
        {
            int ans = 0;
            for(int i=0;i<n;i++) {
                if(currSum + A[i] <= x) {
                    ans = (ans + (dp[currSum + A[i]])) % mod;
                }
            }
            dp[currSum]=ans;   
        }
    }
    return dp[0];
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
    cout << waysIteration(A,0,x,n,dp) << endl;
    return 0;
}