#include<bits/stdc++.h>
using namespace std;
#define int long long
class Node{
public:
    int mx_sub=0;
    int mx_suff=0;
    int mx_pre=0;
    int total_sum=0;
};


Node merge(Node a, Node b) {
    Node ans;
    ans.total_sum = a.total_sum + b.total_sum;
    ans.mx_sub = max({a.mx_sub, b.mx_sub, a.mx_suff + b.mx_pre});
    ans.mx_pre = max(a.mx_pre, a.total_sum + b.mx_pre);
    ans.mx_suff = max(b.mx_suff, b.total_sum + a.mx_suff);
    return ans;
}



template<typename T>
class SegmentTree {
public:
    int N;
    T identity;
    vector<T> tree;

 
    SegmentTree(int n,T identity) {
        this->N = n;
        this->identity = identity;
        tree.resize(4*N);
    }

    void updateTree(int qIndx,T x) {
        helpUpdateTree(0,0,N-1,qIndx,x);
    }


    void helpUpdateTree(int tIndx,int tL,int tR,int qIndx,T x) {
        if(tL==tR) {
            tree[tIndx] = x;
            return;
        }
        int tM = (tL+tR)/2;
        if(qIndx>=tL && qIndx<=tM) {
            helpUpdateTree(2*tIndx+1,tL,tM,qIndx,x);
        }
        else{
            helpUpdateTree(2*tIndx+2,tM+1,tR,qIndx,x);
        }
        tree[tIndx] = merge(tree[2*tIndx+1],tree[2*tIndx+2]);
    }

    T query(int l,int r) {
        return helpQuery(0,0,N-1,l,r);
    }

    T helpQuery(int tIndx,int tL,int tR,int l,int r) {
        //no overlap
        if(tL>r || tR<l) {
            return identity;
        }
        //complete overlap
        if(l<=tL && tR<=r) {
            return tree[tIndx];
        }
        int tM = (tL+tR)/2;
        return merge(helpQuery(2*tIndx+1,tL,tM,l,r),helpQuery(2*tIndx+2,tM+1,tR,l,r));
    }
};


signed main() {
    int n,q;
    cin >> n >> q;
    SegmentTree<Node> st(n+1,Node());
    for(int i=1;i<=n;i++) {
        int x;
        cin >> x;
        st.updateTree(i,Node({x,x,x,x}));
    }
    
    while(q>0) {
        int indx,val;
        cin >> indx >> val;
        st.updateTree(indx,Node({val,val,val,val}));
        cout << max(0ll,st.query(0,n).mx_sub) << endl;
        q--;
    }
    
    return 0;
}