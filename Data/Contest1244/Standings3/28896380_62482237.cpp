#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,a,b,c,d,k;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        int x = ceil((double)a/c),y = ceil((double)b/d);
        printf(x+y>k ? "-1\n" : "%d %d\n",x,y);
    }
    return 0;
}
