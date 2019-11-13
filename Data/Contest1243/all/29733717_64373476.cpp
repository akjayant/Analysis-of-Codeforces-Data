#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
#define pb push_back
mt19937 rnd;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int a[n+1];
        for (int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+n+1);
        reverse(a+1, a+n+1);
        int ans = 0;
        for (int i=1; i<=n; i++) {
            ans = max(ans, min(i, a[i]));
        }
        cout << ans << "\n";
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL
    return 0;
}
