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
    ll ans = 1;
    do
    {
        if (b & 1) ans *= a;
        a *= a;
        a %= MOD; ans %= MOD;
    } while (b >>= 1);
    return ans;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);

    int n,m; cin>>n>>m;
    ll ans=mpow(2,m);
    ans--;
    ans=mpow(ans,n);
    cout<<ans;
    return 0;
}

