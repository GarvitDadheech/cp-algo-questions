#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

class Node{
public:
    int val;
public:
    Node(int val=0){
        this->val = val;
    }
};

Node merge(Node a,Node b) {
    return Node(max(a.val,b.val));
}

template<typename T>
class SegmentTree{
    int N;
    T identity;
    vector<T> tree;
public:
    SegmentTree(int n, T identity) {
        this->identity = identity;
        this->N = n;
        tree.resize(4*n,identity);
    }

    void update(int qIndx,T x){
        helpUpdate(0,0,N-1,qIndx,x);
    }
    void helpUpdate(int tIndx,int tL,int tR,int qIndx,T x) {
        if(tL==tR){
            tree[tIndx] = x;
            return;
        }
        int tM = (tL+tR)/2;
        if(tL<=qIndx && qIndx<=tM){
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
        if(tL>r || tR<l) {
            return identity;
        }
        if(tL>=l && r>=tR){
            return tree[tIndx];
        }
        int tM = (tL+tR)/2;
        return merge(helpQuery(2*tIndx+1,tL,tM,l,r),helpQuery(2*tIndx+2,tM+1,tR,l,r));
    }
};


signed main() {
    int n,m;
    cin >> n >> m;
    SegmentTree<Node> st(n+1,Node(INT_MIN));
    vector<int> hotels(n+1);
    for(int i=1;i<=n;i++) {
        int x;
        cin >> x;
        hotels[i] = x;
        st.update(i, Node(x));
    }
    
    // sort(hotels.begin(),hotels.end());
    while(m>0) {
        int t;
        cin >> t;
        int s = 1;
        int e = n;
        int ans = 0;
        while(s<=e){
            int mid = (s+e)/2;
            if(st.query(s,mid).val>=t) {
                ans = mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        st.update(ans,st.query(ans,ans).val-t);
        cout << ans << " ";
        m--;
    }
    cout << endl;
    return 0;
}