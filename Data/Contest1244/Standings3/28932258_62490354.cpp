#include "bits/stdc++.h"
#define hhh printf("hhh\n")
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
inline int read() {int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}

const int maxn = 1e5+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;

int c[maxn][4];
int in[maxn], b[3]={1,2,3}, d[3];
int s, t;
int head[maxn], to[maxn*2], nxt[maxn*2], tot, id[maxn];
inline void add_edge(int u, int v) {
    ++tot; to[tot]=v; nxt[tot]=head[u]; head[u]=tot;
    ++tot; to[tot]=u; nxt[tot]=head[v]; head[v]=tot;
}

void dfs(int u, int f) {
    for(int i=head[u]; i; i=nxt[i]) {
        int v=to[i];
        if(v==f) continue;
        id[v]=id[u]+1;
        dfs(v,u);
    }
}

int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i) c[i][1]=read();
    for(int i=1; i<=n; ++i) c[i][2]=read();
    for(int i=1; i<=n; ++i) c[i][3]=read();
    for(int i=1; i<n; ++i) {
        int u=read(), v=read();
        add_edge(u,v); in[u]++, in[v]++;
    }
    for(int i=1; i<=n; ++i) {
        if(in[i]>2) return printf("-1\n"), 0;
        if(in[i]==1) {
            if(!s) s=i;
            else t=i;
        }
    }
    ll ans=1e18;
    dfs(s,0);
    //for(int i=1; i<=n; ++i) printf("%d ", id[i]); cout<<endl;
    do{
        //for(int i=0; i<3; ++i) printf("%d ", b[i]); cout<<endl;
        ll cur=0;
        for(int i=1; i<=n; ++i) {
            cur+=c[i][b[id[i]%3]];
            /*if(b[0]==1&&b[1]==3&&b[2]==2) {
                see(id[i]);
                see(b[id[i]%3]);
                see(c[i][b[id[i]%3]]);
            }*/
        }
        //see(cur);
        if(cur<ans) {
            ans=cur;
            d[0]=b[0], d[1]=b[1], d[2]=b[2];
        }
    }while(next_permutation(b,b+3));
    //for(int i=0; i<3; ++i) printf("%d ", d[i]);
    cout<<ans<<endl;
    for(int i=1; i<=n; ++i) printf("%d%c", d[id[i]%3], " \n"[i==n]);
}