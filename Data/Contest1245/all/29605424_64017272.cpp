#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int a,b,c;
char s[105];
int s1[105];
int ok=0;

int main ()
{
    //freopen("main.inp","r",stdin);
    //freopen("main.out","w",stdout);

    scanf("%d ",&t);

    while(t>0)
    {
        t--;

        scanf("%d ",&n);

        scanf("%d %d %d ",&a,&b,&c);

        scanf("%s",s+1);

        memset(s1,0,sizeof s1);
        ok=0;

        for(int i=1; i<=n; ++i)
        {
            if(s[i]=='R'&&b>0)
                b--,ok++,s1[i]=1;

            if(s[i]=='P'&&c>0)
                c--,ok++,s1[i]=2;

            if(s[i]=='S'&&a>0)
                a--,ok++,s1[i]=3;
        }

        for(int i=1; i<=n; ++i)
            if(s1[i]==0)
            {
                if(a>0)
                    a--,s1[i]=3;
                else if(b>0)
                    b--,s1[i]=1;
                else if(c>0)
                    c--,s1[i]=2;
            }

        if(ok>=(n+1)/2)
        {
            printf("YES\n");
            for(int i=1; i<=n; ++i)
            {
                if(s1[i]==3)
                    printf("R");

                if(s1[i]==1)
                    printf("P");

                if(s1[i]==2)
                    printf("S");
            }
            printf("\n");
        }
        else
            printf("NO\n");

    }
}
