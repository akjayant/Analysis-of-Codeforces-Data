#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long ans=0;
        int n,m;
        int n1=0,n2=0,m1=0,m2=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            int x;
            scanf("%d",&x);
            if(x&1)
                n1++;
            else
                n2++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;++i)
        {
            int x;
            scanf("%d",&x);
            if(x&1)
                m1++;
            else
                m2++;
        }
        ans=1ll*n2*m2+1ll*n1*m1;
        printf("%lld\n",ans);
    }
    return 0;
}
