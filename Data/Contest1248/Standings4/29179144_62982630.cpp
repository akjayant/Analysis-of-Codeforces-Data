#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10],b[10];
int n,m;
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        ll ans=0;
        a[0]=a[1]=b[0]=b[1]=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a[x%2]++;
        }
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            b[x%2]++;
        }
        ans=a[0]*b[0]+a[1]*b[1];
        printf("%lld\n",ans);
    }
}
