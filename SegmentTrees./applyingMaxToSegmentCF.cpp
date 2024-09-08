#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
public:
    vector<int> tree;
    int N;
    SegmentTree(int n) {
        this->N = n;
        tree.resize(4*n,0);
    }

    void update(int l,int r,int v) {
        function<void(int,int,int)> f = [&](int tidx,int tl,int tr) {
            //no overlap
            if(tl>r || tr<l) {
                return;
            }

            //complete overlap
            if(tl>=l && tr<=r) {
                tree[tidx] = max(tree[tidx],v); 
                return;
            }

            int tm = (tl+tr)/2;
            f(2*tidx+1, tl, tm);
            f(2*tidx+2, tm+1, tr);
        };
        f(0,0,N-1);
    }

    int query(int qidx) {
        function<int(int,int,int)> f = [&](int tidx,int tl,int tr) {
            if(tl==tr) {
                return tree[tidx];
            }
            int tm = (tl+tr)/2;
            int ans = tree[tidx];
            if(qidx<=tm) {
                ans = max(ans,f(2*tidx+1,tl,tm));
            }
            else{
                ans = max(ans,f(2*tidx+2,tm+1,tr));
            }
            return ans;
        };
        return f(0,0,N-1);
    }

};

int main() {
    int n,q;
    cin>>n>>q;
    SegmentTree st(n);
    while(q--) {
         int t; cin >> t;
        if(t == 1) {
            int l, r, x; cin >> l >> r >> x;
            st.update(l, r - 1, x);
        }
        else {
            int idx; cin >> idx;
            cout << st.query(idx) << endl;
        }
    }
    return 0;
}