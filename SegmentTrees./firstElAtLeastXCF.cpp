#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
public:
    Node(int val=0) {
        this->val = val;
    }
};

Node merge(Node a,Node b){
    return Node(max(a.val,b.val));
}


template<typename T>
class SegmentTree{
    int N;
    vector<T> tree;
    T identity;

public:
    SegmentTree(int n,T identity) {
        this->N = n;
        tree.resize(4*N,identity);
        this->identity = identity;
    }

    void update(int qIndx,T x) {
        helpUpdate(0,0,N-1,qIndx,x);
    }

    void helpUpdate(int tIndx,int tL,int tR,int qIndx,T x) {
        if(tL==tR) {
            tree[tIndx] = x;
            return;
        }
        int tM = (tL+tR)/2;
        if(tL<=qIndx && qIndx<=tM) {
            helpUpdate(2*tIndx+1,tL,tM,qIndx,x);
        }
        else{
            helpUpdate(2*tIndx+2,tM+1,tR,qIndx,x);
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
        //partial overlap
        if(l<=tL && tR<=r) {
            return tree[tIndx];
        }
        int tM = (tL+tR)/2;
        return merge(helpQuery(2*tIndx+1,tL,tM,l,r),helpQuery(2*tIndx+2,tM+1,tR,l,r));
    }
    
};

int main() {

    int n,q;
    cin >> n >> q;
    SegmentTree<Node> st(n+1,Node(0));
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        st.update(i,Node(x));
    }

    while(q>0) {
        int t;
        cin >> t;
        if(t==1) {
            int idx,val;
            cin >> idx >> val;
            st.update(idx,val);
        }
        else{
            int k;
            cin >> k;
            int s = 0;
            int e = n-1;
            int ans = -1;
            while(s<=e) {
                int mid = (s+e)/2;
                if(st.query(0,mid).val>=k){
                    ans = mid;
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
            cout << ans << endl;
        }
        q--;
    }



    return 0;
}