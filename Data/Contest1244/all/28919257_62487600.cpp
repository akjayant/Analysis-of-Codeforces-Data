#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

/*
typedef tree<int,
        null_type,
        less<int>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        set_t;*/

/*
    find_by_order()
    order_of_key()
*/

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define fast_work {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

const ll INF = 1e18+ 7, NMAX = 1e6 + 5, END = 1e5, MOD = 1000000007, N = 1005, LITTLE_INF = 1e9 + 5, LOG = 25;
const ld EPS = 1e-5;

vector<int> g[NMAX];
vector<ll> a[5];

vector<int> arr;

void create(int v, int pr) {
    arr.pb(v);
    for(int to : g[v]) if(to != pr) create(to, v);
}


ll f(int x, int y, int z) {
    ll ans = 0;

    for(int i = 0; i < arr.size(); ++i) {
        if(i % 3 == 0) ans += a[x][arr[i]];
        else if(i % 3 == 1) ans += a[y][arr[i]];
        else ans += a[z][arr[i]];
    }

    return ans;
}


int colors[NMAX];

void print(int x, int y, int z) {
    for(int i = 0; i < arr.size(); ++i) {
        if(i % 3 == 0) colors[arr[i]] = x;
        else if(i % 3 == 1) colors[arr[i]] = y;
        else colors[arr[i]] = z;
    }
}

int main() {
    fast_work;
    int n;
    cin >> n;

    a[1].resize(n + 1);
    a[2].resize(n + 1);
    a[3].resize(n + 1);

    for(int i = 1; i <= n; ++i) cin >> a[1][i];
    for(int i = 1; i <= n; ++i) cin >> a[2][i];
    for(int i = 1; i <= n; ++i) cin >> a[3][i];

    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    int start = 0;
    int cnt = 0;
    for(int i = 1; i <= n; ++i) if(g[i].size() == 1) {
        start = i;
        ++cnt;
    }

    if(cnt != 2) return cout << -1, 0;

    create(start, start);

    ll answer = min({f(1, 2, 3), f(1, 3, 2), f(2, 3, 1), f(2, 1, 3), f(3, 2, 1), f(3, 1, 2)});

    cout << answer << "\n";

    if(answer == f(1, 2, 3)) {
        print(1, 2, 3);
        for(int i = 1; i <= n; ++i) cout << colors[i] << " ";
        return 0;
    }

    if(answer == f(1, 3, 2)) {
        print(1, 3, 2);
        for(int i = 1; i <= n; ++i) cout << colors[i] << " ";
        return 0;
    }


    if(answer == f(2, 3, 1)) {
        print(2, 3, 1);
        for(int i = 1; i <= n; ++i) cout << colors[i] << " ";
        return 0;
    }

    if(answer == f(2, 1, 3)) {
        print(2, 1, 3);
        for(int i = 1; i <= n; ++i) cout << colors[i] << " ";
        return 0;
    }


    if(answer == f(3, 2, 1)) {
        print(3, 2, 1);
        for(int i = 1; i <= n; ++i) cout << colors[i] << " ";
        return 0;
    }

    if(answer == f(3, 1, 2)) {
        print(3, 1, 2);
        for(int i = 1; i <= n; ++i) cout << colors[i] << " ";
        return 0;
    }
}
