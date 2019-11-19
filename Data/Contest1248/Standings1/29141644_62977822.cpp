#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=4e5+10;
const int MOD=1e9+7;



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        ll ji1=0,ji2=0,ou1=0,ou2=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            if(a&1)ji1++;
            else ou1++;
        }
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            int a;
            scanf("%d",&a);
            if(a&1)ji2++;
            else ou2++;
        }
        printf("%lld\n",ji1*ji2+ou1*ou2);
    }
    return 0;
}
