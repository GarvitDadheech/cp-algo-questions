#include <iostream>
#include <vector>
using namespace std;
vector <int> dp;
int mod = 1000000007;
int ways(int currSum,int target) {
    if(currSum==target) {
        return 1;
    }
    if(currSum>target) {
        return 0;
    }
    if(dp[currSum]!=-1) {
        return dp[currSum];
    }
    int count = 0;
    for(int i=1;i<=6;i++) {
        count= (count%mod + ways(currSum+i,target)%mod)%mod;
    }
    dp[currSum] = count;
    return dp[currSum];
}


int main() {
    int n;
    cin >> n;
    dp = vector<int>(n+1,-1);
    cout << ways(0, n) << endl;
    return 0;
}