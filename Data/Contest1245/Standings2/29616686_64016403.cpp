#include <bits/stdc++.h>
#define copy(x,y) memcpy(x,y,sizeof x)
#define fill(x,y) memset(x,y,sizeof x)
#define int long long
using namespace std;
template<class t> inline void read(t &x){
    x=0;char c=getchar();
    bool f=0;
    while(c<'0'||c>'9') f|=c=='-',c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;
}
template<class t> inline void write(t x){
    if(x<0) putchar('-'),write(-x);
    else{
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
template<class t> inline void Write(t x,char c){
	write(x);putchar(c);
}
const int N=2005,M=N*N;
int n,a[N],b[N],tot,k[N],m,f[N];
vector<int> road,open;
struct edge{
    int u,v,w;
    inline bool operator < (const edge &nt) const {
        return w<nt.w;
    }
}e[M];
inline int getf(int x){
    if(f[x]==x) return x;
    return f[x]=getf(f[x]);
}
signed main(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]),read(b[i]);
    for(int i=1,x;i<=n;i++){
        read(x);
        e[++m]=(edge){0,i,x};
    }
    for(int i=1;i<=n;i++) read(k[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            e[++m]=(edge){i,j,(k[i]+k[j])*(abs(a[i]-a[j])+abs(b[i]-b[j]))};
    sort(e+1,e+1+m);
    int num=0;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        int x=e[i].u,y=e[i].v;
        int fx=getf(x),fy=getf(y);
        if(fx==fy) continue;
        tot+=e[i].w;
        f[fx]=fy;
        if(x==0){
            open.push_back(y);
        }
        else{
            road.push_back(i);
        }
        num++;
        if(num==n) break;
    }
    write(tot);
    puts("");
    write(open.size());
    puts("");
    for(int i=0;i<open.size();i++) write(open[i]),putchar(' ');
    puts("");
    write(road.size());
    puts("");
    for(int i=0;i<road.size();i++) write(e[road[i]].u),putchar(' '),write(e[road[i]].v),putchar('\n');
}
