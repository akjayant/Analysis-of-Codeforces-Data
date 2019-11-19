#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}




signed main() {
    accell();
    int n;
    cin >> n;
    int g = n;
    for(int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            g = __gcd(g, i);
            g = __gcd(g, n / i);
        }
    }
    cout << g << '\n';
    return 0;
}
