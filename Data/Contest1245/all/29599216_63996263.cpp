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
const int md = 0x3b800001,
          oo = 2e9;
//} </defines>
const int N = +100500;

int a, b;

void solve() {
    cin >> a >> b;
    cout << (__gcd(a, b) == 1 ? "Finite\n" : "Infinite\n");
}

int main() {
#ifdef _LOCAL
    freopen("in.txt", "r", stdin);
#else
    ios_base :: sync_with_stdio(0);
//    int tt = 1;
#endif
    int tt; cin >> tt;
    while(tt--) solve();
}
