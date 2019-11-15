#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N = 1e6, mod = 1e9 + 7;
int binpow (int a, int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpow(a, n-1) % mod) * a % mod;
    else {
        int b = binpow(a, n/2 ) % mod;
        return (b * b)  % mod;
    }
}
signed main() {
   int n, m;
   cin>>n>>m;
   int g = (binpow(2, m) - 1 % + mod) % mod;
   cout<<binpow(g, n) % mod<<endl;
}