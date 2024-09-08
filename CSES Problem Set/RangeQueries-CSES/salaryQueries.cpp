#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds;
using namespace std;

template <typename T>
class OrderedSet {
private:
    tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update> st;
public:
    int countElementsLessThanX(T x) {
        return st.order_of_key(x);
    }

    int countElementsAtleastX(T x) {
        return st.size() - countElementsLessThanX(x);
    }

    T getKthElement(int k) {
        return *st.find_by_order(k);
    }
    
    void insert(T x) {
        st.insert(x);
    }
    
    void erase(T x) {
        st.erase(x);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    OrderedSet<pair<int, int>> st;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        st.insert({A[i], i});
    }

    while (q--) {
        char x;
        cin >> x; 
        if (x == '!') {
            int idx, newSal;
            cin >> idx >> newSal;
            idx--;
            st.erase({A[idx], idx});
            A[idx] = newSal;
            st.insert({A[idx], idx});
        } else {
            int a, b;
            cin >> a >> b;
            cout << (int)st.countElementsLessThanX({b, INT_MAX}) - (int)st.countElementsLessThanX({a-1, INT_MAX}) << endl;
        }
    }

    return 0;
}
