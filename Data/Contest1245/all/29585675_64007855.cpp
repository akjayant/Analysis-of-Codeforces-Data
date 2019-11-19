#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll x[2005], y[2005], c[2005], k[2005];
int super;
vector<pair<ll, pair<int, int> > > v;
int dsu[2005];
int f(int x) {return dsu[x] = (dsu[x] == x ? x : f(dsu[x])); }
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    super = n + 1;
    for (int i = 1; i <=n ; ++i) cin >> x[i] >> y[i];
    for (int i = 1; i <= n + 1; ++i) dsu[i] = i;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        v.push_back(make_pair(c[i], make_pair(i, super)));
    }
    for (int i = 1; i <= n; ++i) cin >> k[i];
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            v.push_back(make_pair((k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])), make_pair(i, j)));
    sort(v.begin(), v.end());
    ll ans = 0;
    vector<int> power;
    vector<pair<int, int> > conn;
    for (int i = 0; i < v.size(); ++i) {
        ll cost = v[i].first, u = v[i].second.first, x = v[i].second.second;
        if (f(u) == f(x)) continue;
        dsu[f(u)] = f(x);
        if (x == super) power.push_back(u);
        else conn.push_back(make_pair(u, x));
        ans += cost;
    }
    cout << ans << endl;
    cout << power.size () << endl;
    for (int i = 0; i < power.size(); ++i) cout << power[i] << ' ';
    if (power.size() != 0) cout << endl;
    cout << conn.size () << endl;
    for (int i = 0; i < conn.size(); ++i) cout << conn[i].first << " " << conn[i].second << endl;

}
 