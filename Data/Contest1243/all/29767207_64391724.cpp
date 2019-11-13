#include <bits/stdc++.h>
#define N 55
using namespace std;

int T,n;
char s[N],t[N];
int num[30];
int tot;
int x[105],y[105];

bool Judge()
{
    for(int i=0;i<26;i++) if(num[i]&1) return 0;
    return 1;
}

void Solve()
{
    tot=0;
    for(int i=1;i<=n;i++) if(s[i]!=t[i])
    {
        for(int j=i+1;j<=n;j++) if(s[j]!=t[j])
        {
            if(s[i]==s[j])
            {
                tot++;
                swap(s[j],t[i]);
                x[tot]=j,y[tot]=i;
                break;
            }
        }
        if(s[i]!=t[i])
        {
            int fj=0,fk=0;
            for(int j=i+1;j<=n;j++) if(s[j]!=t[j])
            {
                if(s[i]==t[j])
                {
                    fj=j;
                    break;
                }
            }
            for(int j=i+1;j<=n;j++) if(s[j]!=t[j])
            {
                fk=j;break;
            }
            swap(s[fk],t[fj]);tot++;
            x[tot]=fk,y[tot]=fj;
            swap(s[fk],t[i]);tot++;
            x[tot]=fk,y[tot]=i;
        }
    }
    printf("%d\n",tot);
    for(int i=1;i<=tot;i++) printf("%d %d\n",x[i],y[i]);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        scanf("%s%s",s+1,t+1);
        for(int i=1;i<=n;i++) num[s[i]-'a']++,num[t[i]-'a']++;
        if(Judge())
        {
            printf("Yes\n");
            Solve();
        }
        else printf("No\n");
    }
    return 0;
}