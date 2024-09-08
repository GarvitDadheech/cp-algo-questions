#include<bits/stdc++.h>
using namespace std;

int ways(string num,vector<int> &dp) {
    int currentNum = stoi(num);

   
    if (currentNum == 0) {
        return 1;
    }

    
    if (num.length() == 1) {
        return 1;
    }
    if(dp[currentNum]!=-1) {
        return dp[currentNum];
    }
    int ans = INT_MAX;
    for (int i = 0; i < num.length(); i++) {
        int digitToRemove = num[i] - '0';
        if(digitToRemove>0) {
        int newNum = currentNum - digitToRemove;
        ans = min(ans, 1+ways(to_string(newNum),dp));
        }
    }

    return dp[currentNum]=ans;
}

int main() {
    int num;
    cin >> num;
    vector<int> dp(num+1,-1);
    std::cout <<  ways(std::to_string(num),dp) << std::endl;
    return 0;
}