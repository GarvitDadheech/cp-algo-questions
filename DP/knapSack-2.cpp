#include<bits/stdc++.h>
using namespace std;

vector<int> wt,cost;

int help(int indx,int profit,int N) {
    if(indx==N){
        if(profit==0){
            return 0;
        }
        return INT_MAX;
    }
    int ans1 = help(indx+1,profit,N);
    int ans2 = 0;
    if(cost[indx]<=profit) {
        ans2 = wt[indx] + help(indx+1,profit-cost[indx],N);
    }
    return min(ans1,ans2);
}


int main(){
    int N, W;
    cin >> N >> W;
    wt.resize(N);
    cost.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> wt[i] >> cost[i];
    }
    int maxprofit = 0;
    

    int result = help(0, 100000, N);
    
    cout << result << endl;

    return 0;

}