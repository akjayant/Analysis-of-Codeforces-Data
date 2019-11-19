#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define go_precise cout << fixed << setprecision(15);
mt19937 rnd;

bool a[1010];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            char c;
            cin >> c;
            if (c=='1') a[i] = 1;
            else a[i] = 0;
        }
        int l = -1, r = -1;
        for (int i=1; i<=n; i++) {
            if (a[i]) {
                l = i;
                break;
            }
        }
        for (int i=n; i>=1; i--) {
            if (a[i]) {
                r = i;
                break;
            }
        }
        if (l==-1) {
            cout << n << "\n";
            continue;
        }
        cout << 2 * max(max(l, n - l + 1), max(r, n - r + 1)) << "\n";
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
