#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
string ans;
int lcsLength(string &A,string &B,int i,int j) {
    if(i>=static_cast<int>(A.length()) || j>=static_cast<int>(B.length())) {
        return 0;
    }
    if(dp[i][j]!=-1) {
        return dp[i][j];
    }
    int ans1 = 0;
    if(A[i]==B[j]) {
        ans1 = 1 + lcsLength(A,B,i+1,j+1);
    }
    int ans2 = lcsLength(A,B,i+1,j);
    int ans3 = lcsLength(A,B,i,j+1);
    return dp[i][j] = max({ans1,ans2,ans3});
}

void recover(string A,string B,int i,int j) {
    if(i>=static_cast<int>(A.length()) || j>=static_cast<int>(B.length())){
        return;
    }
    int ans1 = 0;
    int ans2 = lcsLength(A,B,i+1,j);
    int ans3 = lcsLength(A,B,i,j+1);
    if(A[i]==B[j]) {
        ans1 = 1 + lcsLength(A,B,i+1,j+1);
    }
    int mx = max({ans1,ans2,ans3});
    if(mx==ans2) {
        recover(A,B,i+1,j);
    }
    else if(mx==ans3) {
        recover(A,B,i,j+1);
    }
    else{
        ans = ans + A[i];
        recover(A,B,i+1,j+1);
    }
}

int main() {
    string A, B;
    cin >> A;
    cin >> B;
    dp.resize(A.length(), vector<int>(B.length(), -1));
    int mxlenght = lcsLength(A, B, 0, 0);
    recover(A,B,0,0);
    cout << ans << endl;
    return 0;
}