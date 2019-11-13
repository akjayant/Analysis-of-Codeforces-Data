#include <bits/stdc++.h>

using namespace std;

int n;
int a[1010];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int ans=0;
        for(int i=n;i;i--)
        {
            ans=max(ans,min(n-i+1,a[i]));
        }
        printf("%d\n",ans);
    }
    
    return 0;
}