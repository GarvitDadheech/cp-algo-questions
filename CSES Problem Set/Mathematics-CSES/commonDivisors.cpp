#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> cnt(1e6+7,0);
    vector<int> A(n);
    vector<int> freq(1e6+7,0);
    int ans = 1;
    for(int i=0;i<n;i++) {
        cin >> A[i];
        freq[A[i]]++;
    }
    for(int i=1;i<1e6+7;i++) {
        for(int j=i;j<1e6+7;j=j+i) {
            cnt[i] += freq[j];
        }
    }
    for(int i=2;i<1e6+7;i++) {
        if (cnt[i] >= 2) {
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}