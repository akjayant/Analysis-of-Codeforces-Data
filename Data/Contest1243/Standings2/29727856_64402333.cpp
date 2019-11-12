#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(1337);

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef LOCAL
    FILE *f = freopen("input", "r", stdin);\
    freopen("output", "w", stdout);
#endif
    const int cnt = 'z' - 'a' + 1;

    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;

        /*
        int n = (rnd() % 5) + 1;

        string s, t;
        s.resize(n);
        t.resize(n);

        for (int i = 0; i < n; ++i)
            s[i] = t[i] = (rnd() % 26) + 'a';
        shuffle(t.begin(), t.end(), rnd);

         */

        int cntSymb[cnt];
        memset(cntSymb, 0, sizeof(cntSymb));
        for (int i = 0; i < n; ++i)
            cntSymb[s[i] - 'a']++, cntSymb[t[i] - 'a']++;
        bool ok = true;
        for (int i = 0; i < cnt; ++i)
            ok &= (cntSymb[i] % 2) == 0;

        if (ok) {
            cout << "Yes\n";

            vector<pair<int, int>> res;
            res.reserve(2 * n);

            for (int i = 0; i < n; ++i) {
                if (s[i] != t[i]) {
                    for (int j = i + 1; j < n; ++j) {
                        if (s[j] == s[i]) {
                            res.push_back({j, i});
                            swap(s[j], t[i]);
                            break;
                        } else if (s[j] == t[i]) {
                            res.push_back({j, n - 1});
                            swap(s[j], t[n - 1]);
                            res.push_back({i, n - 1});
                            swap(s[i], t[n - 1]);
                            break;
                        } else if (t[j] == t[i]) {
                            res.push_back({i, j});
                            swap(s[i], t[j]);
                            break;
                        } else if (t[j] == s[i]) {
                            res.push_back({n - 1, j});
                            swap(s[n - 1], t[j]);
                            res.push_back({n - 1, i});
                            swap(s[n - 1], t[i]);
                            break;
                        }
                    }

                    //if (s[i] != t[i])
                        //return -1;
                }
            }

            cout << res.size() << "\n";
            for (auto[x, y]: res) {
                cout << x + 1 << " " << y + 1 << "\n";
            }

        } else {
            cout << "No\n";
        }
    }

    return 0;
}