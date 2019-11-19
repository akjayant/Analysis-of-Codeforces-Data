#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

// 0 1 2 3 4 5
// 1 1 2 3 5 8


ll solve(ll N, ll M) {
    int ans = 0;
    for(int i = 0; i < 1 << (N * M); i++) {
        vector<vector<int>> B(N, vector<int>(M));
        for(int j = 0; j < N * M; j++) {
            if (i >> j & 1) {
                B[j / M][j % M] = 1;
            }
        }
        bool ok = true;
        for(int y = 0; y < N; y++) {
            for(int x = 0; x < M; x++) {
                int cnt = 0;
                int dx[] = {1, 0, -1, 0};
                int dy[] = {0, -1, 0, 1};
                for(int k = 0; k < 4; k++) {
                    int tx = x + dx[k];
                    int ty = y + dy[k];
                    if (tx < 0 || tx >= M || ty < 0 || ty >= N) continue;
                    if (B[ty][tx] == B[y][x]) cnt++; 
                }
                if (cnt > 1) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            ans++;
            for (int y = 0; y < N; y++) {
                for (int x = 0; x < M; x++) {
                    cout << B[y][x] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    return ans;
}

void solve() {
    const int mod = 1e9 + 7;
    vector<ll> fib(200001);
    fib[0] = 1; fib[1] = 1;
    for (int i = 2; i <= 200000; i++) {
        fib[i] = fib[i - 2] + fib[i - 1];
        fib[i] %= mod;
    }

    int N, M;
    cin >> N >> M;
    //cout << solve(N, M) << endl;
    if (N == 1 && M == 1) {
        cout << 2 << endl;
        return;
    } else if (N == 1 || M == 1) {
        if (N == 1) cout << fib[M] * 2 % mod << endl;
        else if (M == 1) cout << fib[N] * 2 % mod << endl;
        return;
    }
    cout << ((2 * fib[N] % mod + 2 * fib[M] % mod) % mod + mod - 2) % mod << endl;

}

int main() {
    #ifdef LOCAL_ENV
    cin.exceptions(ios::failbit);
    #endif
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    
    solve();
}