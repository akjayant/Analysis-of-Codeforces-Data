#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
long long powmod (long long a, long long n, long long mod) {
        long long ans = 1;
        while (n) {
                if (n&1ll) ans = ans * a % mod;
                n /= 2;
                a = a * a % mod;
        }
        return ans % mod;
}
int main () {
        int n, m; cin >> n >> m;
        cout << powmod((powmod(2,m,mod)-1+mod)%mod,n,mod) << endl;
        return 0;
}