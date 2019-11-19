#include <bits/stdc++.h>
#define f first
#define s second
#define push push_back
#define pop pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MAXN = 2001, MAXK = 1e6 + 1, INF = 1e9, M = 1e9 + 7;

// mt19937 rnd(0);

struct tr {
    int a, b;
    ll c;
    tr(): a(0), b(0), c(0){};
    tr(ll a, ll b, ll c): a(a), b(b), c(c){};
    bool operator< (const tr &oth) const {
        return c < oth.c;
    }
};

vector <ll> p(MAXN), cost(MAXN);
ll x[MAXN], y[MAXN], c[MAXN], k[MAXN];

inline ll dist(ll &i, ll &j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

ll get(ll a) {
    if (a == p[a]) {
        return a;
    }
    return p[a] = get(p[a]);
}

void join(ll a, ll b, ll d) {
    a = get(a);
    b = get(b);
    if (c[a] > c[b]) {
        swap(a, b);
    }
    p[b] = a;
    cost[a] += cost[b] - c[b] + d;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    iota(all(p), 0);
    for (ll i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> c[i];
        cost[i] = c[i];
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> k[i];
    }
    vector <ll> ans;
    vector <pair <ll, ll>> e;
    vector <tr> edg(n * n);
    int ptr = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (i != j) {
                edg[ptr++] = tr(i, j, dist(i, j) * (k[i] + k[j]));
            }
        }
    }
    sort(edg.begin(), edg.begin() + ptr);
    for (ll i = 0; edg[i].a != 0; ++i) {
        ll a = edg[i].a, b = edg[i].b;
        if (get(edg[i].a) == get(edg[i].b)) {
            continue;
        }
        if (cost[get(a)] + cost[get(b)] > cost[get(a)] + cost[get(b)] - max(c[get(a)], c[get(b)]) + dist(a, b) * (k[a] + k[b])) {
            join(a, b, dist(a, b) * (k[a] + k[b]));
            e.push({a, b});
        }
    }
    ll sum = 0;
    for (ll i = 1; i <= n; ++i) {
        if (get(i) == i) {
            ans.push(i);
            sum += cost[i];
        }
    }
    cout << sum << '\n' << ans.size() << '\n';
    for (auto i : ans) {
        cout << i << ' ';
    }
    cout << '\n' << e.size() << '\n';
    for (auto i : e) {
        cout << i.f << ' ' << i.s << '\n';
    }
	return 0;
}
