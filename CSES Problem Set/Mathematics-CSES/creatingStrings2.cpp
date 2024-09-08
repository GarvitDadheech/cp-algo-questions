#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int N = 1e6+10; 
typedef long long ll; 
int freq[26];   
ll fact[N+1], invFact[N+1]; 

ll findPower(ll a, ll b) { 
    if(b==0){
        return 1;
    }
    if(b%2==0){
        ll half = findPower(a,b/2);
        half = (half*half)%mod;
        return half;
    } 
    return (a*findPower(a,b-1))%mod;
}

ll modInverse(ll x){
    return findPower(x,mod-2);
}

void fillFact() {
    fact[0] = 1;
    for(int i=1;i<=N;i++){
        fact[i] = (i*fact[i-1])%mod;
    }
    for(int i=0;i<=N;i++){
        invFact[i] = modInverse(fact[i]);
    }
}

int main() {
    fillFact();
    string s;
    cin >> s;
    for (char c : s) {
        freq[c - 'a']++;
    }
    int n = s.length();
    int ans = fact[n];

    for(int i=0;i<26;i++){
        ans = (ans * invFact[freq[i]])%mod;
    }
    cout << ans << endl;
    return 0;
}
