#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

using ll = long long;

seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(
    	chrono::high_resolution_clock::now().
    	time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) random_device{}(),
    (uint64_t) 17
};

mt19937 rd{seq};

ll const mod = 1e9 + 7;

ll fexp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b&1) ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    ll p = fexp(2, m) - 1;
    if (p < 0) p += mod;

    ll ans = fexp(p, n);
    cout << ans << "\n";
}