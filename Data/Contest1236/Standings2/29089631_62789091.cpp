#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define pb push_back
#define mp make_pair
#define LL long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e6 + 5, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

LL qpow(LL a, LL b) {
    LL ret = 1;
    for(;b;b >>= 1, a = a * a % MOD) 
        if(b & 1) ret = ret * a % MOD;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    LL n, m;
    cin >> n >> m;
    LL ans = (qpow(2, m) - 1 + MOD) % MOD;
    ans = qpow(ans, n);
    cout << ans << endl;
    return 0;
}