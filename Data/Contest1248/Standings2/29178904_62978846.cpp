#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int p;
        int n,m;
        scanf("%d",&n);
        int even1 = 0,odd1= 0;
        for(int i =0;i<n;i++)
        {
            scanf("%d",&p);
            if(p%2 ==0 )even1 ++;
            else odd1++;
        }
        scanf("%d",&m);
        int even2 = 0,odd2 = 0;
        for(int i =0;i<m;i++)
        {
            scanf("%d",&p);
            if(p%2 ==0 )even2 ++;
            else odd2++;
        }
        ll ans = 1ll * even1 * even2 + 1ll * odd1 * odd2;
        printf("%lld\n",ans);
    }
}