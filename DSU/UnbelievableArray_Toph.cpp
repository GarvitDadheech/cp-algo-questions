#include<bits/stdc++.h>
using namespace std;

class DSU {
    public:
        vector<int> parent;
        DSU(int n) {
            parent.resize(n);
            for(int i=1;i<n;i++) {
                parent[i] = i;
            }
        }

        int findParent(int x) {
            if(x==parent[x]) {
                return x;
            }
            return parent[x] = findParent(parent[x]);
        }

        void unite(int x,int y) {
            ;
        }
};

int main() {
    int t; cin >> t;
    while(t--) {
        cout << "Case 1:" << endl;
        int n,q; cin >> n >> q;
        DSU dsu(n);
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }
        map<int,int> mp;
        for(int i=0;i<n;i++) {
            if(mp.count(arr[i])==0) {
                mp[arr[i]] = i;
            }
        }
        for(int i=0;i<n;i++) {
            dsu.unite(i,mp[arr[i]]);
        }
        while(q--) {
            int op; cin >> op;
            if(op==1) {
                int x, y; cin >> x >> y;
                if(mp.count(x)==0) {
                    continue;
                }
                if(mp.count(y)==0) {
                    int root = dsu.findParent(mp[x]);
                    mp.erase(x);
                    mp[y] = root;
                    arr[root] = y;
                    continue;
                }

                dsu.unite(dsu.findParent(mp[x]),dsu.findParent(mp[y]));
                int root = dsu.findParent(dsu.findParent(mp[x]));
                mp.erase(x);
                mp[y] = root;
                arr[root] = y;
            } 
            else{
                int x; cin >> x;
                cout << dsu.findParent(x) << endl;
            } 
        }
    }
}