#include<bits/stdc++.h>
using namespace std;
// Print all numbers less than n
void printTillNum(int indx,bool tight,string &s,string currNum) {
    if(indx>=s.size()) {
        cout << currNum << endl;
        return;
    }
    int lb = 0;
    int ub = 9;
    if(tight) {
        ub = s[indx]-'0';
    }
    for(int i=lb;i<ub;i++) {
        printTillNum(indx+1,false,s,currNum+to_string(i));
    }
    printTillNum(indx+1,tight,s,currNum+to_string(ub));
}

int main() {
    string s;
    cin >> s;
    printTillNum(0,true,s,"");
}
