
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

#define X first
#define Y second
#define A(x) get<0>(x)
#define B(x) get<1>(x)
#define C(x) get<2>(x)
#define D(x) get<3>(x)

mt19937 gen(228);

#ifdef DEBUG
#define dbg(x) cout << "[dbg " << __LINE__ << "] " << x << endl
#else
#define dbg(x) ((void)0)
#endif

int mapp [128];
char unmap [3];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    mapp['R'] = 0;
    mapp['P'] = 1;
    mapp['S'] = 2;
    unmap[0] = 'R';
    unmap[1] = 'P';
    unmap[2] = 'S';

    while (t--) {
        int n, cnt[3];
        cin >> n >> cnt[0] >> cnt[1] >> cnt[2];
        string s;
        cin >> s;

        vector<int> ans(n);
        fill(all(ans), -1);
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (cnt[(mapp[s[i]] + 1) % 3] > 0) {
                ans[i] = (mapp[s[i]] + 1) % 3;
                cnt[(mapp[s[i]] + 1) % 3]--;
                total++;
            }
        }

        dbg(total);

        if (total*2 + 1 > n) {
            cout << "YES\n";
            for (auto v : ans) {
                if (v >= 0) {
                    cout << unmap[v];
                } else {
                    for (int i = 0; i < 3; i++) {
                        if (cnt[i] > 0) {
                            cnt[i]--;
                            cout << unmap[i];
                            break;
                        }
                    }
                }
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
