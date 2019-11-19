#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,k,t;
int main()
{
    scanf("%d",&t);
    for (int iii=1;iii<=t;++iii)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        bool flag=true;
        for (int i=0;i<=k;i++)
        if (i*c>=a && (k-i)*d>=b)
        {
            printf("%d %d\n",i,k-i);
            flag=false;
            break;
        }
        if (flag) printf("-1\n");
    }
    return 0;
}
