#include <bits/stdc++.h>

#define ll long long
#define all(x) x.begin(),x.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const ll INF = 1e18;
const ll MN = 1000000;
const ll mod = 1e9 + 7;

void add(int &a, int &b) {
    a += b;
    while (a >= mod)
        a -= mod;
}

int main() {
    fast
    int n;
    cin >> n;
    ll x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    ll c[n], k[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    ll dist[n];
    pair<int, int> par[n];
    for (int i = 0; i < n; i++) {
        dist[i] = c[i];
        par[i] = {-1, -1};
    }
    vector<bool> us(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll mi = INF;
        ll v = -1;
        for (int j = 0; j < n; j++) {
            if (us[j])
                continue;
            if (dist[j] < mi) {
                mi = dist[j];
                v = j;
            }
        }
        us[v] = true;
        sum += mi;
        for (int j = 0; j < n; j++) {
            if (us[j])
                continue;
            ll nd = (k[v] + k[j]) * (abs(x[v] - x[j]) + abs(y[v] - y[j]));
            if (dist[j] > nd) {
                dist[j] = nd;
                par[j] = {1, v};
            }
        }
    }
    cout << sum << '\n';
    vector<int> el;
    vector<pair<int, int>> rb;
    for (int i = 0; i < n; i++) {
        if (par[i].first == -1)
            el.emplace_back(i + 1);
        else
            rb.emplace_back(i + 1, par[i].second + 1);
    }
    cout << el.size() << '\n';
    for (auto i : el)
        cout << i << ' ';
    cout << '\n' << rb.size() << '\n';
    for (auto[a, b] : rb) {
        cout << a << ' ' << b << endl;
    }
}