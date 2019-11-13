#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define x first
#define y second
#define debug(x) cerr << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()

typedef long long LL;
typedef pair <LL, LL> PLL;

const LL maxn = 100010;
const LL mod = 1000000007;
const LL inf = 2000000000;
const LL inf64 = inf*inf;

LL bigmod(LL num, LL exp)
{
    if (exp == 0) return 1;
    LL ans = bigmod(num, exp/2);
    ans = ans * ans % mod;

    if (exp & 1) ans = ans * num % mod;
    return ans;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    LL n, m;
    cin >> n >> m;

    cout << bigmod((bigmod(2, m)-1+mod)%mod, n);

    return 0;
}
