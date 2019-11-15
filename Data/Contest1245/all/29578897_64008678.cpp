#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=300050;
const ll llINF=~(1ll<<63);
const int INF=~(1<<31),MOD=1e9+7;
#define lowbit(x) x&-x

char s[105],ans[105];
int a,b,c,n,cnt;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cnt=0;
        memset(ans,0,sizeof(ans));
        scanf("%d%d%d%d",&n,&a,&b,&c);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='P'&&c)
            {
                c--;
                ans[i]='S';
                cnt++;
            }
            else if(s[i]=='R'&&b)
            {
                b--;
                ans[i]='P';
                cnt++;
            }
            else if(s[i]=='S'&&a)
            {
                a--;
                ans[i]='R';
                cnt++;
            }
        }
        if(cnt<(n+1)/2)
        {
            puts("NO");
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(!ans[i])
            {
                if(a)
                {
                    a--;
                    ans[i]='R';
                }
                else if(b)
                {
                    b--;
                    ans[i]='P';
                }
                else
                {
                    c--;
                    ans[i]='S';
                }
            }
        }
        printf("YES\n%s\n",ans+1);
    }
    return 0;
}
