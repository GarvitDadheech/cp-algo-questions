#include<bits/stdc++.h>
using namespace std;

class SegmentTree {
    int N;
    long long identity;
    vector<long long> tree;
public:
    SegmentTree(int n, long long identity) {
        this->N = n;
        this->identity = identity;
        tree.resize(4 * n, identity); 
    }

    void update(int idx, long long x) {
        function<void(int, int, int)> help = [&](int tid, int tl, int tr) {
            if (tl == tr) {
                tree[tid] = x;
                return;
            }
            int tm = (tl + tr) / 2;
            if (tl <= idx && idx <= tm) {
                help(2 * tid + 1, tl, tm);
            } else {
                help(2 * tid + 2, tm + 1, tr);
            }
            tree[tid] = tree[2 * tid + 1] + tree[2 * tid + 2];
        };
        help(0, 0, N - 1);
    }

    long long query(int l, int r) {
        function<long long(int, int, int)> help = [&](int tid, int tl, int tr) {
            if (l > tr || r < tl) {
                return identity;
            }
            if (l <= tl && r >= tr) {
                return tree[tid];
            }
            int tm = (tl + tr) / 2;
            return help(2 * tid + 1, tl, tm) + help(2 * tid + 2, tm + 1, tr);
        };
        return help(0, 0, N - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n + 1);
    vector<long long> val(n + 1); 

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int to, from;
        cin >> to >> from;
        adj[to].push_back(from);
        adj[from].push_back(to);
    }

    int timer = 0;
    vector<long long> tour(2 * n);  
    vector<int> tin(n + 1);
    vector<int> tout(n + 1);

    function<void(int, int)> dfs = [&](int node, int parent) {
        tin[node] = timer;
        tour[timer++] = val[node];
        for (int nb : adj[node]) {
            if (nb != parent) {
                dfs(nb, node);
            }
        }
        tout[node] = timer;
        tour[timer++] = val[node];
    };

    dfs(1, 0);

    SegmentTree st(2 * n, 0LL);

    for (int i = 0; i < 2 * n; i++) {
        st.update(i, tour[i]);
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s;
            long long x;
            cin >> s >> x;
            st.update(tin[s], x);
            st.update(tout[s], x);
        } 
        else {
            int x;
            cin >> x;
            cout << st.query(tin[x], tout[x]) / 2 << endl;  
        }
    }
    return 0;
}
