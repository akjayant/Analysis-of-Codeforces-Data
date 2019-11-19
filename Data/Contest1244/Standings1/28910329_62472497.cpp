#include<bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
int n,u,v;
int a[N],b[N],c[N];
vector<int>q[N];
int deg[N];

int s[N],cnt;
void DFS(int x,int fa){
    s[++cnt]=x;
    for(int i=0;i<(int)q[x].size();i++){
        int to=q[x][i];
        if(to==fa)continue;
        DFS(to,x);
    }
}
ll ans=1e18;int Tp1,Tp2,Tp3;
int col[N];
void work(int *a,int *b,int *c,int tp1,int tp2,int tp3){
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(i%3==1)sum+=a[s[i]];
        if(i%3==2)sum+=b[s[i]];
        if(i%3==0)sum+=c[s[i]];
    }
    if(sum<ans)ans=sum,Tp1=tp1,Tp2=tp2,Tp3=tp3;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        q[u].push_back(v),q[v].push_back(u);
        deg[v]++,deg[u]++;
    }
    for(int i=1;i<=n;i++)if(deg[i]>=3)return 0*printf("-1\n");
    int fir;
    for(int i=1;i<=n;i++)if(deg[i]==1){fir=i;break;}
    DFS(fir,-1);

    work(a,b,c,1,2,3);
    work(a,c,b,1,3,2);
    work(b,a,c,2,1,3);
    work(b,c,a,2,3,1);
    work(c,a,b,3,1,2);
    work(c,b,a,3,2,1);
    for(int i=1;i<=n;i++){
        if(i%3==1)col[s[i]]=Tp1;
        if(i%3==2)col[s[i]]=Tp2;
        if(i%3==0)col[s[i]]=Tp3;
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)printf("%d%c",col[i],i==n?'\n':' ');
    return 0;
}