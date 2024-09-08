#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int minOperations(string A,string B,int i,int j) {
    if (i == -1 && j == -1) {
        return 0;
    }
    if (i == -1) {
        return j + 1;
    }
    if (j == -1) {
        return i + 1;
    }
    if(dp[i][j]!=-1) {
        return dp[i][j];
    }
    if(A[i]==B[j]) {
        dp[i][j] = minOperations(A,B,i-1,j-1);
    }
    else{
        int ans1 = 1 + minOperations(A, B, i - 1, j - 1); // Replace
        int ans2 = 1 + minOperations(A, B, i - 1, j);     // Delete
        int ans3 = 1 + minOperations(A, B, i, j - 1);     // Insert
        dp[i][j] = min(ans1, min(ans2, ans3));
    }
    return dp[i][j];
}
int main() {
    string A, B;
    cin >> A;
    cin >> B;
    int lenA = A.length();
    int lenB = B.length();
    dp.assign(lenA, vector<int>(lenB, -1));
    cout << minOperations(A, B, lenA-1, lenB-1) << endl;
    
    return 0;
}