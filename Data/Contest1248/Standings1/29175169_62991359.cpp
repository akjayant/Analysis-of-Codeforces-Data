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
const int MAXN = static_cast<int>(1e6) + 17;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(4, 0)), p(m, vector<int>(4, 0));
    d[0][0] = d[0][1] = p[0][0] = p[0][1] = 1;
    for (int i = 1; i < n; ++i) {
        d[i][0] = (d[i - 1][1] + d[i - 1][3]) % INF;
        d[i][1] = (d[i - 1][0] + d[i - 1][2]) % INF;
        d[i][2] = d[i - 1][0];
        d[i][3] = d[i - 1][1];
    }
    for (int i = 1; i < m; ++i) {
        p[i][0] = (p[i - 1][1] + p[i - 1][3]) % INF;
        p[i][1] = (p[i - 1][0] + p[i - 1][2]) % INF;
        p[i][2] = p[i - 1][0];
        p[i][3] = p[i - 1][1];
    }
    int ans = -2;
    for (int i = 0; i < 4; ++i) {
        ans = (ans + d[n - 1][i]) % INF;
    }
    for (int i = 0; i < 4; ++i) {
        ans = (ans + p[m - 1][i]) % INF;
    }
    
    cout << ans << '\n';;
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
