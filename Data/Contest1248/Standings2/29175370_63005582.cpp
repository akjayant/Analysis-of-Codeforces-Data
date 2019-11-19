#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define double long double

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

bool MULTI_TEST = false;


deque<int> q;

namespace Window {
    inline void clear() {
        q.clear();
    }

    inline void add(int x) {
        while (!q.empty() && q.back() > x)
            q.pop_back();
        q.push_back(x);
    }

    inline void remove(int x) {
        if (!q.empty() && q.front() == x)
            q.pop_front();
    }

    inline int min() {
        return q.front();
    }
};

int n;
const int MAXN = 1000;
int psum[MAXN];
int v[MAXN];

inline int solve2() {
    Window::clear();
    psum[0] = v[0];
    for (int i = 1; i < 2 * n - 1; i++) {
        psum[i] = psum[i - 1] + v[i];
    }
    int del = 0;
    int ans = 0;
    for (int i = 0; i < 2 * n - 1; i++) {
        if (i >= n - 1) {
            if (Window::min() >= del && psum[i] == del) {
                ans++;
            }
            Window::remove(psum[i - n + 1]);
            del += v[i - n + 1];
        }
        Window::add(psum[i]);
    }
    return ans;
}

void solve() {
    cin >> n;
    if (n % 2 == 1) {
        cout << "0\n1 1";
        return;
    }
    string s;
    cin >> s;

    vector<int> ax, bx;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            ax.push_back(i);
        } else {
            bx.push_back(i);
        }
    }

    if (ax.size() != bx.size()) {
        cout << "0\n1 1";
        return;
    }

    for (int k = 0; k < 2 * n - 1; k++) {
        v[k] = (s[k % n] == '(' ? 1 : -1);
    }
    int ans = solve2();
    int bi = 0, bj = 0;
    for (int i : ax) {
        for (int j : bx) {
            swap(s[i], s[j]);
            for (int k = 0; k < 2 * n - 1; k++) {
                v[k] = (s[k % n] == '(' ? 1 : -1);
            }
            int t = solve2();
            if (t > ans) {
                ans = t;
                bi = i;
                bj = j;
            }
            swap(s[i], s[j]);
        }
    }
    cout << ans << endl;
    cout << bi + 1 << ' ' << bj + 1;
}

signed main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    if (MULTI_TEST) {
        cin >> t;
    }
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
