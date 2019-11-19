#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<lu> vu;
typedef vector<v> vv;
typedef vector<vu> vvu;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<set<ll>> vsll;
typedef set<pair<ll, ll>> spll;
typedef vector<spll> vspll;
typedef vector<pll> vpll;
typedef pair<lu, lu> puu;
typedef vector<puu> vpuu;
const ll MOD = 1000000007;
const ld PI = 2 * acos(0.0);
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
#define round(x, y) ((x + y - 1) / y)
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
    if (y > x)     \
        x = y;
#define amin(x, y) \
    if (y < x)     \
        x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define sz(x) (ll) x.size()
#define len(x) (ll) x.length()
#define sq(x) ((x) * (x))
#define cb(x) ((x) * (x) * (x))
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yesno(f) \
    if (f)       \
        yes else no;
#define noo \
    { no return; }

#define all(x) x.begin(), x.end()

v ga(ll n, bool oneIndexed = false) {
    v a;
    if (oneIndexed)
        a.push_back(0ll);
    for (ll i = 0; i < n; i++) {
        ll p;
        // scanf("%lld", &p);
        cin >> p;
        a.push_back(p);
    }
    return move(a);
}

vs gas(lu n, bool oneIndexed = false) {
    vs a;
    if (oneIndexed)
        a.push_back("");
    for (lu i = 0; i < n; i++) {
        string p;
        // scanf("%lu", &p);
        cin >> p;
        a.push_back(p);
    }
    return move(a);
}

template <typename T, typename A>
void pa(vector<T, A> const &a, ll begin = 0, ll end = -1) {
    if (end == -1)
        end = sz(a) - 1;
    for (ll i = begin; i <= end; i++) {
        // printf("%lu ", a[i]);
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename T, typename A>
void papair(vector<T, A> const &a, ll begin = 0, ll end = -1) {
    if (end == -1)
        end = sz(a) - 1;
    for (ll i = begin; i <= end; i++) {
        // printf("%lu ", a[i]);
        cout << a[i].first << " " << a[i].second << endl;
    }
}

#define MAX (ll)1e5 + 10
v parents(MAX);
v depths(MAX);
vv costs(3, v(MAX, 0));
v currcolorass(MAX, 0);

map<ll, ll> fixes;
ll dfs(vv &adjList, ll curr, ll prev, ll ca, ll cb) {
    ll currcolor = (3 - ca - cb), cost = costs[currcolor][curr];
    currcolorass[curr] = currcolor;

    for (auto neigh : adjList[curr]) {
        if (neigh == prev)
            continue;
        cost += dfs(adjList, neigh, curr, cb, currcolor);
    }

    return cost;
}

void solve() {
    ll n, m;
    cin >> n;
    for (ll j = 0; j < 3; j++) {
        for (ll i = 1; i <= n; i++) {
            cin >> costs[j][i];
        }
    }
    m = n - 1;
    v deg(n + 1, 0);
    vv adjList(n + 1, v(0));
    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    ll endpoint = 0;
    for (ll i = 1; i <= n; i++) {
        if (deg[i] >= 3) {
            cout << -1;
            return;
        }
        if (deg[i] == 1)
            endpoint = i;
    }

    // linear chain
    // fix first two, rest automatic
    ll costa = 1e15;
    v ass;

    for (ll c1 = 0; c1 < 3; c1++) {
        for (ll c2 = 0; c2 < 3; c2++) {
            if (c1 == c2)
                continue;
            ll cost = 0, ca = c1, cb = c2;
            ll sguy = adjList[endpoint][0];

            fixes[endpoint] = ca;
            fixes[sguy] = cb;

            ll thirdguy = (adjList[sguy][0] == endpoint) ? adjList[sguy][1]
                                                         : adjList[sguy][0];

            cost = costs[ca][endpoint] + costs[cb][sguy] +
                   dfs(adjList, thirdguy, sguy, ca, cb);

            currcolorass[endpoint] = ca;
            currcolorass[sguy] = cb;
            if (costa > cost) {
                costa = cost;
                ass = currcolorass;
            }
        }
    }

    cout << costa << endl;
    for (auto &x : ass)
        x = x + 1;
    pa(ass, 1, n);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}