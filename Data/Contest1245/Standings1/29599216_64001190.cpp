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

int n, a[3];
string p, t;

void solve() {
    cin >> n >> a[0] >> a[2] >> a[1] >> p;
    int q[n], w[n], ans = 0; memset(w, -1, sizeof w);
    fo(n) if(p[i] == 'R') q[i] = 0; ef(p[i] == 'S') q[i] = 1; ef(p[i] == 'P') q[i] = 2;
    fo(n) if(a[(q[i]+2)%3]) a[(q[i]+2)%3]--, w[i] = (q[i]+2)%3, ++ans;
    if(ans * 2 < n) {
        cout << "NO\n";
        re;
    }
    cout << "YES\n";
    fo(n) if(w[i] < 0) fr(j, 3) if(a[j]) {w[i] = j; a[j]--; break;}
    t = "";
    fo(n) {
        char c = 'R';
        if(w[i] == 1) c = 'S';
        if(w[i] == 2) c = 'P';
        t += c;
    }
    cout << t << endl;
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
