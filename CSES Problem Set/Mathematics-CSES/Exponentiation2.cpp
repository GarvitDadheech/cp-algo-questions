#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long divide(int a,int b,int mod){
    if(b==0){
        return 1;
    }
    if(a==0 || b==1){
        return a;
    }
    if(b%2==0){
        return (divide(a,b/2,mod)%(mod))*(divide(a,b/2,mod)%(mod))%(mod);
    }
    else{
        return ((a%(mod))*(divide(a,b-1,mod)%(mod)))%(mod);
    }
}

int main() {
    int Q,a,b,c;
    cin >> Q;
    while(Q>0){
        cin >> a;
        cin >> b;
        cin >> c;
        long long r = divide(b,c,mod-1);
        cout << divide(a,r,mod) << endl;
        Q--;
    }
}

































































































