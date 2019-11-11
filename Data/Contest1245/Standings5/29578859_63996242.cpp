#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rnd;
#define F first
#define S second
#define pb push_back


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) == 1) cout << "Finite\n";
        else cout << "Infinite\n";
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif // LOCAL
    return 0;
}
