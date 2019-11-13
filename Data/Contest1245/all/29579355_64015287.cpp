#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifdef _DEBUG
    const int N=1e3+10;
#else
    const int N=1e6+10;
#endif
int m,n,t;
int a,b,c;
int sum[10],cnt[10];
char s[N],out[N];
int main()
{
    // freopen("data.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d%d%d",&a,&b,&c);
        sum[1]=sum[2]=sum[3]=0;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='R')sum[1]++;
            if(s[i]=='P')sum[2]++;
            if(s[i]=='S')sum[3]++;
        }
        cnt[1]=min(a,sum[3]);a-=cnt[1];//r
        cnt[2]=min(b,sum[1]);b-=cnt[2];//p
        cnt[3]=min(c,sum[2]);c-=cnt[3];//s
        int ans=cnt[1]+cnt[2]+cnt[3];
        if(ans<n/2+n%2)puts("NO");
        else
        {
            puts("YES");memset(out,0,sizeof(out));
            for(int i=1;i<=n;i++)
            {
                if(s[i]=='R'&&cnt[2])out[i]='P',cnt[2]--;
                if(s[i]=='P'&&cnt[3])out[i]='S',cnt[3]--;
                if(s[i]=='S'&&cnt[1])out[i]='R',cnt[1]--;
            }
            for(int i=1;i<=n;i++)if(!out[i])
            {
                if(a){out[i]='R',a--;continue;}
                if(b){out[i]='P',b--;continue;}
                if(c){out[i]='S',c--;continue;}
            }
            printf("%s\n",out+1);
        }
    }
    return 0;
}