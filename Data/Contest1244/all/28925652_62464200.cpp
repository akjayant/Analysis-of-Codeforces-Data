#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m,T,ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c,d,k;
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        int p=a/c+!!(a%c),q=b/d+!!(b%d);
        if(p+q>k)printf("-1\n");
        else printf("%d %d\n",p,q);
    }
    return 0;
}