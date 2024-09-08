#include <bits/stdc++.h>
using namespace std;

vector<long long> preSum;

void pre(vector<long long> A, long long n) {
    preSum[0] = A[0];
    for (long long i = 1; i < n; i++) {
        preSum[i] = preSum[i - 1] + A[i];
    }
}

int main() {
    long long n, q;
    cin >> n;
    vector<long long> A(n);
    cin >> q;
    preSum.resize(n);
    for (long long i = 0; i < n; i++) {
        cin >> A[i];
    }
    pre(A, n);
    while (q > 0) {
        long long left, right;
        cin >> left >> right;
        if (left == 1) {
            cout << preSum[right - 1] << endl;
        } 
        else {
            cout << preSum[right - 1] - preSum[left - 2] << endl;
        }
        q--;
    }
    return 0;
}
