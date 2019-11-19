#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =2e5+7;
int n,m,x;
ll a1,a2,b1,b2;
ll ans;
int main()
{
    int tt;scanf("%d",&tt);
    while(tt--)
    {
        a1=a2=b1=b2=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            if(x<0)x=-x;
            if(x&1)a1++;
            else a2++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++){
            scanf("%d",&x);
            if(x<0)x=-x;
            if(x&1)b1++;
            else b2++;
        }

        ans=a1*b1+a2*b2;
        printf("%lld\n",ans);
    }
}
