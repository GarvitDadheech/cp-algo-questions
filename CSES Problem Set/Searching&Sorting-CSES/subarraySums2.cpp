#include<bits/stdc++.h>
using namespace std;

int numberSubArrays(vector<int> &A,int n,int k) {
    vector<int> ps(n);
    int ans = 0;
    ps[0] = A[0];
    map.add(ps[0]);
    map<int,int> map;
    for(int i=1;i<n;i++) {
        ps[i] = ps[i-1] + A[i];
        if(ps[i]==k) {
            ans++;
        }
        if(map.containsKey(ps[i])) {
            int freq = map.get(ps[i]);
            map.put(ps[i],freq+1);
        }
        else {
            map.put(ps[i],1);
        }
        if(map.contains(ps[i]-k)) {
            int freq1 = map.get(ps[i]-k);
            ans = ans + freq1;
        }
    }
}


int main() {
    return 0;
}