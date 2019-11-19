#include<bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ld double
#define null nullptr
#define endl '\n'

using namespace std;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 1e5 + 7;
const int M = 1e9 + 7;

int n;
ll x[N], y[N], c[N], k[N];

ll l(int i, int j){
    return (abs(x[i] - x[j]) + abs(y[i] - y[j]))*(k[i] + k[j]);
}

struct dsu{
    int p[N];
    ll a[N];

    dsu(){for (int i = 0; i < n; i++) p[i] = i, a[i] = i;}

    int get(int v){
        return p[v] = (p[v] == v ? v : get(p[v]));
    }

    ll unite(int x, int y, ll len){
        int X = get(x);
        int Y = get(y);
        if (X == Y) return 0;
        if (c[a[X]] + c[a[Y]] < min(c[a[X]], c[a[Y]]) + len) return 0;
        if (gen()%2) swap(X, Y);
        p[Y] = X;
        ll was = (c[a[X]] + c[a[Y]]);
        if (c[a[Y]] < c[a[X]]) a[X] = a[Y];
        return -was + c[a[X]] + len;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    cin >> n;
    ll res = 0;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++) cin >> c[i], res += c[i];
    for (int i = 0; i < n; i++) cin >> k[i];
    vector<pair<ll,pair<int,int> > > e;
    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        e.pb( {l(i, j), {i, j}} );
    sort(e.begin(), e.end());
    dsu d;
    vector<pair<int,int> > all;
    for (int i = 0; i < e.size(); i++){
        ll ret = d.unite(e[i].S.F, e[i].S.S, e[i].F);
        res += ret;
        if (ret != 0) all.pb( {e[i].S.F, e[i].S.S} );
    }
    cout << res << endl;
    int cnt = 0;
    for (int i = 0; i < n; i++) if (d.p[i] == i) cnt++;
    cout << cnt << endl;
    for (int i = 0; i < n; i++) if (d.p[i] == i) cout << d.a[i] + 1 << ' ';
    cout << endl << all.size() << endl;
    for (auto it : all) cout << it.F + 1 << ' ' << it.S + 1 << endl;
    return 0;
}
