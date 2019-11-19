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
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,k;
        pii ans= {-1,-1};
        cin>>a>>b>>c>>d>>k;
        for (int i=1; i<=k;++i)
        {
            for (int j=1; j+i<=k; ++j)
            {
                if (i*d>=b&&j*c>=a)
                    ans= {j,i};
            }
        }
        if (ans.F==-1)
            cout<<-1<<"\n";
        else
            cout<<ans.F<<" "<<ans.S<<"\n";
    }
    return 0;
}
