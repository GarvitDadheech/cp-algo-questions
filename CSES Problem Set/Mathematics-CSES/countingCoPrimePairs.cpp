#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
long long freq[N+1], cnt[N+1];

int main() {
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    
    // Calculating cnt array
    for(int i=1; i<=N; i++) {
        for(int j=i; j<=N; j=j+i) {
            cnt[i] += freq[j];
        }
        cnt[i] = (1LL * cnt[i] * (cnt[i]-1)) / 2;
    }
    
    // Adjusting cnt array using subtraction
    for(int i=N; i>=1; i--) {
        for(int j=2*i; j<=N; j=j+i) {
            cnt[i] -= cnt[j];
        }
    }
    
    // Output the result
    cout << cnt[1] << endl;
    
    return 0;
}


const int = 1e6+
