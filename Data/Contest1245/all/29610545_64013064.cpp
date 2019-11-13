#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int t,n;
char s[110];
int a,b,c;
char ans[110];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d %s",&n,&a,&b,&c,s+1);
        int num=n;
        for(register int i=1;i<=n;i++)
        {
            if(s[i]=='R' && b) ans[i]='P',b--;
            else if(s[i]=='P' && c) ans[i]='S',c--;
            else if(s[i]=='S' && a) ans[i]='R',a--;
            else ans[i]='M',num--;
        }
        if(num>=(n+1)/2)
        {
            puts("YES");
            for(register int i=1;i<=n;i++)
                if(ans[i]!='M') putchar(ans[i]);
                else 
                {
                    if(a) putchar('R'),a--;
                    else if(b) putchar('P'),b--;
                    else if(c) putchar('S'),c--;
                }
            puts("");
        }else puts("NO");
    }
    return 0;
}