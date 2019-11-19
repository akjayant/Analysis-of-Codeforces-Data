#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #define watch(x) cout << (#x) << " is " << (x) << '\n'
  #define dashline() cout << "=============\n"
#else
  #define watch(x)
  #define dashline()
#endif

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int MX = 1e9;
const ll MX2 = 3e18;
const double pi = acos(-1);

const int MOD = 1e9+7;
const int sz = 262144;

ll mpow(ll a, ll b)
{
    ll ret = 1;
    do
    {
        if (b & 1) ret *= a;
        a *= a;
        a %= MOD; ret %= MOD;
    } while (b >>= 1);
    return ret;
}

ll d[100011]={2,2,4};
ll d2[100011]={1,1,2};
int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    ll n,m; cin>>n>>m;
    //if (n<m) swap(n,m);
    int i;

    for(i=3;i<=n;i++)
    {
        d[i]=d[i-1]+d[i-2];
        d[i]%=MOD;
    }
    for(i=3;i<=m;i++)
    {
        d2[i]=d2[i-1]+d2[i-2];
        d2[i]%=MOD;
    }

    ll v=0; int r=0;
//    watch(d[n]);
    cout<< (d[n]-2 + d2[m]*2) % MOD;

    return 0;
}

