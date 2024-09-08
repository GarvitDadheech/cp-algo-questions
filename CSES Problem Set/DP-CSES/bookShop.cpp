#include <bits/stdc++.h>
using namespace std;

int maxNumPages(vector<int> &prices, int x, vector<int> &pages, int currPrice, int index,vector<vector<int>> &dp) {
    if (currPrice > x) {
        return 0;
    }
    if (index >= prices.size()) {
        return 0;
    }
    if (dp[index][currPrice] != -1) {
        return dp[index][currPrice];
    }
    // Case 1: Skip the current book
    int ans = maxNumPages(prices, x, pages, currPrice, index + 1,dp);

    // Case 2: Take the current book if possible
    if (currPrice + prices[index] <= x) {
        ans = max(ans, pages[index] + maxNumPages(prices, x, pages, currPrice + prices[index], index + 1,dp));
    }

    return dp[index][currPrice] = ans;
}

int main() {
    int n;
    cin >> n;
    int x;
    cin >> x;
    vector<int> prices(n);
    vector<int> pages(n);
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << maxNumPages(prices, x, pages, 0, 0,dp) << endl;

    return 0;
}
