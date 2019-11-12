#include <bits/stdc++.h>

//#pragma GCC optimize ("O3")
//#pragma GCC target ("avx2")
//#pragma GCC target (sse, sse2, sse3, ssse3, sse4,popcnt,tune=native)

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define SZ(a) (int)(a.size())
#define Read() freopen("input.cpp", "r", stdin)
#define Write() freopen("output.cpp", "w", stdout)
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

const int MAXN = 2e5 + 47, inf = 1e17 + 47;

int n, m;
vec<vec<int> >  graf(MAXN);

void read(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vec<char> kek;
    loop(i, n) if(a[i] !=  b[i]) kek.pb(a[i]), kek.pb(b[i]);
    if(SZ(kek) == 4 && kek[0] == kek[2] && kek[1] == kek[3]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
void solve() {

}

signed main() {
    #ifdef COFFEE_MACHINE
        Read();
        Write();
    #endif
    CIN;
    int t = 1;
    cin >> t;
    while(t--) {
        read();
        solve();
    }
}
