#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll n,c[4][100005],ans[100005],deg[100005];
vector<ll>v[100005];
ll dp[100005][4][4];
void dfs(ll node, ll par, ll col, ll pc){
    dp[node][col][pc]=c[col][node];
    for(auto it:v[node]){
        if(it!=par){
            for(ll i=1;i<=3;i++){
                if(i!=col&&i!=pc){
                    dfs(it,node,i,col);
                }
            }
            ll val=1e15;
            for(ll i=1;i<=3;i++){
                if(i!=col&&i!=pc){
                    val=min(val,dp[it][i][col]);
                }
            }
            dp[node][col][pc]+=val;
        }
    }
}
void solve(ll node,ll par,ll col,ll pc,ll gans){
    gans-=c[col][node];
    for(auto it:v[node]){
        if(it!=par){
            for(ll i=1;i<=3;i++){
                if(i!=col&&i!=pc&&dp[it][i][col]==gans){
                    ans[it]=i;
                    solve(it,node,i,col,gans);
                    break;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k,x,y;
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>c[1][i];
    }
    for(i=1;i<=n;i++){
        cin>>c[2][i];
    } 
    for(i=1;i<=n;i++){
        cin>>c[3][i];
    }
    for(i=1;i<n;i++){
        cin>>x>>y;
        deg[x]++;
        deg[y]++;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(i=1;i<=n;i++){
        if(deg[i]>2){
            cout<<"-1\n";
            return 0;
        }
    }
    ll rt=0;
    for(i=1;i<=n;i++){
        if(deg[i]==1){
            rt=i;
        }
    }
    dfs(rt,0,1,0);
    dfs(rt,0,2,0);
    dfs(rt,0,3,0);
    ll gans=dp[rt][1][0];
    ll curcol=1;
    if(dp[rt][2][0]<gans){
        curcol=2;
        gans=dp[rt][2][0];
    } 
    if(dp[rt][3][0]<gans){
        curcol=3;
        gans=dp[rt][3][0];
    }
    cout<<gans<<"\n";
    ans[rt]=curcol;
    solve(rt,0,curcol,0,gans);
    for(i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}