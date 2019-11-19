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
set<paii> was;

void read(){
    cin >> n >> m;
    loop(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if(a > b) swap(a, b);
        was.insert({a, b});
    }
}
vec<int> P;

void bfs() {
    queue<int> q;
    q.push(P.back());
    P.pop_back();
    while(SZ(q) > 0) {
        int p1 = q.front();
        q.pop();

        //cout << p1 + 1 << endl;

        vec<int> temp;
        while(SZ(P) > 0) {
            int p2 = P.back();
            P.pop_back();
            int h1 = min(p1, p2), h2 = max(p1, p2);
            if(was.count({h1, h2}) == 0) {
                q.push(p2);
            } else {
                temp.pb(p2);
            }
        }
        P = temp;
    }
}

void solve() {
    int cnt = 0;

    loop(i, n) P.pb(i);

    //cout <<SZ(P) <<endl;

    while(SZ(P) > 0) {
        ++cnt;
        bfs();
    }
    cout << cnt -1 << endl;
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
6 11
1 3
1 4
1 5
1 6
2 3
2 4
2 5
2 6
3 4
3 5
3 6
*/
