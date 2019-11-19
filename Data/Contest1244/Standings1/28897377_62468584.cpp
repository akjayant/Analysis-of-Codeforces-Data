#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,a,b,c,d,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        if((a+c-1)/c+(b+d-1)/d>k)
        {
            printf("-1\n");
            continue;
        }
        printf("%d %d\n",(a+c-1)/c,k-(a+c-1)/c);
    }
}
