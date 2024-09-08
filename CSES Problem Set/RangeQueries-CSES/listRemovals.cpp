#include<bits/stdc++.h>
using namespace std;
#define int long long
class Node {
public:
    int val;

    Node(int val = 0) {
        this->val = val;
    }
};

Node merge(Node a, Node b) {
    return Node(a.val + b.val);
}

template<typename T>
class SegmentTree {
    int N;
    vector<T> tree;
    T identity;

public:
    SegmentTree(int n, T identity) {
        this->N = n;
        tree.resize(4 * N, identity);
        this->identity = identity;
    }

    void update(int qIndx, T x) {
        helpUpdate(0, 0, N - 1, qIndx, x);
    }

    void helpUpdate(int tIndx, int tL, int tR, int qIndx, T x) {
        if (tL == tR) {
            tree[tIndx] = x;
            return;
        }
        int tM = (tL + tR) / 2;
        if (tL <= qIndx && qIndx <= tM) {
            helpUpdate(2 * tIndx + 1, tL, tM, qIndx, x);
        }
        else {
            helpUpdate(2 * tIndx + 2, tM + 1, tR, qIndx, x);
        }
        tree[tIndx] = merge(tree[2 * tIndx + 1], tree[2 * tIndx + 2]);
    }

    T query(int l, int r) {
        return helpQuery(0, 0, N - 1, l, r);
    }

    T helpQuery(int tIndx, int tL, int tR, int l, int r) {
        // no overlap
        if (tL > r || tR < l) {
            return identity;
        }
        // partial overlap
        if (l <= tL && tR <= r) {
            return tree[tIndx];
        }
        int tM = (tL + tR) / 2;
        return merge(helpQuery(2 * tIndx + 1, tL, tM, l, r), helpQuery(2 * tIndx + 2, tM + 1, tR, l, r));
    }
};

signed main() {
    int n;
    cin >> n;
    SegmentTree<Node> st(n + 1, Node(0));
    vector<int> A(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        st.update(i, Node(1));
    }

    int  l = n;
    while (l > 0) {
        int t;
        cin >> t;

        int s = 0;
        int e = n - 1;
        int ans = -1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (st.query(0, mid).val >= t) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        st.update(ans, (1 - st.query(ans, ans).val));
        cout << A[ans] << endl;
        l--;
    }

    return 0;
}
