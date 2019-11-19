#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
#define maxn 101000
#define maxm 201000
typedef long long ll;
int n,b[maxn],c[maxn],du[maxn],a[maxn],d,k,pre[maxm],now[maxn],son[maxm],tot;
void con(int a,int b){
    pre[++tot]=now[a];
    now[a]=tot;
    son[tot]=b;
}
ll f[maxn][3][3];
int col[maxn];
void dfs(int x,int fa){
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)if(i!=j){
        f[x][i][j]=i==0?a[x]:(1==i?b[x]:c[x]);
    }
    for(int p=now[x];p;p=pre[p])
        if(son[p]!=fa){
            dfs(son[p],x);
            for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)if(i!=j){
                f[x][i][j]+=f[son[p]][j][3-i-j];
            }
        }
}
void get_ans(int x,int fa,int c,int tt){
    col[x]=c;
    for(int p=now[x];p;p=pre[p])
    if(son[p]!=fa){
        get_ans(son[p],x,tt,3-c-tt);
    }
}
void work(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",b+i);
    for(int i=1;i<=n;i++)
        scanf("%d",c+i);
    bool kk=0;
    for(int i=1,t1,t2;i<n;i++){
        scanf("%d%d",&t1,&t2);
        con(t1,t2);con(t2,t1);
        du[t1]++;
        du[t2]++;
        if(du[t1]>2||du[t2]>2)kk=1;
    }
    int st=0;
    for(int i=1;i<=n;i++)if(du[i]==1)st=i;
    if(!st||kk){
        puts("-1");
        return;
    }
    dfs(st,0);
    ll ans1=1e18,ans2,ans3;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
        if(i!=j&&f[st][i][j]<ans1){
            ans1=f[st][i][j];
            ans2=i;
            ans3=j;
        }
    get_ans(st,0,ans2,ans3);
    printf("%lld\n",ans1);
    for(int i=1;i<=n;i++)
        printf("%d ",col[i]+1);
}
int main(){
    int t=1;
    while(t--)work();
}
