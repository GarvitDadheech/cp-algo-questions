#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1e9+7;
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
    cout << ways(A,0,x,n,dp) << endl;
    return 0;
}
