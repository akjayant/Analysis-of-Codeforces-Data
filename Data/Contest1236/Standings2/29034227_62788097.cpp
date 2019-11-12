#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int exp(int a, int b) {
    int r = 1;    
    while (b > 0) {
        if (b&1) r = a*1ll*r%mod;
        a=a*1ll*a%mod;
        b >>= 1;
    }
    return r;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << exp(exp(2, m) + mod - 1, n) << endl;
    return 0;
}