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

template <class it>
void cycle_shift(it begin, it end, int k) {
    reverse(begin, end);
    reverse(end - k, end);
    reverse(begin, end - k);
}

int count(string s) {
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = 0;
    int mn = INF, mn_i = -1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + (s[i - 1] == '(') - (s[i - 1] == ')');
        if (dp[i] < mn) {
            mn = dp[i];
            mn_i = i;
        }
    }
    int cnt = 0;
    cycle_shift(s.begin(), s.end(), mn_i);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + (s[i - 1] == '(') - (s[i - 1] == ')');
        if (dp[i] < 0) {
            return 0;
        }
        if (dp[i] == 0) {
            ++cnt;
        }
    }
    if (dp[n] != 0) {
        return 0;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bl = 0, br = 0;
    int cnt = count(s);
    for (int l = 0; l < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            string cp = s;
            swap(cp[l], cp[r]);
            int res = count(std::move(cp));
            if (res > cnt) {
                cnt = res;
                bl = l;
                br = r;
            }
        }
    }
    cout << cnt << '\n' << bl + 1 << ' ' << br + 1 << '\n';
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
