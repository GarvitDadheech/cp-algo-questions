#include<bits/stdc++.h>
using namespace std;

int dp[110][100010],pre[100010];
const int mod = 1e9+7;
int help(vector<int> &A,int indx,int N,int K) {
    if(indx>=N){
        if(K==0){
        return 1;
        }
        return 0;
    }
    
    int ans = 0;
    int max_cndies = min(A[indx],K);
    for(int i=0;i<=max_cndies;i++) {
        ans = ans + help(A,indx+1,N,K-i);
    }
    return ans;
}


int loop(vector<int> &A,int K) {
    for(int indx=A.size();indx>=0;indx--) {
        for(int k=0;k<=K;k++) {
            int &ans = dp[(indx)%2][k];
            if(indx>=A.size()) {
                ans = k == 0;
            }
            else{
                int max_cndies = min(A[indx],k);
                int start_idx = k-max_cndies;
                int end_idx = k;
                ans = pre[end_idx] - pre[start_idx] + dp[(indx+1)%2][start_idx];
                ans%= mod;
                ans += mod;
                ans %= mod;
            }
        }
        pre[0] = dp[indx%2][0];
        for(int k=1;k<=K;k++) {
            pre[k] = (pre[k-1]+dp[(indx)%2][k]) % mod;
        }
    }
    return dp[0][K];
}

int main() {
    int N, K;
    cin >> N;
    cin >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int result = loop(A,K);
    cout << result << endl;

    return 0;

}