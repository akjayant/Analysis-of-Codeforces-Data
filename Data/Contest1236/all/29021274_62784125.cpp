#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define go_precise cout << fixed << setprecision(15);
mt19937 rnd;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        int a,b,c;
        cin >> a >> b >> c;
        int ans = min(b, c/2);
        b -= ans;
        c -= 2*ans;
        ans += min(a, b/2);
        cout << ans * 3 << "\n";
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
