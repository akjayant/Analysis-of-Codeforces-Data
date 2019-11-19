#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("avx")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

void shift()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
signed main()
{
    shift();
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    int l = 0;
    int cntl = 1;
    int r = n - 1;
    int cntr = 1;
    while(l < r) {
        if (cntl < cntr) {
            if (k < (a[l + 1] - a[l]) * cntl) {
                int mx = a[l] + k / cntl;
                cout << a[r] - mx;
                return 0;
            }
            k -= (a[l + 1] - a[l]) * cntl;
            ++l, cntl++;
            while(l < r && a[l + 1] == a[l])
                ++l, cntl++;
        } else {
            if (k < (a[r] - a[r - 1]) * cntr) {
                int mx = a[r] - k / cntr;
                cout << mx - a[l];
                return 0;
            }
            k -= (a[r] - a[r - 1]) * cntr;
            --r;
            cntr++;
            while(l < r && a[r - 1] == a[r])
                --r, cntr++;
        }
    }
    cout << 0;
    return 0;
}
