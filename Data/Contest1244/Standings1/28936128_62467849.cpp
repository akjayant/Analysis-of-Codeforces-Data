#include <bits/stdc++.h>
using namespace std;

int a,b,c,d,k;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        int ans1=0,ans2=0;
        ans1=a/c;
        if(a%c!=0)
            ans1++;
        ans2=b/d;
        if(b%d!=0)
            ans2++;
        if(ans1+ans2>k)
            printf("-1\n");
        else
        {
            printf("%d %d\n",ans1,ans2);
        }
    }
    return 0;
}