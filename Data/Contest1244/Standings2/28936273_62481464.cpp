#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mx 200000
#define ll long long

ll dp[mx][4][4];
int ara[mx][4];
int color[mx];
vector<int>vc[mx],ac[mx];
ll big=(1LL<<58);
ll dp_func(int v,int par,int grand)
{

    if(dp[v][par][grand]!=-1)return dp[v][par][grand];
    ll ans=(1LL<<58);
    ll g;
    if(par!=1&&grand!=1)
    {
          g=ara[v][1];
          if(vc[v].size())g+=dp_func(vc[v][0],1,par);
          ans=min(ans,g);
    }
     if(par!=2&&grand!=2)
    {
          g=ara[v][2];
          if(vc[v].size())g+=dp_func(vc[v][0],2,par);
          ans=min(ans,g);
    }
     if(par!=3&&grand!=3)
    {
          g=ara[v][3];
          if(vc[v].size())g+=dp_func(vc[v][0],3,par);
          ans=min(ans,g);
    }
    return dp[v][par][grand]=ans;
}
void dfs(int v,int par)
{
     for(int i=0;i<ac[v].size();i++)
     {
         int w=ac[v][i];
         if(w==par)continue;
         dfs(w,v);
         vc[v].pb(w);
     }
}
void path(int v,int par,int grand)
{
     ll ret=dp[v][par][grand];
    for(int j=1;j<=3;j++)
    {
        if(j==par||j==grand)continue;
        ll g=ara[v][j];
        if(vc[v].size())g+=dp_func(vc[v][0],j,par);
        if(g==ret)
        {
            color[v]=j;
            if(vc[v].size())path(vc[v][0],j,par);
            return ;
        }
    }
}
int main()
{
   int n;
    scanf("%d",&n);
    memset(dp,-1,sizeof dp);
    for(int j=1;j<=3;j++)
    for(int i=1;i<=n;i++)
    {
       scanf("%d",&ara[i][j]);
    }
    int ck=0;
    for(int i=1;i<n;i++)
    {
        int l,k;
        scanf("%d%d",&l,&k);
        ac[l].pb(k);
        ac[k].pb(l);
        if(ac[l].size()>=3)
        {
            ck=1;
        }
         if(ac[k].size()>=3)
        {
            ck=1;
        }
    }
    if(ck)
    {
       printf("-1");
       return 0;
    }
    int root;
    for(int i=1;i<=n;i++)
    {
       if(ac[i].size()==1)root=i;
    }
    dfs(root,-1);
    ll ans=dp_func(root,0,0);
    if(ans==big)
    {
        printf("-1");
        return 0;
    }
    cout<<ans<<endl;
    path(root,0,0);
    for(int i=1;i<=n;i++)printf("%d ",color[i]);




}
