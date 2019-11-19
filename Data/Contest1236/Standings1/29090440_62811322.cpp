#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 555;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    static ll a[maxn], n, m;
    map<int, int> mp;
    auto gao = [&]() -> ll {
        ll o = 0, ans = 0;
        mp.clear();
        for (int i = 1; i <= n; i++) {
            mp[i] = 1;
        }
        for (int i = 1; i <= m; i++, o++) {
            auto ptr = mp.find(a[i] - 1 - o);
            if (ptr != mp.end()) {
                auto res = *ptr;
                mp.erase(ptr);
                mp[res.first - 1] += res.second;
            }
        }
        for (const auto &[a, b] : mp) {
            ans += min(a + o + 1, n) * b;
        }
        return ans - 1LL * n * (n - 1) / 2;
    };
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    if (n == 1 && m > 0) {
        cout << 0 << endl;
    } else {
        ll ans1 = gao();
        for (int i = 1; i <= m; i++) {
            a[i] = n - a[i] + 1;
        }
        cout << ans1 + gao() - n << endl;
    }
    return 0;
}
