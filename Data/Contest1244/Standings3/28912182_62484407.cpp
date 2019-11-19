#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

#define sz(a) static_cast<int>((a).size())
#define f first
#define s second
#define els(v) for (auto &el : (v))


#ifdef KIRYA
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
void _dbg(const char* _s, T _h) {
    cerr << _s << " = " << _h << "\n";
}

template<typename T, typename... Ts>
void _dbg(const char*_s, T _h, Ts... _t) {
    int _b = 0;

    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++;

    cerr << " = " << _h << ",";
    _dbg(_s + 1, _t...);
}

const int64_t INF = static_cast<int64_t>(1e9) + 7;
const int64_t LINF = INF * INF;
const int MAXN = static_cast<int>(1e5) + 17;

vector<vector<int>> g(MAXN);
vector<vector<int>> c(3, vector<int>(MAXN));

bool is_path(int &start) {
    for (int i = 0; i < MAXN; ++i) {
        if (g[i].size() > 2) {
            return false;
        }
        if (g[i].size() == 1) {
            start = i;
        }
    }
    return true;
}

int64_t estim(int start, const vector<int> &perm, int cur, vector<int> &colors) {
    int64_t res = 0;
    int v = start;
    int prev = -1;
    do {
        res += c[perm[cur]][v];
        colors[v] = perm[cur];
        for (int ngb : g[v]) {
            if (ngb == prev) {
                continue;
            }
            prev = v;
            v = ngb;
            cur = perm[cur];
            break;
        }
    } while (g[v].size() == 2);
    colors[v] = perm[cur];
    return res + c[perm[cur]][v];
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[0][i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[1][i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[2][i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int start;
    if (!is_path(start)) {
        cout << "-1\n";
        return;
    }
    int64_t cnt = LINF;
    int cur;
    vector<int> best;
    vector<int> vec = {1,2,0};
    for (int i = 0; i < 3; ++i) {
        vector<int> cand(n);
        int64_t val = estim(start, vec, i, cand);
        if (val < cnt) {
            cnt = val;
            best = cand;
            cur = i;
        }
    }
    vec = {2,0,1};
    for (int i = 0; i < 3; ++i) {
        vector<int> cand(n);
        int64_t val = estim(start, vec, i, cand);
        if (val < cnt) {
            cnt = val;
            best = cand;
            cur = i;
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; ++i) {
        cout << 1 + best[i] << ' ';
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int q = 1;

    for (int i = 0; i < q; ++i) {
        solve();
    }
}
