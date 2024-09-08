#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegmentTree {
public:
    ll N;
    vector<ll> tree;
    vector<bool> lazy;
    vector<ll> lazyValue;

    SegmentTree(ll n) {
        this->N = n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
        lazyValue.resize(4 * n);
    }

    void propagate(ll tid, ll tl, ll tr) {
        if (!lazy[tid]) {
            return;
        }
        if (tl < tr) {
            lazy[2 * tid + 1] = true;
            lazyValue[2 * tid + 1] |= lazyValue[tid];

            lazy[2 * tid + 2] = true;
            lazyValue[2 * tid + 2] |= lazyValue[tid];
        }
        lazy[tid] = false;
        tree[tid] |= lazyValue[tid];
        lazyValue[tid] = 0;
    }

    void update(ll l, ll r, ll x) {
        function<void(ll, ll, ll)> f = [&](ll tid, ll tl, ll tr) {
            propagate(tid, tl, tr);
            // no overlap
            if (r < tl || l > tr) {
                return;
            }
            // complete overlap
            if (l <= tl && r >= tr) {
                lazy[tid] = true;
                lazyValue[tid] |= x;
                propagate(tid, tl, tr);
                return;
            }
            ll tm = (tl + tr) / 2;
            f(2 * tid + 1, tl, tm);
            f(2 * tid + 2, tm + 1, tr);
            tree[tid] = (tree[2 * tid + 1]& tree[2 * tid + 2]);
        };
        f(0, 0, N - 1);
    }

    ll query(ll l, ll r) {
        function<ll(ll, ll, ll)> f = [&](ll tid, ll tl, ll tr) {
            propagate(tid, tl, tr);

            // no overlap
            if (tl > r || tr < l) return LLONG_MAX;

            // complete overlap
            if (l <= tl && tr <= r) {
                return tree[tid];
            }

            ll tm = (tl + tr) / 2;

            return (f(2 * tid + 1, tl, tm)& f(2 * tid + 2, tm + 1, tr));
        };
        return f(0, 0, N - 1);
    }
};

int main() {
    ll n, q;
    cin >> n >> q;
    SegmentTree st(n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll l, r, x;
            cin >> l >> r >> x;
            st.update(l, r - 1, x);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << st.query(l, r - 1) << endl;
        }
    }
    return 0;
}
