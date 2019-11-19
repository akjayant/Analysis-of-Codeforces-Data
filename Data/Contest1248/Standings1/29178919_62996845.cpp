#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
#define int ll
#define endl '\n'
#define TIME 1.0*clock()/CLOCKS_PER_SEC

using namespace std;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 3e5 + 7;
const int M = 1e9 + 7;
const int FFTM = 998244353;

ll n, p, t[N], res[N];

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("drone.in", "r", stdin);
//    freopen("drone.out", "w", stdout);
#endif
    cin >> n >> p;
    for (int i = 0; i < n; i++) cin >> t[i];
    set<pair<int,pair<ll,int> > > q;
    set<pair<int,ll> > q2;
    set<ll> all;all.insert(1e9 + 7);
    ll cur = -1;
    for (int i = 0; i < n; i++) q.insert( {t[i], {0, i}} );
    while (!q.empty()){
        int tp = q.begin()->S.F;
        ll T = q.begin()->F;
        int j = q.begin()->S.S;
        q.erase(q.begin());
//        cerr << tp << ' ' << T << ' ' << j << ' ' << q2.size() << endl;
        if (tp == 1){
            all.erase(j);
            while (!q2.empty()){
                ll i = q2.begin()->F;
                ll tm = q2.begin()->S;
                if (!all.empty() && (*all.begin()) < i) break;
                cur = max(cur, tm) + p;
                q.insert( {cur, {1, i}} );
                q2.erase(q2.begin());
                all.insert(i);
                res[i] = cur;
            }
        }
        else if (tp == 0){
            if (all.empty() || (*all.begin()) > j){
                cur = max(cur, T) + p;
                all.insert(j);
                res[j] = cur;
                q.insert( {cur, {1, j}} );
            }
            else q2.insert( {j, T} );
        }
    }
    for (int i = 0; i < n; i++) cout << res[i] << ' ';
    return 0;
}
