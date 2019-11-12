#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MOD = 1e9+7;

ll N, M;

ll mypow(ll x, ll y)
{
    if(y==0) return 1;
    if(y%2) return mypow(x, y-1)*x%MOD;
    ll t=mypow(x, y/2);
    return t*t%MOD;
}

int main()
{
    int i, j;

    scanf("%lld%lld", &N, &M);

    ll t=mypow(2, M);
    t--;
    if(t<0) t+=MOD;
    printf("%lld", mypow(t, N));
}
