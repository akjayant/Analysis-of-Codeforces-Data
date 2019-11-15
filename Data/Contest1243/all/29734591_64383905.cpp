#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int m,n,t,ans;
int a[N],tmp[10];
char s1[N],s2[N];

int main()
{
    // freopen("data.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);int ok=1;
        scanf("%s%s",s1+1,s2+1);
        memset(a,0,sizeof(a));
        memset(tmp,0,sizeof(tmp));
        for(int i=1;i<=n;i++)a[s1[i]-'a'+1]++,a[s2[i]-'a'+1]++;
        for(int i=1;i<=26;i++)if(a[i]%2)ok=0;
        if(!ok){puts("NO");continue;}
        ok=0;
        for(int i=1;i<=n;i++)if(s1[i]!=s2[i])ok++,tmp[++tmp[0]]=i;
        if(ok>2)puts("NO");
        else 
        {
            if(s1[tmp[1]]!=s1[tmp[2]])puts("NO");
            else puts("YES");
        }
    }
}
