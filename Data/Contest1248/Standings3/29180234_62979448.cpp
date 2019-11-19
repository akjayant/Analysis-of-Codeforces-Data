#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int p[maxn],q[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d",&n);
        long long c1 = 0,c2 = 0,c3 = 0,c4 = 0;
        for(int i = 1;i <= n; ++i)
        {
            scanf("%d",&p[i]);
            if(p[i] & 1) c1++;
            else c2++;
        }
            
        scanf("%d",&m);
        for(int i = 1;i <= m; ++i)
        {
            scanf("%d",&q[i]);
            if(q[i] & 1) c3++;
            else c4++;
        }
        printf("%lld\n",c1 * c3 + c2 * c4);
    }
    return 0;
}