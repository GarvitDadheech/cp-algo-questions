#include<bits/stdc++.h>
using namespace std;

int dp[18][18*9][9];

int f(int indx,int currSum,int currGcd,int n,int reqSum,int reqGcd) {

    if(indx==n) {
        if(currSum==reqSum and currGcd==reqGcd) {
            return 1;
        }
        else {
            return 0;
        }
    }

    if(dp[indx][currSum][currGcd]!=-1) {
        return dp[indx][currSum][currGcd];
    }
    int ans = 0;
    for(int i=0;i<=9;i++) {
        ans = ans + f(indx+1,currSum+i,gcd(currGcd,i),n,reqSum,reqGcd);
    }
    return dp[indx][currSum][currGcd] = ans;
}

int main() {
    int reqGcd;
    int reqSum;
    int n;
    cin >> n;
    cin >> reqSum;
    cin >> reqGcd;
    cout << f(0,0,0,n,reqSum,reqGcd) <<endl;
    return 0;
}