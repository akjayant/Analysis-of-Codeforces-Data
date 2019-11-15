#include <bits/stdc++.h>
#define N 20005
using namespace std;

int T,n;
char s[N],t[N];   
char ss[N],tt[N]; 

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s%s",s+1,t+1);
        int tot=0;
        for(int i=1;i<=n;i++)
            if(s[i]!=t[i]) ss[++tot]=s[i],tt[tot]=t[i];
        if(tot==2)
        {
            if(ss[1]==ss[2]&&tt[1]==tt[2]) printf("Yes\n");
            else printf("No\n");
        }
        else printf("No\n");
    }
    return 0;
}