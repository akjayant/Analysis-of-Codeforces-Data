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
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;
        int ans = (a+c-1)/c + (b+d-1)/d;
        if (ans <= k) cout << (a+c-1)/c << " " << (b+d-1)/d << "\n";
        else cout << -1 << "\n";
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
