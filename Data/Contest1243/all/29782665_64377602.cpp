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
        string a, b;
        cin >> a >> b;
        // vector<pair<int, char> >a;
        vector<int>aa;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                ++cnt;
                aa.push_back(i);
            }
        }
       if (cnt != 2) {
            cout << "No" << '\n';
       } else {
            swap(a[aa[0]], b[aa[1]]);
            if (a != b) {
                cout << "No" << '\n';
            } else {
            cout << "Yes" << '\n';
            }
       }
    }
    return 0;
}
