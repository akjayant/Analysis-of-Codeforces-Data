#include <bits/stdc++.h>
#define f first
#define s second
#define push push_back
#define pop pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MAXN = 3000, MAXK = 1e6 + 1, INF = 1e9, M = 1e9 + 7;

// mt19937 rnd(0);

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (;t;--t) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        vector <char> ans(n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            char p;
            cin >> p;
            if (p == 'R') {
                ans[i] = (b? 'P': '$');
                cnt += (b > 0);
                b = max(0, b - 1);
            } else if (p == 'P') {
                ans[i] = (c? 'S': '$');
                cnt += (c > 0);
                c = max(0, c - 1);
            } else {
                ans[i] = (a? 'R': '$');
                cnt += (a > 0);
                a = max(0, a - 1);
            }
        }
        cout << (cnt * 2 >= n? "YeS\n": "nO\n");
        if (cnt * 2 >= n) {
            for (char p: ans) {
                if (p != '$') {
                    cout << p;
                } else if (a) {
                    --a;
                    cout << 'R';
                } else if (b) {
                    --b;
                    cout << 'P';
                } else {
                    --c;
                    cout << 'S';
                }
            }
            cout << '\n';
        }
    }
	return 0;
}
