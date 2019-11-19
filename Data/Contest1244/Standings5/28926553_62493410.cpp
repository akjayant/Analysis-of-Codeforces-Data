#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n,x,y,r;
long long w[100010][5];
int cnt[100010];
vector<int> e[100010];
long long dp[100010][5][5];
int ans[100010];

void add_edge(int u,int v)
{
    e[u].push_back(v);
    e[v].push_back(u);
}

int diff(int x,int y)
{
    if (x!=1 && y!=1) return 1;
    if (x!=2 && y!=2) return 2;
    return 3;
}

int find_root()
{
    int re=0;
    for (int i=1;i<=n;i++)
    {
        if (cnt[i]>2) return 0;
        if (cnt[i]==1) re=i;
    }
    return re;
}

void get_dp(int u,int fa)
{
    if (u!=r && cnt[u]==1)
    {
        for (int i=1;i<=3;i++)
        {
            for (int j=1;j<=3;j++)
            {
                dp[u][i][j]=w[u][i];
            }
        }
        return;
    }
    for (int v:e[u])
    {
        if (v==fa) continue;
        get_dp(v,u);
        for (int i=1;i<=3;i++)
        {
            for (int j=1;j<=3;j++)
            {
                if (i==j) continue;
                int k=diff(i,j);
                if (!dp[u][i][j]) dp[u][i][j]=dp[v][j][k]+w[u][i];
                else dp[u][i][j]=min(dp[u][i][j],dp[v][j][k]+w[u][i]);
            }
        }
    }
}

void get_ans(int u,int fa,int now,int nxt)
{
    ans[u]=now;
    for (int v:e[u])
    {
        if (v==fa) continue;
        get_ans(v,u,nxt,diff(now,nxt));
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&w[i][1]);
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&w[i][2]);
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&w[i][3]);
    }
    for (int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        cnt[x]++;
        cnt[y]++;
    }
    r=find_root();
    if (!r) printf("-1");
    else
    {
        get_dp(r,0);
        long long minw=LONG_LONG_MAX;
        int ans1,ans2;
        for (int i=1;i<=3;i++)
        {
            for (int j=1;j<=3;j++)
            {
                if (i==j) continue;
                if (dp[r][i][j]<minw)
                {
                    minw=dp[r][i][j];
                    ans1=i;
                    ans2=j;
                }
            }
        }
        get_ans(r,0,ans1,ans2);
        printf("%lld\n",minw);
        for (int i=1;i<=n;i++)
        {
            printf("%d ",ans[i]);
        }
    }
    getchar(); getchar();
    return 0;
}