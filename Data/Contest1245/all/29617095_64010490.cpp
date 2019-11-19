#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> iii;

const ll N = 1e6 + 5;
const ll INF = 1e18 + 7;

ll n, kq = INF, c[N], k[N], d[N], P[N];
ii a[N];

int main() {
    //freopen("1245D.INP", "r", stdin);
    //freopen("1245D.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    for (ll i = 1; i <= n; i++) cin >> c[i];
    for (ll i = 1; i <= n; i++) cin >> k[i];
    //********************
    ll s = min_element(c + 1, c + n + 1) - c;
    for (; ;) {
        ll C = 0;
        priority_queue <iii, vector <iii>, greater <iii> > Q;
        fill(d + 1, d + n + 1, INF);
        Q.push(iii(c[s], ii(s, 1))); d[s] = c[s];
        vector <ll> v1; v1.clear();
        vector <ii> v2; v2.clear();
        while (not Q.empty()) {
            ll u = Q.top().second.first, du = Q.top().first, tt = Q.top().second.second;
            Q.pop();
            if (d[u] != du) continue;
            C += d[u]; d[u] = 0;
            if (tt == 1) v1.push_back(u);
            else v2.push_back(ii(u, P[u]));
            for (ll v = 1; v <= n; v++) if (d[v] > c[v]) {
                d[v] = c[v];
                Q.push(iii(d[v], ii(v, 1)));
            }
            for (ll v = 1; v <= n; v++)
                if (d[v] > (k[u] + k[v]) * (abs(a[u].first - a[v].first) + abs(a[u].second - a[v].second))) {
                d[v] = (k[u] + k[v]) * (abs(a[u].first - a[v].first) + abs(a[u].second - a[v].second));
                Q.push(iii(d[v], ii(v, 2)));
                P[v] = u;
            }
        }
        kq = min(kq, C);
        cout << kq << endl;
        cout << size_t(v1.size()) << endl;
        for (auto it : v1) cout << it << " "; cout << endl;
        cout << size_t(v2.size()) << endl;
        for (auto it : v2) cout << it.first << " " << it.second << endl;
        exit(0);
    }
    //********************
    cout << kq;
    return 0;
}
