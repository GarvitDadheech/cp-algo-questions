#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int cntFactors[N+1];

void makeSieve(){
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j=j+i){
            cntFactors[j]++;
        }
    }
}

int main(){
    int x,Q;
    cin >> Q;
    makeSieve();
    while(Q>0){
        cin >> x;
        cout << cntFactors[x] << endl;
        Q--;
    }
}