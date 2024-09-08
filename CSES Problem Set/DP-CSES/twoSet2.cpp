#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
vector<vector<int>> dp;
int count(int indx,int n,int currSum,int part) {
    if(currSum==part) {
        return 1;
    }
    if(indx>n || currSum > part) {
        return 0;
    }
    if(dp[indx][currSum]!=-1) {
        return dp[indx][currSum];
    }
    
    int ans1 = count(indx+1,n,currSum+indx,part)%mod;
    int ans2 = count(indx+1,n,currSum,part)%mod;
    return dp[indx][currSum] = ans1+ans2;
}


int main() {
    int n;
    cin >> n;
    int part = (n*(n+1))/4;
    int total = (n*(n+1))/2;
    if((total)%2!=0) {
        cout << 0 << endl;
        return 0;
    }
    dp.resize(n + 1, vector<int>(part*2 + 1, -1));
    cout << count(1,n,0,part)/2 << endl;
    return 0;
}