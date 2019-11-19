#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=100005;
int n,lnk[maxn],son[2*maxn],nxt[2*maxn],tot,c[maxn][4],siz[maxn],inn[maxn],ss[maxn],col[maxn],acol[maxn],bcol[maxn],que[maxn],tail;
ll ans=(1ll<<60);
bool flg;
void adde(int x,int y){
    son[++tot]=y,nxt[tot]=lnk[x],lnk[x]=tot;
}
void dfs(int x,int fa){
    que[++tail]=x;
    for (int j=lnk[x];j;j=nxt[j])
        if (son[j]!=fa) {
            dfs(son[j],x);
            ss[x]=son[j];
        }
}
void solve(){
    for (int i=3;i<=n;i++)
        col[i]=3-col[i-1]-col[i-2];
    ll ret=0;
    for (int i=1;i<=n;i++) ret+=1ll*c[que[i]][col[i]];
    if (ret<ans) {
        ans=ret;
        for (int i=1;i<=n;i++) acol[i]=col[i];
    }
}
int main(){
    scanf("%d",&n);
    for (int j=0;j<3;j++)
    for (int i=1;i<=n;i++)
        scanf("%d",&c[i][j]);
    for (int i=1;i<n;i++){
        int x,y; scanf("%d%d",&x,&y);
        adde(x,y); adde(y,x); inn[x]++,inn[y]++;
    }
    for (int i=1;i<=n;i++) if (inn[i]>2) flg=1;
    if (flg==1) {printf("-1\n"); return 0;}
    int p;
    for (int i=1;i<=n;i++) if (inn[i]==1) {p=i; dfs(i,0); break;}
    if (n==1) {
        printf("%d\n",min(c[1][0],min(c[1][1],c[1][2])));
        if (c[1][0]<min(c[1][1],c[1][2])) printf("1\n");
        if (c[1][1]<min(c[1][2],c[1][0])) printf("2\n");
        if (c[1][2]<min(c[1][0],c[1][1])) printf("3\n");
    } else {
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                if (i!=j){
                    col[1]=i,col[2]=j; solve();
                }
        printf("%lld\n",ans);
        //for (int i=1;i<=n;i++) printf("%d ",acol[i]); puts("");
        for (int i=1;i<=n;i++) bcol[que[i]]=acol[i];
        for (int i=1;i<=n;i++) printf("%d ",bcol[i]+1); puts("");
    }
    return 0;
}
