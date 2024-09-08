#include <bits/stdc++.h>
using namespace std;

vector<long long> preXor;

void pre(vector<long long> A, long long n) {
    preXor[0] = A[0];
    for (long long i = 1; i < n; i++) {
        preXor[i] = preXor[i - 1]^A[i];
    }
}

int main() {
    long long n, q;
    cin >> n;
    vector<long long> A(n);
    cin >> q;
    preXor.resize(n);
    for (long long i = 0; i < n; i++) {
        cin >> A[i];
    }
    pre(A, n);
    while (q > 0) {
        long long left, right;
        cin >> left >> right;
        if (left == 1) {
            cout << preXor[right - 1] << endl;
        } 
        else {
            cout << (preXor[right - 1]^preXor[left - 2]) << endl;
        }
        q--;
    }
    return 0;
}
