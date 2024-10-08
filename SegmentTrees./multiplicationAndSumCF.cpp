#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

class SegmentTree {
public:
    vector<int> tree;
    vector<bool> lazy;
    vector<int> lazyValues;
    int N;

    SegmentTree(int n) {
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, false);
        lazyValues.resize(4 * n, 1);
        N = n;
    }

    void propagate(int tid, int tl, int tr) {
        if (!lazy[tid]) return;

        if (tl < tr) {
            lazyValues[2 * tid + 1] *= lazyValues[tid];
            lazyValues[2 * tid + 1] %= mod;
            lazy[2 * tid + 1] = true;
            lazyValues[2 * tid + 2] *= lazyValues[tid];
            lazyValues[2 * tid + 2] %= mod;
            lazy[2 * tid + 2] = true;
        }

        tree[tid] *= lazyValues[tid];
        tree[tid] %= mod;
        lazyValues[tid] = 1;
        lazy[tid] = false;
    }

    void update(int idx, int val) {
        int l = idx, r = idx;
        function<void(int, int, int)> f = [&](int tid, int tl, int tr) {
            if (tl > r || tr < l) return;

            if (l <= tl && tr <= r) {
                tree[tid] = val;
                return;
            }

            int tm = (tl + tr) / 2;
            f(2 * tid + 1, tl, tm);
            f(2 * tid + 2, tm + 1, tr);

            tree[tid] = (tree[2 * tid + 1] + tree[2 * tid + 2]) % mod;
        };

        f(0, 0, N - 1);
    }

    void update(int l, int r, int x) {
        function<void(int, int, int)> f = [&](int tid, int tl, int tr) {
            propagate(tid, tl, tr);
            if (tl > r || tr < l) return;

            if (l <= tl && tr <= r) {
                lazy[tid] = true;
                lazyValues[tid] *= x;
                lazyValues[tid] %= mod;
                propagate(tid, tl, tr);
                return;
            }

            int tm = (tl + tr) / 2;
            f(2 * tid + 1, tl, tm);
            f(2 * tid + 2, tm + 1, tr);

            tree[tid] = (tree[2 * tid + 1] + tree[2 * tid + 2]) % mod;
        };
        f(0, 0, N - 1);
    }

    int query(int l, int r) {
        function<int(int, int, int)> f = [&](int tid, int tl, int tr) {
            propagate(tid, tl, tr);

            if (tl > r || tr < l) return 0ll;

            if (l <= tl && tr <= r) {
                return tree[tid];
            }

            int tm = (tl + tr) / 2;
            return (f(2 * tid + 1, tl, tm) + f(2 * tid + 2, tm + 1, tr)) % mod;
        };
        return f(0, 0, N - 1);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    SegmentTree st(n);

    for (int i = 0; i < n; i++) {
        st.update(i, 1);
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            st.update(l, r - 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r - 1) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
