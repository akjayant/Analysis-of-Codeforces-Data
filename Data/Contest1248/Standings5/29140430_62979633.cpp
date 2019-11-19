#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 1e5 + 10;

int a[MAXN];

int main()
{
    int p;
    cin>>p;
    while (p--)
    {
        int n,m;
        ll eve1 = 0,odd1 = 0,eve2 = 0,odd2 = 0;
        scanf("%d",&n);
        for (int i = 1,u;i<=n;i++)
        {
            scanf("%d",&u);
            if (u % 2 == 0) eve1++;
            else odd1++;
        }
        scanf("%d",&m);
        for (int i = 1,u;i<=m;i++)
        {
            scanf("%d",&u);
            if (u % 2 == 0) eve2++;
            else odd2++;
        }
        ll cnt = eve1 * eve2 + odd1 * odd2;
        printf("%lld\n",cnt);
    }
    return 0;
}