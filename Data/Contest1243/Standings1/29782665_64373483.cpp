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
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(rall(a));
        int mx = 0;
        for(int i = 0; i < n; ++i) {
            mx = max(mx, min(i + 1, a[i]));
        }
        cout << mx << '\n';
    }
    return 0;
}
