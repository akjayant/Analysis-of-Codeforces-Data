#pragma GCC optimize("03")
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long 

using namespace std;

ll n;
pair<ll, ll> a[2010];
ll c[2010], k[2010];
ll bst[2010];
ll viz[2010];
vector<pair<ll, ll> > sol;
vector<ll> stations;
ll ans;

ll get(int x, int y) {
    if (x == n)
        return c[y];

    if (y == n)
        return c[x];
    
    ll dx = abs(a[x].fi - a[y].fi);
    ll dy = abs(a[x].se - a[y].se);
    return (dx + dy) * (k[x] + k[y]);
}

int main() {
    // ifstream cin("tst.in");
    // ofstream cout("tst.out");
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;

    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int i = 1; i <= n; i++)
        cin >> k[i];

    for (int i = 1; i <= n; i++)
        bst[i] = n + 1;

    n++;

    for (int i = 1; i < n; i++) {
        ll mn = LLONG_MAX;
        ll id = -1;
        for (int j = 1; j < n; j++) {
            if (viz[j])
                continue;
        
            ll dist = get(j, bst[j]);
            if (dist < mn) {
                mn = dist;
                id = j;
            }  
        } 

        ans += mn;
        viz[id] = 1;
        if (bst[id] == n) {
            stations.push_back(id);
        } else {
            sol.push_back({id, bst[id]});
        }

        for (int j = 1; j < n; j++) {
            ll dist = get(j, id);
            if (dist < get(j, bst[j]))
                bst[j] = id;
        }
    }

    cout << ans << '\n';
    cout << (int) stations.size() << '\n';
    for (auto it : stations)
        cout << it << ' ';
    cout << '\n';
    cout << (int) sol.size() << '\n';
    for (auto it : sol)
        cout << it.fi << ' ' << it.se << '\n';

    return 0;
}