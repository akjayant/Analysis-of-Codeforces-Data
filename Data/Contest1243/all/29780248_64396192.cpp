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
    int n, izn;
    cin >> n;
    izn = n;
    if(n == 1) {
        cout << 1 << endl;
        return ;
    }
    vec<int> mul;
    for(int d = 2; d * d <= n; ++d) {
        while(n % d == 0) {
            mul.pb(d);
            n /= d;
        }
    }
    if(n != 1) mul.pb(n);

    sort(all(mul));
    Unique(mul);

    /*loop(i, SZ(mul)) cout << mul[i] << " ";
    cout << endl;*/

    if(SZ(mul) == 1) {
        cout << mul[0] << endl;
        return;
    }
    cout << 1 << endl;
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
   // cin >> t;
    while(t--) {
        read();
        solve();
    }
}/*
4
5
souse
houhe
3
car
dog
2
aa
az
3
abc
bca
*/
