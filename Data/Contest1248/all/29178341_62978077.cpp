#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define forn(i, n) for(int i=0;i<(n);++i)
#define clr(ar, val) memset(ar, val, sizeof(ar))

using namespace std;

typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<ld, ld> point;

const int MAXN = int(2e5) + 200;
const int INF = int(1e9) + 10;
const long long LINF = 1LL * INF * INF;
const int md = int(1e9) + 7;
const ld eps = 1e-9;
const ld PI = 3.1415926535897932384626433832795l;

int n, m, tt;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> tt;
    for (int it = 0; it < tt; ++it) {
        cin >> n;
        vector<long long> a(2), b(2);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            ++a[x & 1];
        }
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            ++b[x & 1];
        }
        long long ans = a[0] * b[0] + a[1] * b[1];
        cout << ans << endl;
    }
    return 0;
}
