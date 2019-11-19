#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 2020;
ll n;
ll c[MAXN];
ll k[MAXN];
ll d[MAXN];

struct pnt {
    ll x, y;
};

pnt a[MAXN];
bool used[MAXN];
ll p[MAXN];
bool light[MAXN];

int main() {
//     freopen("negcycle.in", "r", stdin);
//     freopen("negcycle.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    set<pair<ll, ll>> q;
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
        d[i] = c[i];
        light[i] = 1;
        q.insert({d[i], i});
    }
    for (ll i = 0; i < n; ++i) {
        cin >> k[i];
        p[i] = -1;
    }
    ll ans = 0;
    vector<ll> a1;
    vector<pnt> e;
    while (!q.empty()) {
        ll v = q.begin()->second;
        used[v] = 1;
        ans += d[v];
        if (light[v]) {
            a1.push_back(v);
        }
        if (p[v] != -1) {
            e.push_back({v, p[v]});
        }
        q.erase(q.begin());
        for (ll i = 0; i < n; ++i) {
            if (!used[i]) {
                ll cur = (k[v] + k[i]) * (abs(a[i].x - a[v].x) + abs(a[i].y - a[v].y));
                if (cur < d[i]) {
                    light[i] = 0;
                    q.erase({d[i], i});
                    p[i] = v;
                    d[i] = cur;
                    q.insert({d[i], i});
                }
            }
        }
    }
    cout << ans << endl;
    cout << a1.size() << endl;
    sort(a1.begin(), a1.end());
    for (ll i : a1) {
        cout << i + 1 << " ";
    }
    cout << endl;
    cout << e.size() << endl;
    for (auto i : e) {
        cout << i.x + 1 << " " << i.y + 1 << endl;
    }
}