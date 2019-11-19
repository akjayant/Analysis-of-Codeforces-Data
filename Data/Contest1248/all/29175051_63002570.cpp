// Author : Apaar
// Built  : 20-10-2019 16:07:35

#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

const int mod = 1000000007;
int fact[N], invfact[N];
inline int add(int x, int y) { x += y; return x % mod;}
inline int sub(int x, int y) { x -= y; x %= mod; x += mod; return x % mod;}
inline int mul(int x, int y) { return  (x * y) % mod;}
inline int powr(int a, int b) {
    int x = 1 % mod;
    while (b) {
        if (b & 1) x = mul(x, a);
        a = mul(a, a);
        b >>= 1;
    }
    return x;
}
inline int inv(int a) { return powr(a, mod - 2);}
void pre() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < N; i++) fact[i] = mul(i, fact[i - 1]);
    invfact[N - 1] = inv(fact[N - 1]);
    for (int i = N - 2; i >= 1; i--) invfact[i] = mul(invfact[i + 1], i + 1);
    assert(invfact[1] == 1);
}

inline int C(int n, int k) {
    if (n < k || k < 0) return 0;
    return mul(fact[n], mul(invfact[k], invfact[n - k]));
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        int a[N];
        a[0] = a[1] = 1;
        for (i = 2; i < N; i++) {
            a[i] = a[i - 1] + a[i - 2];
            a[i] %= mod;
        }
        ans = 2 * (a[n] + a[m]); ans %= mod;
        ans -= 2; ans += mod; ans %= mod;
        cout << ans;
    }
}