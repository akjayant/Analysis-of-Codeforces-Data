#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#define INF 0x3f3f3f3f
#define ll long long
#define mod 998244353
#define maxx 100005
using namespace std;
int n;
int a,b,c;
char s[105];
char ans[105];
int _a,_b,_c;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d%d%d",&a,&b,&c);
        scanf("%s",s+1);
        _a=0,_b=0,_c=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='R')_a++;
            else if(s[i]=='P')_b++;
            else _c++;
        }
        int num=min(b,_a)+min(a,_c)+min(c,_b);
        if(num*2>=n)
        {
            printf("YES\n");
            memset(ans,0,sizeof(ans));
            for(int i=1;i<=n;i++)
            {
                if(s[i]=='R')
                {
                    if(b)
                    {
                        ans[i]='P';
                        b--;
                    }
                }
                else if(s[i]=='P')
                {
                    if(c)
                    {
                        ans[i]='S';
                        c--;
                    }
                }
                else
                {
                    if(a)
                    {
                        ans[i]='R';
                        a--;
                    }
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(!ans[i])
                {
                    if(a)
                    {
                        ans[i]='R';a--;
                    }
                    else if(b)
                    {
                        ans[i]='P',b--;
                    }
                    else
                    {
                        ans[i]='S',c--;
                    }
                }
            }
            for(int i=1;i<=n;i++)printf("%c",ans[i]);
            printf("\n");
        }
        else printf("NO\n");
    }
    return 0;
}