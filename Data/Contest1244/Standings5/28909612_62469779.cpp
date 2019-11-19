#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define int long long
//#define d long double
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define N 1003
#define inf (int)1e18
#define Arena ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int mod=1e9+7;
string s;
int n,ma;
bool vis[5][N];

bool good(int i,int j)
{
    return (i>=1 and j>=1 and i<=2 and j<=n and (!vis[i][j]));
}   

void dfs(int i,int j,int cnt)
{
    ma=max(ma,cnt);
    vis[i][j]=1;
    
    if(good(i,j-1))
        dfs(i,j-1,cnt+1);
    if(good(i,j+1))
        dfs(i,j+1,cnt+1);
    if((s[j-1]-'0')>0)
    {
        if(good(i+1,j))
            dfs(i+1,j,cnt+1);
        if(good(i-1,j))
            dfs(i-1,j,cnt+1);
    } 
}   

signed main()
{
    Arena
       
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>s;
        ma=0;
        memset(vis,0,sizeof vis);
        dfs(1,1,1);
        
        memset(vis,0,sizeof vis);
        dfs(1,n,1);
        
        memset(vis,0,sizeof vis);
        dfs(2,1,1);
        
        memset(vis,0,sizeof vis);
        dfs(2,n,1);
        
        cout<<ma<<'\n';
    }   
    
    
    return 0;
}
