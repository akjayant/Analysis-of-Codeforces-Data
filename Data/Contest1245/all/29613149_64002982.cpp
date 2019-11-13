//μ's forever
#include <bits/stdc++.h>
#define N 105
using namespace std;
int T,n,a,b,c,sum,f[N];
char s[N];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        memset(f,0,sizeof(f));
        scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
        for(register int i=1;i<=n;++i)
        {
            if(s[i]=='R')
            {
                if(b)
                {
                    --b,++sum;
                    f[i]=1;
                }
            }
            else if(s[i]=='P')
            {
                if(c)
                {
                    --c,++sum;
                    f[i]=1;
                }
            }
            else
            {
                if(a)
                {
                    --a,++sum;
                    f[i]=1;
                }
            }
            //printf("%d\n",sum);
        }
        if(sum*2>=n)
        {
            puts("Yes");
            for(register int i=1;i<=n;++i)
            {
                if(f[i])
                {
                    if(s[i]=='R')
                        putchar('P');
                    else if(s[i]=='P')
                        putchar('S');
                    else
                        putchar('R');
                }
                else
                {
                    if(a)
                        putchar('R'),--a;
                    else if(b)
                        putchar('P'),--b;
                    else
                        putchar('S');
                }
            }
            puts("");
        }
        else
            puts("NO");
    }
	return 0;
}
