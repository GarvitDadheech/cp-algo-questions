#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int ways(vector<int> &A,int x,int currSum,int indx,vector<int> &dp,int n) {
    if(currSum>x || indx>=n) {
        return 0;
    }
    if(currSum==x) {
        return 1;
    }
    if(dp[currSum]!=-1) {
        return dp[currSum];
    }

    return dp[currSum] = ways(A,x,currSum+A[indx],indx,dp,n)+ways(A,x,currSum,indx+1,dp,n);
}
 
int main() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> A(n);
    vector<int> dp(x+1,-1);
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << (int)ways(A,x,0,0,dp,n) << endl;
    return 0;
}