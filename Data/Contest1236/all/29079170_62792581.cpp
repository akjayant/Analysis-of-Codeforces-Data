#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;scanf("%d",&T);
    int a,b,c;
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int ans=min(b,c/2)*3;
        b-=min(b,c/2);
        ans+=min(a,b/2)*3;
        printf("%d\n",ans);
    }
}
