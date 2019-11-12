#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double rl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define pb push_back
#define mp make_pair

#if 1
#define dbg(x) cerr << #x << ": " << (x) << endl;
#else
#define dbg(x)
#endif // 1
ll n, m;

const ll MOD=1000*1000*1000+7LL;

ll powmod(ll A, ll N)
{
    A%=MOD;
    ll R=1;
    while(N!=0)
    {
        if(N&1) R=(R*A)%MOD;
        A=(A*A)%MOD;
        N>>=1;
    }
    return R;
}

int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;

    ll tmp=(powmod(2, m)-1+MOD)%MOD;
    ll res=powmod(tmp, n);

    cout << res;

    return 0;
}
