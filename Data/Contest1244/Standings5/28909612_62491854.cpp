#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define d long double
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define N 100003
#define inf (int)1e15
#define Arena ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int mod=1e9+7;
int c[4][N];
vector<int> g[N];
int dp[4][4][N];
int col[N];

void dfs(int i, int p)
{
    int j,k;
    for(j=0;j<4;++j)
        for(k=0;k<4;++k)
            dp[j][k][i]=inf;
    
    j=g[i].size();
    if(j==1 and (i!=p))
    {
        dp[1][0][i]=c[1][i];
        dp[2][0][i]=c[2][i];
        dp[3][0][i]=c[3][i];
    }
    else 
    {
        j=g[i][0];
        if(j==p)
            j=g[i][1];
        dfs(j,i);
        dp[1][2][i]=min(dp[1][2][i] , min(dp[2][0][j] , dp[2][3][j]) + c[1][i]);
        dp[1][3][i]=min(dp[1][3][i] , min(dp[3][0][j] , dp[3][2][j]) + c[1][i]);
        dp[2][1][i]=min(dp[2][1][i] , min(dp[1][0][j] , dp[1][3][j]) + c[2][i]);
        dp[2][3][i]=min(dp[2][3][i] , min(dp[3][0][j] , dp[3][1][j]) + c[2][i]);
        dp[3][1][i]=min(dp[3][1][i] , min(dp[1][0][j] , dp[1][2][j]) + c[3][i]);
        dp[3][2][i]=min(dp[3][2][i] , min(dp[2][0][j] , dp[2][1][j]) + c[3][i]);
    }   
}

void fillcol(int i,int p,int curr,int child)
{
    col[i]=curr;
    int j=g[i].size(),mi;
    if(j==1 and (i!=p))
        return;
    else
    {
        j=g[i][0];
        if(j==p)
            j=g[i][1];
        fillcol(j,i,child,6-child-curr);
    }   
}   

signed main()
{
    Arena
       
    int n;
    cin>>n;
    int i,j,u,v;
    for(i=1;i<=3;++i)
        for(j=1;j<=n;++j)
            cin>>c[i][j];
    
    for(i=1;i<=n-1;++i)
        cin>>u>>v, g[u].pb(v), g[v].pb(u);
    
    for(i=1;i<=n;++i)
        if(g[i].size()>2)
            return cout<<-1, 0;
        else if(g[i].size()==1)
            j=i;
    
    dfs(j,j);
    int mi=min({dp[1][2][j],dp[1][3][j],dp[2][1][j],dp[2][3][j],dp[3][1][j],dp[3][2][j]});
    int curr,child;
   
    if(mi==dp[1][2][j])
        curr=1, child=2;
    else if(mi==dp[1][3][j])
        curr=1, child=3;
    else if(mi==dp[2][1][j])
        curr=2, child=1;
    else if(mi==dp[2][3][j])
        curr=2, child=3;
    else if(mi==dp[3][1][j])
        curr=3, child=1;
    else
        curr=3, child=2;
    
    fillcol(j,j,curr,child);
    cout<<mi<<'\n';
    for(i=1;i<=n;++i)
        cout<<col[i]<<' ';
    
    
    
    return 0;
}
