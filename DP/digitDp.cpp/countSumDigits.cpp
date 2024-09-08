#include <iostream>
#include <vector>
using namespace std;

//Find count of all numbers less than 10^18 whose sum of digits is 10
int dp[19][18*9+1];
int count(int pos,int n,int sum) {
    if(pos==n) {
        if(sum==10) {
            return 1;
        }
        return 0;
    }
    if(dp[pos][sum]!=-1) {
        return dp[pos][sum];
    }
    int ans = 0;
    for(int i=0;i<=9;i++) {
        ans += count(pos+1,n,sum+i);
    }
    return dp[pos][sum] = ans;
}


int main() {
    for (int i = 0; i < 19; ++i) {
        for (int j = 0; j < 10*18+1; ++j) {
            dp[i][j] = -1;
        }
    }
    cout << count(0,18,0) << endl;
    return 0;

}