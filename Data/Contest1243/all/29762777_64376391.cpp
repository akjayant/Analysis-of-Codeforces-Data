#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const ll MAXN = 2e3 + 10;
const ll mod = 998244353;
const ll inf = 1e18;
const ll mo = 1e9+7;

int vis[MAXN];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,x,ans;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            vis[x] ++;
        }
        for(int i=1000;i>=1;i--)
        {
            int tot = 0;
            for(int j=i;j<=1000;j++)
                tot += vis[j];
            if(tot >= i)
            {
                ans = i;
                break;
            }
        }
        printf("%d\n",ans);
    }
}
