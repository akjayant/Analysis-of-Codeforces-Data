#include<iostream>
#include<vector>
#include<map>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#define BUG puts("no bug")
#define sci(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define REP(a,b,c) for(ll a=b;a<=c;a++)
#define PER(a,b,c) for(ll a=b;a>=c;a--)
#define ll long long
#define lb(a) (a&(-a))
using namespace std;
const ll MAXN=1e6+5;
ll n,m,t;
ll num[MAXN];
char s[MAXN];
int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    for(ll i=0;i<=min(1000000LL,a);i++)
    {
        ll shang=(b-d*i)/c;
        if(shang*c+i*d==b)
        if(i+shang<=a&&shang>=0)
        {
            cout<<shang<<' '<<i<<' '<<a-i-shang;
            return 0;
        }
    }
    cout<<-1;
}
