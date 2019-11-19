#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,a,b,c,d,k,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        x=a/c;
        y=b/d;
        if(a%c)
            x++;
        if(b%d)
            y++;
        if(x+y<=k)
            printf("%d %d\n",k-y,y);
        else
            printf("-1\n");
    }
	return 0;
}
