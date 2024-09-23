#include<bits/stdc++.h>
using namespace std;

class SqrtDecomposition{
    vector<int> arr;
    vector<int> sqrtArr;
    int n;
    int blockSize;
public: 
    SqrtDecomposition(vector<int> &a) {
        arr = a;
        n = a.size();
        blockSize = sqrt(n) + 1;
        sqrtArr.assign(blockSize,INT_MAX);

        for(int i=0;i<n;i++) {
            int blockIndx = i/blockSize;
            sqrtArr[blockIndx] = min(sqrtArr[blockIndx],arr[i]); 
        }

    }

    int query(int l,int r) {
        int ans = INT_MAX;
        for(int i=l;i<=r;i++) {
            if(i%blockSize!=0 || i+blockSize-1>r) {
                ans = min(ans,arr[i]);
            }
            else{
                ans = min(ans,sqrtArr[i/blockSize]);
                i += blockSize-1;
            }
        }
        return ans;
    }

    void update(int idx,int val) {
        arr[idx] = val;
        int blockIndx = idx/blockSize;
        sqrtArr[blockIndx] = INT_MAX;
        int start = blockIndx*blockSize;
        int end = start + blockSize -1;
        for(int i=start;i<=end;i++) {
            sqrtArr[blockIndx] = min(sqrtArr[blockIndx],arr[i]);
        }
    }
};

int main() {

    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    SqrtDecomposition sqrtDecomposition(a);
    while(q--) {
        int type;
        cin >> type;
        if(type==1) {
            int idx,val; cin >> idx >> val;
            sqrtDecomposition.update(idx-1,val);
        }
        else{
            int l,r; cin >> l >> r;
            cout << sqrtDecomposition.query(l-1,r-1) << endl;
        }
    }

    return 0;
}