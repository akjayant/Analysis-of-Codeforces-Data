#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define g 9.8
#define m(a,b) make_pair(a,b)
const ll mod = 1e9+7;
ull base = 131;
const int w = 1e5+5;
int n,m,k;
int main()
{
    int i,j,t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        ll x=0,y=0;
        for(i=1;i<=n;i++)
        {
            ll u;
            scanf("%lld",&u);
            if(u%2==0)
                x++;
            else
                y++;
        }
        ll xx=0,yy=0;
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            ll u;
            scanf("%lld",&u);
            if(u%2==0)
                xx++;
            else
                yy++;
        }
        ll ans=0;
        ans+=xx*x+yy*y;
        printf("%lld\n",ans);
    }
    return 0;
}
