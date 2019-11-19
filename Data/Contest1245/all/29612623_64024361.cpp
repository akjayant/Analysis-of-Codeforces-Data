// 17:31

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

#define ON

#ifdef ON
#define debug(x) cerr << #x << " = " << (x) << endl
#else
#define debug(x)
#endif


template<typename T = int>
T input() {
    T res;
    cin >> res;
    return res;
}

template<typename It>
void input_seq(It begin, It end, istream &in = cin) {
    generate(begin, end, input<typename remove_reference<decltype(*begin)>::type>);
}

template<class It>
void output(It begin, It end, ostream &out = cerr) {
    while (begin != end) {
        out << *(begin++) << ' ';
    }
    out << endl;
}

//#define int ll

constexpr int N = 2001;
ll x[N], y[N];
int c[N], k[N], dsu[N];
pii mn[N];

int rt(int x) {
    if (dsu[x] == x) {
        return x;
    }
    return dsu[x] = rt(dsu[x]);
}

void merge(int x, int y) {
    int rx = rt(x);
    int ry = rt(y);
    if (rx == ry) {
        return;
    }
    if (rand() % 2) {
        swap(x, y);
    }
    dsu[x] = y;
    mn[y] = min(mn[y], mn[x]);
}

signed main() {
#ifdef ON
//    freopen("../in.txt", "r", stdin);
//    freopen("../out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = input();
    iota(dsu, dsu + n, 0);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        x[i] = input(), y[i] = input();
    }
    input_seq(c, c + n);
    for (int i = 0; i < n; ++i) {
        mn[i] = {c[i], i};
        ans += c[i];
    }
    input_seq(k, k + n);
    vector<tuple<ll, int, int>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            q.emplace_back((abs(x[i] - x[j]) + abs(y[i] - y[j])) * ll(k[i] + k[j]), i, j);
        }
    }
    sort(all(q));

    vector<pii> edg;
    for (auto[d, a, b] : q) {
        int ra = rt(a);
        int rb = rt(b);
        if (ra == rb) {
            continue;
        }
        if (max(mn[ra], mn[rb]).first >= d) {
            ans -= max(mn[ra], mn[rb]).first;
            ans += d;
            edg.emplace_back(a, b);
            merge(ra, rb);
        }
    }

    cout << ans << endl;
    set<int> used;
    for (int i = 0; i < n; ++i) {
        if (dsu[i] == i) {
            used.insert(mn[i].second);
        }
    }
    cout << sz(used) << endl;
    for (int i : used) {
        cout << i + 1 << ' ';
    }
    cout << endl;
    cout << sz(edg) << endl;
    for (auto[a, b] : edg) {
        cout << a + 1 << ' ' << b + 1 << endl;
    }
}
