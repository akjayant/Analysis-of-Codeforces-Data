#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)
#define mes(x, k) memset(x, k, sizeof(x))
#define bug() printf("LINE: %d.\n", __LINE__)
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

ll n, m;
ll ksm(ll a, ll ni) {
    ll r = 1;
    while (ni) {
        if (ni & 1) r = r * a % mod;
        a = a * a % mod;
        ni >>= 1;
    }
    return r;
}

int main() {
    cin >> m >> n;
    cout << ksm((ksm(2, n) - 1 + mod) % mod, m);
}