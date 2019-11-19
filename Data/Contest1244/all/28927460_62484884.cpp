#include<bits/stdc++.h>
using namespace std;

#define int long long 

void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}

void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}

#define lf double
#define ll long long 

#define pii pair<int,int >
#define vec vector<int >

#define pb push_back
#define mp make_pair
#define fr first
#define sc second

#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)

const int maxn = 1e5+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;

int head[maxn],tot,n,id[maxn],d[maxn],col[maxn],f[maxn][3][3],rev[maxn],a[3][maxn];
struct edge{int to,nxt;}e[maxn<<1];

pair<int,int > t[maxn][3][3];

void ins(int u,int v) {e[++tot]=(edge){v,head[u]},head[u]=tot,d[v]++;}

void dfs(int x,int fa,int ddd) {
    id[x]=ddd;rev[ddd]=x;
    for(int i=head[x];i;i=e[i].nxt)
        if(e[i].to!=fa) dfs(e[i].to,x,ddd+1);
}

signed main() {
    read(n);memset(f,63,sizeof f);
    for(int x=0;x<3;x++) for(int i=1;i<=n;i++) read(a[x][i]);
    for(int i=1,x,y;i<n;i++) read(x),read(y),ins(x,y),ins(y,x);
    int st;
    for(int i=1;i<=n;i++)
        if(d[i]>2) return puts("-1"),0;
        else if(d[i]==1) st=i;
    dfs(st,0,1);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            f[0][i][j]=0;
    for(int p=1;p<=n;p++) {
        int x=p,y=p-1;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++) {
                if(i==j) continue;
                int k=3-i-j;
                if(f[x][i][j]<=f[y][j][k]+a[i][rev[x]]) continue;
                f[x][i][j]=f[y][j][k]+a[i][rev[x]];
                t[x][i][j]=mp(j,k);
            }
    }
    pii s;int ans=1e18;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(ans>f[n][i][j]) ans=f[n][i][j],s=mp(i,j);
    for(int i=n;i;i--) {
        col[rev[i]]=s.fr;s=t[i][s.fr][s.sc];
    }write(ans);
    for(int i=1;i<=n;i++) printf("%lld ",col[i]+1);puts("");
    return 0;
}
