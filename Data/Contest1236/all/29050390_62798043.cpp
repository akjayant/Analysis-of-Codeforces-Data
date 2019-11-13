
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

#define X first
#define Y second
#define A(x) get<0>(x)
#define B(x) get<1>(x)
#define C(x) get<2>(x)
#define D(x) get<3>(x)

mt19937 gen(228);

#ifdef DEBUG
#define dbg(x) cout << "[dbg " << __LINE__ << "] " << x << endl
#else
#define dbg(x) ((void)0)
#endif

constexpr ll MOD = 1'000'000'007;

int tbl [305][305];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    deque<int> pool;

    for (int i = 0; i < n*2; i++) {
        pool.push_back(i);
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                tbl[j][i] = cnt++;
            }
        } else {
            for (int j = n-1; j >= 0; j--) {
                tbl[j][i] = cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << tbl[i][j] + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
