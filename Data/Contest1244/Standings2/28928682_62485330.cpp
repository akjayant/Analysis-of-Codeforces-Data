#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+8;
int n;
int c[maxn][4];
int first[maxn],nxt[maxn*2],last[maxn],to[maxn*2],cnt=0;
int dig[maxn];
int dp[maxn][3][3][3];
int col[maxn];
int tar[maxn];
int arr[maxn],tot=0;
void addedge(int a,int b){
    if(!first[a])first[a]=++cnt;
    else nxt[last[a]]=++cnt;
    last[a]=cnt;
    to[cnt]=b;
}
void dfs(int u,int fa){
    arr[++tot]=u;
    tar[tot]=u;
    for(int q=first[u];q;q=nxt[q]){
        if(to[q]!=fa){
            dfs(to[q],u);
        }
    }
}
signed main(){
    scanf("%lld",&n);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&c[j][i]);
        }
    }
    for(int i=1;i<n;i++){
        int a,b;scanf("%lld%lld",&a,&b);
        addedge(a,b);addedge(b,a);
        dig[a]++,dig[b]++;
    }
    for(int i=1;i<=n;i++){
        if(dig[i]>=3){
            cout<<-1<<endl;
            exit(0);
        }
    }
    for(int i=1;i<=n;i++){
        if(dig[i]==1){
            dfs(i,0);
            break;
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(i==j)continue;
            int z=6-i-j;
            dp[3][i][j][z]=c[tar[1]][i]+c[tar[2]][j]+c[tar[3]][z];
        }
    }
    for(int i=4;i<=tot;i++){
        for(int j=1;j<=3;j++){
            for(int k=1;k<=3;k++){
                if(j==k)continue;
                int z=6-j-k;
                if(dp[i-1][z][j][k]+c[tar[i]][z]<dp[i][j][k][z]){
                    dp[i][j][k][z]=dp[i-1][z][j][k]+c[tar[i]][z];
                }
            }
        }
    }
    int ans=dp[0][0][0][0];
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(i==j)continue;
            int k=6-i-j;
            if(dp[n][i][j][k]<ans){
                ans=dp[n][i][j][k];
                col[tar[n]]=k;col[tar[n-1]]=j;col[tar[n-2]]=i;
            }
        }
    }
    for(int i=n-3;i>=1;i--){
        col[tar[i]]=col[tar[i+3]];
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        printf("%lld ",col[i]);
    }
    return 0;
}