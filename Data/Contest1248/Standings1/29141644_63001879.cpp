#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=4e5+10;
const int MOD=1e9+7;

char s[MAXN];
int st[MAXN],cnt,n;

int work()
{
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(')
            st[++cnt]=-1;
        else
        {
            if(st[cnt]==-1)cnt--;
            else st[++cnt]=i;
        }
    }
    while(st[cnt]==-1)cnt--;
    int ans=st[cnt];
    return ans;
}

int solve(int tmp)
{
    int ans=0;
    cnt=0;
    for(int i=1;i<=n;i++)
    {
        int now=i+tmp;
        if(now>n)now-=n;
        if(s[now]=='(')cnt++;
        else cnt--;
        if(!cnt)ans++;
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(')cnt++;
    }
    if(cnt!=n/2||n&1)
    {
        puts("0");
        return puts("1 1"),0;
    }
    int l=1,r=1,ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
        {
            swap(s[i],s[j]);
            int tmp=work();
            int tt=solve(tmp);
            if(tt>ans)
            {
                ans=tt;
                l=i,r=j;
            }
            swap(s[i],s[j]);
        }
    printf("%d\n%d %d",ans,l,r);
    return 0;
}
