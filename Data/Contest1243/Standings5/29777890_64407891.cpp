// Nguyen Anh Tu
#include <bits/stdc++.h>
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define FORD(x,a,b) for(int x=a;x>=b;x--)
#define maxn 100005
#define maxc 1000000007
#define MOD 1000000007
#define reset(x) memset(x,0,sizeof(x))
#define task ""
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
#define remain(a,b) (a+b >= MOD) ? (a+b - MOD) : (a+b)
#define itn int
using namespace std;
ll n;
vector<ll> ans;
ll res;
int main()
{
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif
    cin >> n;
    if(n == 1) return cout << 1,0;
    res = n;
    for(int i=sqrt(n); i>=2; i--)
    if(n % i == 0)
    {
        ans.pb(i);
        res = __gcd(res,1ll*i);
        res = __gcd(res,n/i);
    }
    cout << res;
    for(int i=1; i<=100000; i++) res ++;
    return 0;
}
