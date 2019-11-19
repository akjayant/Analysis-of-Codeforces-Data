#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

#define int long long
#define double long double
#define _ << ' ' <<
#define For(i,z) for(int32_t i=0;i<(z);i++)
#define sqr(a) ((a)*(a))

#define pii pair<int, int>
#define pdd pair<double, double>
#define f first
#define s second

template<typename T, typename K> inline void umax(T &a, K b) { a = max(a, (T)b); }
template<typename T, typename K> inline void umin(T &a, K b) { a = min(a, (T)b); }

const int32_t N = 1e5+10;
const int INF = 1e16 + 10;
const pii NINF = make_pair(INF, INF);
const double EPS = 1e-6;
const int II = 1e9;
const int MOD = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int fpos = INF, lpos = -INF;
        int n; cin >> n;
        For (i, n) {
            char c; cin >> c;
            if (c == '1') {
                umin(fpos, i);
                umax(lpos, i);
            }
        }
        if (fpos == INF) {
            cout << n << '\n'; continue;
        }

        int dst1 = lpos + 1, dst2 = n - fpos;
        cout << max(dst1, dst2) * 2LL << '\n';
    }
}
