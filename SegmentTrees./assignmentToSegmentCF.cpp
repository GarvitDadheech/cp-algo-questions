#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
    int N;
    vector<int> tree;
    vector<bool> lazy;
    SegmentTree(int n) {
        this->N = n;
        tree.resize(4*n);
        lazy.resize(4*n);
    }

    void propagate(int tidx,int tl,int tr) {
        if(!lazy[tidx] or tl==tr) {
            return;
        }

        tree[tidx*2+1] = tree[tidx];
        lazy[tidx*2+1] = true;

        tree[tidx*2+2] = tree[tidx];
        lazy[tidx*2+2] = true;

        lazy[tidx] = false;
        tree[tidx] = 0;
    }

    void update(int l,int r,int v) {
        function<void(int,int,int)> f = [&](int tidx,int tl,int tr) {
            propagate(tidx,tl,tr);
            if(tl>r || tr<l) {
                return;
            }
            if(l<=tl && tr<=r) {
                tree[tidx] = v;
                lazy[tidx] = true;
                return;
            }
            int tm = (tl+tr)/2;
            f(2*tidx+1,tl,tm);
            f(2*tidx+2,tm+1,tr);
        };
        f(0,0,N-1); 
    }

    int query(int qidx) {
        function<int(int,int,int)> f = [&](int tidx,int tl,int tr) {
            propagate(tidx,tl,tr);
            if(tl==tr) {
                return tree[tidx];
            }
            int tm = (tl+tr)/2;
            int ans = 0;
            if(qidx<=tm) {
                ans = f(2*tidx+1,tl,tm);
            }
            else{
                ans = f(2*tidx+2,tm+1,tr);
            }
            return ans;
        };
        return f(0,0,N-1);
    }

};

int main() {
    int n, q; cin >> n >> q;
    SegmentTree st(n);
    while(q--)
    {
        int t; cin >> t;
        if(t == 1)
        {
            int l, r, x; cin >> l >> r >> x;
            st.update(l, r - 1, x);
        }
        else
        {
            int idx; cin >> idx;
            cout << st.query(idx) << endl;
        }
    }
    return 0;
}