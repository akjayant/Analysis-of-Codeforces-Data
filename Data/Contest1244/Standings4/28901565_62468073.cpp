#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
const int maxn = 2e5 + 5;
signed main() {
    fast;
    srand(time(0));
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int fst = -1, lst = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                fst = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                lst = i;
                break;
            }
        }
        if (fst == -1) cout << n << '\n';
        else {
            int ans1 = 2 * (n - fst);
            int ans2 = 2 * lst + 2;
            cout << max(ans1, ans2) << '\n';
        }
    }
    return 0;
}
