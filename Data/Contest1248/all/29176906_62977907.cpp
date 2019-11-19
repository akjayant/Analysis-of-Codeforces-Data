#include<bits/stdc++.h>
using namespace std;
int T,n,p,q;
long long cnt[5],ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);cnt[0]=cnt[1]=ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&p),cnt[p%2]++;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&q),ans+=cnt[q%2];
        printf("%lld\n",ans);
    }
    return 0;
}