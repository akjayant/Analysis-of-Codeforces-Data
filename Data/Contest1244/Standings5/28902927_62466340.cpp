#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=300050;



int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d,e;
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
        int ans1=(a+c-1)/c,ans2=(b+d-1)/d;
        if(ans1+ans2>e)puts("-1");
        else printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
