#include<bits/stdc++.h>
using namespace std;

void dfs(int curr,vector<int> adj[],vector<int> &ans) {
    for(int nb : adj[curr]) {
        dfs(nb,adj,ans);
        ans[curr] += ans[nb]+1;
    }
}

int main() {
    int n; cin >> n;
    vector<int> adj[n+1];

    for(int i=2;i<=n;i++) {
        int child;
        cin >> child;
        adj[child].push_back(i);
    }
    vector<int> ans(n+1);
    dfs(1,adj,ans);
    for(int i=1;i<=n;i++) {
        cout << ans[i] << " ";
    }

    return 0;
}