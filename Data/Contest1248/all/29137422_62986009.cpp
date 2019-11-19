#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;

ll n,t,m,x,y;
ll ans;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(register int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            if((a%2+2)%2==0) x++;
            else y++;
        }
        scanf("%lld",&m);
        for(register int i=1;i<=m;i++)
        {
            int a;
            scanf("%d",&a);
            if((a%2+2)%2==0) ans+=x;
            else ans+=y;
        }
        printf("%lld\n",ans);
        ans=0;x=0;y=0;
    }
    return 0;   
}