#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+7;
int n;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int num0=0,num1=0;
        for(int i=1;i<=n;i++)
        {
            int temp;
            scanf("%d",&temp);
            if(temp%2==0)
                num0++;
            else
                num1++;
        }
        int m;
        scanf("%d",&m);
        ll ans=0;
        for(int i=1;i<=m;i++)
        {
            int temp;
            scanf("%d",&temp);
            if(temp%2==0)
                ans=ans+1ll*num0;
            else
                ans=ans+1ll*num1;
        }
        printf("%lld\n",ans);
    }
}

