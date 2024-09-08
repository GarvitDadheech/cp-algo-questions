#include <iostream>
#include <vector>
#define int long long
using namespace std;

class SegmentTree {
    int N; // size of array
    int identity; // default value
    vector<int> tree; // tree array

public:
    SegmentTree(int N, int identity) {
        this->N = N;
        this->identity = identity;
        tree.resize(4 * N);
    }

    // function to merge
    int merge(int a, int b) {
        return min(a,b);
    }

    // updateQuery
    void updateTree(int qIndx, int x) {
        helpUpdate(0, 0, N - 1, qIndx, x);
    }

    void helpUpdate(int tIndx, int tL, int tR, int qIndx, int x) {
        if (tL == tR) {
            tree[tIndx] = x;
            return;
        }
        int tM = (tL + tR) / 2;
        if (tL <= qIndx && qIndx <= tM) {
            helpUpdate(2 * tIndx + 1, tL, tM, qIndx, x);
        } else {
            helpUpdate(2 * tIndx + 2, tM + 1, tR, qIndx, x);
        }
        tree[tIndx] = merge(tree[2 * tIndx + 1], tree[2 * tIndx + 2]);
    }

    // answerQuery
    int query(int l, int r) {
        return helpQuery(0, 0, N - 1, l, r);
    }

    int helpQuery(int tIndx, int tL, int tR, int l, int r) {
        // no overlap
        if (l > tR || r < tL) {
            return identity;
        }
        // complete overlap
        if (l <= tL && r >= tR) {
            return tree[tIndx];
        }
        // partial overlap
        int tM = (tL + tR) / 2;
        return merge(helpQuery(2 * tIndx + 1, tL, tM, l, r), helpQuery(2 * tIndx + 2, tM + 1, tR, l, r));
    }
};

signed main() {
    int N, Q;
    #include <climits> // Include the <climits> header file

    cin >> N >> Q;

    SegmentTree st(N + 1, INT_MAX); // Fix the problem by accessing INT_MAX from <climits>
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        st.updateTree(i, x);
    }

    while (Q > 0) {
        int t;
        cin >> t;
        if (t == 1) {
            int indx, val;
            cin >> indx >> val;
            st.updateTree(indx, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << endl;
        }
        Q--;
    }
    return 0;
}
