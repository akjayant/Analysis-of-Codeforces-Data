#include<bits/stdc++.h>

#define cp(a, b) memcpy(a,b,sizeof(b))
#define sz(a) ((int)((a).size()))
#define pb emplace_back
#define sqr(x) ((x)*(x))
#define all(a) (a).begin(),(a).end()
#define mpr make_pair
#define LL long long
using namespace std;
const LL N = 5e6 + 100;
LL mod, inv6, dp[N];
map<LL, LL> mp;

inline LL S(LL a) {
    a %= mod;
    return (a + 1) * a / 2 % mod;
}

inline LL K(LL n) {
    return S(n) * S(n) % mod;
}


inline LL S2(LL a) {
    a %= mod;
    return a * (a + 1) % mod * (2 * a + 1) % mod * inv6 % mod;
}

LL D(LL n) {
    if (n < N) {
        return dp[n];
    }
    if (mp[n]) return mp[n];
    LL ans = K(n);
    for (LL i = 2, j; i <= n; i = j + 1) {
        j = n / (n / i);
        ans = ans + mod - (S2(j) - S2(i - 1) + mod) * D(n / i) % mod;
        ans %= mod;
    }
    return mp[n] = ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t, n;
    cin >> t;
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
                rr = n - i - 1;
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

