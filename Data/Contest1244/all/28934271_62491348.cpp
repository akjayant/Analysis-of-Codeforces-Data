#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define endl '\n'
int n;
vector<int> v[200001];
int c[200001][4];
int deg[200001];
int dp[200001][5][5];
vector<int> tmp;
vector<int> ans1(200001);
void dfs(int node,int par)
{
    tmp.push_back(node);
    for(int i=0;i<v[node].size();i++)
    {
        if(v[node][i]==par)
            continue;
        dfs(v[node][i],node);
    }
}
int f(int i,int prev1,int prev2)
{
    if(i==tmp.size())
        return 0;
    if(dp[i][prev1][prev2]!=-1)
        return dp[i][prev1][prev2];
    int ans=1e18;
    for(int j=1;j<=3;j++)
    {
        if(j==prev1||j==prev2)
            continue;
        ans=min(ans,c[tmp[i]][j]+f(i+1,j,prev1));
    }
    return dp[i][prev1][prev2]=ans;
}
void path(int i,int prev1,int prev2)
{
    if(i==tmp.size())
        return ;
    int ans=1e18;
    int ind=-1;
    for(int j=1;j<=3;j++)
    {
        if(j==prev1||j==prev2)
            continue;
        if(ans>c[tmp[i]][j]+f(i+1,j,prev1))
            ind=j;
        ans=min(ans,c[tmp[i]][j]+f(i+1,j,prev1));
    }
    int node=tmp[i];
    ans1[node]=ind;
    path(i+1,ind,prev1);
}
int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=n;j++)
            cin>>c[j][i];
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    memset(dp,-1,sizeof(dp));
    int start=-1;
    for(int i=1;i<=n;i++)
    {
        if(deg[i]>2)
        {
            cout<<-1;
            return 0;
        }
        if(deg[i]==1)
            start=i;
    }
    dfs(start,0);
    cout<<f(0,4,4)<<endl;
    path(0,4,4);
    for(int i=1;i<=n;i++)
        cout<<ans1[i]<<" ";
}
    