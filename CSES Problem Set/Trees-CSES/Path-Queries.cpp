#include<bits/stdc++.h>
using namespace std;
#define int long long
class SegmentTree{
    int n;
    int identity;
    vector<int> tree;
public:
    SegmentTree(int N,int identity) {
        this->n = N;
        this->identity = identity;
        tree.assign(4*n,identity);
    }

    void update(int idx,int x) {
        function<void(int,int,int)> help = [&](int tid,int tl,int tr) {
            if(tl==tr) {
                tree[tid] = x;
                return;
            }
            int tm = (tl+tr)/2;
            if(tl<=idx && idx<=tm) {
                help(2*tid+1,tl,tm);
            }
            else{
                help(2*tid+2,tm+1,tr);
            }
            tree[tid] = tree[2*tid+1] + tree[2*tid+2];
        }; 
        help(0,0,n-1); 
    }

    int query(int l,int r) {
        function<int(int,int,int)> help = [&](int tid,int tl,int tr) {
            if(r<tl || l>tr) {
                return identity;
            }
            else if(l<=tl && r>=tr) {
                return tree[tid];
            }
            int tm = (tl+tr)/2;
            return help(2*tid+1,tl,tm)+help(2*tid+2,tm+1,tr);
        };
        return help(0,0,n-1);
    }
};

signed main() {
    int n,q; cin >> n >> q;
    vector<int> val(n+1);
    for(int i=1;i<=n;i++) {
        cin >> val[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++) {
        int to,from;
        cin >> to >> from;
        adj[to].push_back(from);
        adj[from].push_back(to);
    }
    vector<int> tin(n+1);
    vector<int> tout(n+1);
    vector<int> tour(2*n);
    int timer = 0;
    function<void(int,int)> dfs = [&](int node,int parent) {
        tin[node] = timer;
        tour[timer++] = val[node]; 
        for(int nb : adj[node]) {
            if(nb!=parent) {
                dfs(nb,node);
            }
        }
        tout[node] = timer;
        tour[timer++] = val[node];
    };
    dfs(1,0);
    SegmentTree st(2*n,0);
    for(int i=1;i<=n;i++) {
        st.update(tin[i],val[i]);
        st.update(tout[i],-val[i]);
    }
    while(q--) {
        int type;
        cin >> type;
        if(type==1) {
            int s,x;
            cin >> s >> x;
            st.update(tin[s],x);
            st.update(tout[s],-x);
        }
        else {
            int s; cin >> s;
            cout << st.query(0,tin[s]) << endl;
        }
    }
    return 0;
}