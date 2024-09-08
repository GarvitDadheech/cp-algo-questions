#include <iostream>
using namespace std;

typedef long long ll;

ll power(ll x, ll n, ll mod) {
    ll result = 1;
    x = x % mod; // Take modulo of base if it's larger than mod
    while (n > 0) {
        if (n & 1) // If n is odd, multiply x with result
            result = (result * x) % mod;
        n = n >> 1; // n = n / 2
        x = (x * x) % mod; // Change x to x^2
    }
    return result;
}

ll f(ll ratio, ll numOfTerms, ll mod) {
    if (numOfTerms == 0) return 0;
    if (numOfTerms == 1) return 1;
    
    ll even = f((ratio * ratio) % mod, numOfTerms / 2, mod);
    ll result = (1 + ratio) * even % mod;
    
    if (numOfTerms % 2 == 1) {
        result = (result + power(ratio, numOfTerms - 1, mod)) % mod;
    }
    
    return result;
}

int main() {
    ll A, X, mod;
    cin >> A >> X >> mod;
    
    if (mod == 1) {
        cout << 0 << endl;
    } else {
        cout << f(A % mod, X, mod) << endl;
    }
    
    return 0;
}
