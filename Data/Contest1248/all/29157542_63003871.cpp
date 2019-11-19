#include<iostream>
#include<vector>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define arep(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

template<typename T>
class Combination {
    private:
        T mod;
        vector<T> factorial, inv_factorial, inv;
    public:
        Combination(int max_number, T _mod):
        mod(_mod), factorial(max_number + 1), inv_factorial(max_number + 1), inv(max_number + 1) {
            factorial[0] = factorial[1] = 1;
            inv_factorial[0] = inv_factorial[1] = 1;
            inv[1] = 1;
            for (int i = 2; i <= max_number; i++) {
                factorial[i] = (factorial[i - 1] * i) % mod;
                inv[i] = mod - inv[mod % i] * (mod / i) % mod;
                inv_factorial[i] = inv_factorial[i - 1] * inv[i] % mod;
            }
        }
        T calc(int n, int k) {
            if (n < k) return 0;
            if (n < 0 || k < 0) return 0;
            return factorial[n] * (inv_factorial[k] * inv_factorial[n - k] % mod) % mod;
        }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    Combination<ll> comb(max(N, M), MOD);
    ll ans = 0;
    rep(i, 0, N + 1) {
        if ((N - i) % 2) continue;
        ll x = i, y = (N - i) / 2;
        ans = (ans + comb.calc(x + y, x)) % MOD;
    }
    rep(i, 0, M + 1) {
        if ((M - i) % 2) continue;
        ll x = i, y = (M - i) / 2;
        ans = (ans + comb.calc(x + y, x)) % MOD;
    }
    ans = (ans - 1 + MOD) % MOD;
    ans = (ans * 2) % MOD;
    cout << ans << endl;
    return 0;
}