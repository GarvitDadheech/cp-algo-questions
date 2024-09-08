#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;
    stack<vector<int>> st;
    int components;

public:
    DSU(int n) {
        parent.assign(n,0);
        rank.assign(n,1);
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int a) {
        if (parent[a] == a) {
            return a;
        }
        return findParent(parent[a]);
    }

    void unionSets(int a, int b) {
        int ap = findParent(a);
        int bp = findParent(b);
        if (ap != bp) {
            st.push({a, b, rank[ap], rank[bp]});
            if (rank[ap] < rank[bp]) {
                parent[ap] = bp;
            } else if (rank[ap] > rank[bp]) {
                parent[bp] = ap;
            } else {
                parent[bp] = ap;
                rank[ap]+=rank[bp];
            }
            components--;
        }
    }

    void persist() {
        st.push({-1});
    }

    void rollback() {
        while (st.size() && st.top()[0] != -1) {
            vector<int> arr = st.top();
            st.pop();
            int a = arr[0];
            int b = arr[1];
            int size_a = arr[2];
            int size_b = arr[3];

            parent[a] = a;
            parent[b] = b;
            rank[a] = size_a;
            rank[b] = size_b;

            components++;
        }
        st.pop();
    }

    int getComponents() {
        return components;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n + 1);

    for (int i = 0; i < m; i++) {
        string op; cin>>op;
        
        if(op=="persist") {
            dsu.persist();
        }
        else if(op=="union") {
            int a, b; cin>>a>>b;
            dsu.unionSets(a, b);
            cout << dsu.getComponents()-1 << endl;
        }
        else if(op=="rollback") {
            dsu.rollback();
            cout << dsu.getComponents()-1 << endl;
        }
    }

    return 0;
}
