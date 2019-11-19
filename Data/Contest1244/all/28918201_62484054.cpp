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

    int n, p, w, d;
    cin >> n >> p >> w >> d;

    int mx = p / w;
    int ans = 0;
    for (int win = mx; win + N > mx && win >= 0; win--) {
        int ost = p - win * w;
        int draw = ost / d;
        if (draw + win > n) continue;

        if (win * w + draw * d == p) {
            cout << win _ draw _ n - win - draw << '\n';
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
