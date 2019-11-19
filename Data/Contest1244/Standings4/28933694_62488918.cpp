#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
ll cst[5][100005];
vector<int> lst[100005], pth;
int deg[100005], clr[100005];
ll dp[5][5][100005];
P prv[5][5][100005];
const ll INF=1e9;

void dfs(int cur, int pv)
{
    pth.push_back(cur);
    for(int i=0 ; i<lst[cur].size() ; i++){
        int nxt=lst[cur][i];
        if(nxt!=pv){
            dfs(nxt,cur);
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1 ; i<=3 ; i++){
        for(int j=1 ; j<=n ; j++) scanf("%lld",&cst[i][j]);
    }
    for(int i=1 ; i<n ; i++){
        int x, y;
        scanf("%d %d",&x,&y);
        lst[x].push_back(y);
        lst[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    int st=-1;
    for(int i=1 ; i<=n ; i++){
        if(deg[i]>2){
            printf("-1");
            return 0;
        }
        if(deg[i]==1) st=i;
    }
    int fn=-1;
    dfs(st,-1);
    for(int i=1 ; i<=3 ; i++) for(int j=1 ; j<=3 ; j++) dp[i][j][st]=cst[i][st];
    for(int i=1 ; i<n ; i++){
        int cur=pth[i], pr=pth[i-1];
        fn=cur;
        for(int j=1 ; j<=3 ; j++){
            for(int k=1 ; k<=3 ; k++){
                dp[j][k][cur]=-1LL;
                if(j==k) continue;
                for(int x=1 ; x<=3 ; x++){
                    if(j==x || k==x) continue;
                    if(dp[j][k][cur]==-1LL || dp[j][k][cur]>dp[k][x][pr]+cst[j][cur]){
                        dp[j][k][cur]=dp[k][x][pr]+cst[j][cur];
                        prv[j][k][cur]=P(k,x);
                    }
                }
            }
        }
    }
    ll ans=-1LL;
    P pcur;
    for(int i=1 ; i<=3 ; i++){
        for(int j=1 ; j<=3 ; j++){
            if(i==j) continue;
            if(ans==-1LL || ans>dp[i][j][fn]){
                ans=dp[i][j][fn];
                pcur=P(i,j);
            }
        }
    }
    printf("%lld\n",ans);
    clr[fn]=pcur.first;
    for(int i=n-2 ; i>=0 ; i--){
        int cur=pth[i+1];
        pcur=prv[pcur.first][pcur.second][cur];
        clr[pth[i]]=pcur.first;
    }
    for(int i=1 ; i<=n ; i++) printf("%d ",clr[i]);
    return 0;
}
