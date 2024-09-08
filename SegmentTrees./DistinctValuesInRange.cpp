#include <bits/stdc++.h>
using namespace std;

class MergeSortTree {
private:
    vector<vector<int>> tree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node].push_back(arr[start]);
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    vector<int> merge(const vector<int>& left, const vector<int>& right) {
        vector<int> result;
        size_t i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                result.push_back(left[i]);
                i++;
            } else {
                result.push_back(right[j]);
                j++;
            }
        }
        while (i < left.size()) {
            result.push_back(left[i]);
            i++;
        }
        while (j < right.size()) {
            result.push_back(right[j]);
            j++;
        }
        return result;
    }

    int countDistinct(const vector<int>& sortedList, int a, int b) {
        set<int> distinctValues;
        for (int value : sortedList) {
            if (value >= a && value <= b) {
                distinctValues.insert(value);
            }
        }
        return distinctValues.size();
    }

public:
    MergeSortTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    int query(int L, int R, int a, int b, int node, int start, int end) {
        if (start > R || end < L) {
            return 0;
        }
        if (start >= L && end <= R) {
            return countDistinct(tree[node], a, b);
        }
        int mid = (start + end) / 2;
        int leftQuery = query(L, R, a, b, 2 * node + 1, start, mid);
        int rightQuery = query(L, R, a, b, 2 * node + 2, mid + 1, end);
        return leftQuery + rightQuery;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MergeSortTree mst(arr);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;  // Convert to 0-based index
        int result = mst.query(a, b, INT_MIN, INT_MAX, 0, 0, n - 1);
        cout << result << "\n";
    }

    return 0;
}
