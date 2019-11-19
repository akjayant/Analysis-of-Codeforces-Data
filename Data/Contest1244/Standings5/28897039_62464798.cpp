#include <bits/stdc++.h>
/*
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#pragma GCC target (sse, sse2, sse3, ssse3, sse4,popcnt,tune=native)
*/
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define SZ(a) (int)(a.size())
#define Read() freopen("input.txt", "r", stdin)
#define Write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Unique(x)  x.erase(unique(all(x)), x.end())
#define pi acos(-1.0)
#define vec vector
#define mp make_pair
#define paii pair<int, int>
#define padd pair<dd, dd>
#define pall pair<ll, ll>
#define fr first
#define sc second
#define endl "\n"
#define vec vector

using namespace std;

#define int long long

const int MAXN = 3e5 + 47;

int n;

void read() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int q = (a - 1) / c + 1;
    int r = (b - 1) / d + 1;
    if(q + r <= k) cout << q << " " << r << endl;
    else cout << -1 << endl;
}

void solve() {
}

signed main()
{
    CIN;
    int t = 1;
    cin >> t;
    while(t--) {
        read();
        solve();
    }
}
