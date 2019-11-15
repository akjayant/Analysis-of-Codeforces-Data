//{ <defines>
#ifndef _LOCAL
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#endif
#include <bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define re return
#define fo(n) for(int i=0;i<n;++i)
#define fr(i,n) for(int i=0;i<n;++i)
#define forb(a, b, c) for(int a = b; a != c; a += ((~~(b<c))<<1)-1)
#define ifn(x) if(!(x))
#define ef else if
#define ve vector
#define sz(x) int(x.size())
#define _  << ' ' <<
#define pb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef ve<int> vi;
const ll OO = 4e18;
const ld pi = 3.1415926535897932384626433832;
const int md = 1e9 + 7,
          oo = 2e9;
//} </defines>
const int N = +100500;

int n;
string p, t;

void solve() {
    cin >> p; n = sz(p);
    fo(n) if(p[i] == 'm' || p[i] == 'w') {cout << 0 << endl; re;}
    int dp[n+1]; memset(dp, 0, sizeof dp);
    dp[0] = 1;
    fo(n) {
        (dp[i+1] += dp[i]) %= md;
        if(i+1 < n && (p[i] == 'n' && p[i+1] == 'n' || p[i] == 'u' && p[i+1] == 'u')) (dp[i+2] += dp[i]) %= md;
    }
    cout << dp[n] << endl;
}

int main() {
#ifdef _LOCAL
    freopen("in.txt", "r", stdin);
    int tt; cin >> tt;
#else
    ios_base :: sync_with_stdio(0);
    int tt = 1;
#endif
    while(tt--) solve();
}
