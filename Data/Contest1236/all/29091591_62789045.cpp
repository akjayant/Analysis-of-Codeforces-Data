#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
using namespace std;
const ll MOD = 1e9 + 7;
ll binpow(ll a,ll b) {
    if(b == 0) return 1;
    if(b & 1) return binpow(a, b - 1) * a % MOD;
    return binpow(a * a % MOD, b >> 1);
}

signed main() {
    int n, m;
    cin >> n >> m;
    cout << binpow(binpow(2, m) -1, n);
    return 0;
}