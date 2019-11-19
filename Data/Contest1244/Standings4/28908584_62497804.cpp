#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define F first
#define S second
#define lp(i, a, b) for (int i=a;i<=(int)b;++i)
#define lp2(i, a, b) for (ll i=a;i>=b;--i)
#define f(x) return cout<<x<<"\n",0
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(c) c.begin(),c.end()
#define allr(c) c.rbegin(),c.rend()
#define p(x) cout<<#x<<" = { "<<x<<" } \n"
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define FAST ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define clr(c, x) memset(c,x,sizeof(c));
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
const int N = (int) 1e5 + 5, INF = 0x3f3f3f3f, ALPHA = 26;
const ll mod = 998244353;

int main()
{
#ifdef ONLINE_JUDGE
    FAST;
#endif
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    ll x=p/w;
    for (ll q=x; q>=x-(int)8e6&&q>=0; --q)
    {
        if (((p-(q*w))%d)==0)
        {
            ll x1=q;
            ll y1=(p-(q*w))/d;
            if (x1+y1<=n)
            {
                cout<<x1<<" "<<y1<<" "<<n-(x1+y1)<<"\n";
                return 0;
            }
        }
    }
    f(-1);
    return 0;
}
