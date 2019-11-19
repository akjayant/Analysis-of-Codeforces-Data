#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
const int maxn=100500;
struct gg {
    int u,v,next;
}side[maxn*2];
int head[maxn],cnt,in[maxn],c[4][maxn],n,col[maxn],s1,s2,s;
using namespace std;
void insert(int u,int v) {
    struct gg add={u,v,head[u]};side[++cnt]=add;head[u]=cnt;
};
int get(int a,int b) {
    for(int i=1;i<=3;i++)if(i!=b&&i!=a)return i;
    return 0;
}

ll dfs(int now,int fa,int nowc,int nextc) {
    ll ans=c[nowc][now];col[now]=nowc;
    for(int i=head[now];i;i=side[i].next) {
        int v=side[i].v;if(v==fa)continue;
        ans+=dfs(v,now,nextc,get(nowc,nextc));
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    ll ans=1e18+1000;
    cin>>n;
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=n;j++)cin>>c[i][j];
    }
    for(int i=1;i<n;i++) {
        int u,v;cin>>u>>v;if(in[u]==2||in[v]==2){cout<<"-1";return 0;}
        insert(u,v);insert(v,u);in[u]++,in[v]++;
    }
    for(int i=1;i<=n;i++)if(in[i]==1)s=i;
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            if(i==j)continue;
            ll val=dfs(s,0,i,j);
            if(val<ans){ans=val;s1=i,s2=j;}
        }
    }
    cout<<dfs(s,0,s1,s2)<<endl;
    for(int i=1;i<=n;i++)cout<<col[i]<<' ';
    return 0;
}