#include<bits/stdc++.h>
using namespace std;
int n,t,a[1010];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,min(a[n-i],i));
        }
        printf("%d\n",ans);
    }
}