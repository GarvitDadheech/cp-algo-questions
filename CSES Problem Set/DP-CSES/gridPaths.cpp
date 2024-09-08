#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int paths(vector<vector<char>> &matrix,int i,int j,vector<vector<int>> &dp) {
    if(i==matrix.size()-1 && j==matrix[0].size()-1 && matrix[i][j]!='*') {
        return 1;
    }
    if(i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]=='*') {
        return 0;
    }
    if(dp[i][j]!=-1) {
        return dp[i][j];
    }
    dp[i][j] = (paths(matrix,i+1,j,dp)%mod+paths(matrix,i,j+1,dp)%mod)%mod;
    return dp[i][j];
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<char>> matrix(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = line[j];
        }
    }
    cout << paths(matrix,0,0,dp);
    return 0;
}