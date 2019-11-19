#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define N 200050
using namespace std;
ll dp[3][3][N];
int rec[3][3][N];
int n;
int d[N],son[N],res[N];
ll cost[3][N];
int st=0;
struct zero{
    int nxt,to;
}edge[N<<1];
int head[N],tot=0;
void add_edge(int a,int b){edge[++tot]=(zero){head[a],b};head[a]=tot;}
void dfs(int x,int fa){
    if(x!=st&&d[x]==1){dp[0][0][x]=cost[0][x],dp[1][1][x]=cost[1][x],dp[2][2][x]=cost[2][x];return;}
    for(int i=head[x];i;i=edge[i].nxt){
        int to=edge[i].to;
        if(to==fa)continue;
        dfs(to,x);son[x]=to;
        for(int p1=0;p1<3;p1++)
        for(int p2=0;p2<3;p2++){
            if(p1==p2&&d[to]!=1)continue;
            if(p1!=0&&p2!=0)if(dp[0][p1][x]>dp[p1][p2][to]+cost[0][x])dp[0][p1][x]=dp[p1][p2][to]+cost[0][x],rec[0][p1][x]=p2;
            if(p1!=1&&p2!=1)if(dp[1][p1][x]>dp[p1][p2][to]+cost[1][x])dp[1][p1][x]=dp[p1][p2][to]+cost[1][x],rec[1][p1][x]=p2;
            if(p1!=2&&p2!=2)if(dp[2][p1][x]>dp[p1][p2][to]+cost[2][x])dp[2][p1][x]=dp[p1][p2][to]+cost[2][x],rec[2][p1][x]=p2;
        }
    }
}
int main(){
scanf("%d",&n);
for(int i=0;i<3;i++)
for(int r=1;r<=n;r++)scanf("%lld",&cost[i][r]);
for(int i=1;i<n;i++){
int a,b;scanf("%d%d",&a,&b);
add_edge(a,b),add_edge(b,a);d[a]++,d[b]++;
}
for(int i=n;i>=1;i--){
    if(d[i]==1)st=i;
    if(d[i]>2)return puts("-1"),0;
}
for(int i=1;i<=n;i++)
for(int r=0;r<3;r++)
for(int k=0;k<3;k++)dp[r][k][i]=1e18;
dfs(st,0);
int rec1=0,rec2=0;
for(int i=0;i<3;i++)for(int r=0;r<3;r++)if(i^r&&dp[i][r][st]<dp[rec1][rec2][st])rec1=i,rec2=r;
int poss=st;
cout<<dp[rec1][rec2][st]<<endl;
while(poss){
    res[poss]=rec1+1;
    int t1=rec1,t2=rec2;
    rec1=t2;
    rec2=rec[t1][t2][poss];
    poss=son[poss];
}
for(int i=1;i<=n;i++)printf("%d ",res[i]);
}