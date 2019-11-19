#include<bits/stdc++.h>

#define LL long long
using namespace std;
const long long MAXN = 5e6 + 100;
bool flag[MAXN];
long long prime[MAXN], phi[MAXN], mu[MAXN];
long long mod;
long long inv6;
long long dp[MAXN];
map<LL, LL> mp;

long long qpow(long long a, long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void init() {
    long long tot = 0;
    phi[1] = mu[1] = 1;
    for (long long i = 2; i < MAXN; i++) {
        dp[i] = -1;
        if (!flag[i]) {
            prime[++tot] = i;
            mu[i] = -1;
            phi[i] = i - 1;
        }
        for (long long j = 1; j <= tot && prime[j] * i < MAXN; j++) {
            flag[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            mu[i * prime[j]] = -mu[i];
        }
    }
    inv6 = qpow(6, mod - 2);
    dp[0] = 0;
    for (long long i = 1; i < MAXN; i++) {
        dp[i] = (dp[i - 1] + i * i % mod * phi[i] % mod) % mod;
    }
}

inline long long S(long long a) {
    a %= mod;
    return (a + 1) * a / 2 % mod;
}

inline long long K(long long n) {
    return S(n) * S(n) % mod;
}


inline long long S2(long long a) {
    a %= mod;
    return a * (a + 1) % mod * (2 * a + 1) % mod * inv6 % mod;
}


long long D(long long n) {
    if (n < MAXN) {
        return dp[n];
    }
    if (mp[n]) return mp[n];
    long long ans = K(n);
    for (long long i = 2, j; i <= n; i = j + 1) {
        j = n / (n / i);
        ans = ans + mod - (S2(j) - S2(i - 1) + mod) * D(n / i) % mod;
        ans %= mod;
    }
    return mp[n] = ans;
}

long long solve(long long n) {
    long long ans = 0;
    for (long long i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        ans = ans + (D(j) - D(i - 1) + mod) * K(n / i) % mod;
        ans %= mod;
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int n;
    string s;
    while (t--) {
        cin >> n;
        cin >> s;
        int lr = -1, rr = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                lr = i;
                break;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') {
                rr = n - i-1;
                break;
            }
        }
        if (lr == rr && lr == -1) {
            cout << n << endl;
        } else {
            cout << 2 * (n - min(lr, rr)) << endl;
        }
    }
    return 0;
}