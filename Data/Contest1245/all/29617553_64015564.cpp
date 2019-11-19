#include<bits/stdc++.h>
#define ll long long
#define zp push_back
#define zm make_pair
#define zl lower_bound
#define z1 first
#define z2 second
using namespace std;
int z(){int z;scanf("%d",&z);return z;}
int Z(){long long Z;scanf("%I64d", &Z);return Z;}

const int M = 2000+5;
int n;
int x[M], y[M];
int c[M], k[M];
struct STC{
    int u, v;
    long long w;
    bool operator<(STC& o)const{
        return w < o.w;
    }
}p[M*M];
int T;
int D(int x){return x>0?x:-x;}
int fa[M];
int seek(int u){
    return fa[u]==u?u:fa[u] = seek(fa[u]);
}
void uni(int u, int v){
    int fu = seek(u), fv = seek(v);
    if(fu-fv){
        fa[fv] = fu;
        seek(fv);
    }
}
int sta[M], top;
int X[M], Y[M], ptr;
void work(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        x[i] = z(); y[i] = z();
    }
    for(int i=1;i<=n;i++) c[i] = z();
    for(int i=1;i<=n;i++) k[i] = z();
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            long long w = 1LL*(D(x[i]-x[j])+D(y[i]-y[j]))*(k[i]+k[j]);
            p[++ T] = (STC){i, j, w};
        }
        p[++ T] = (STC){i, n+1, c[i]};
    }
    long long ans = 0;
    for(int i=1;i<=n+1;i++){
        fa[i] = i;
    }
    sort(p+1,p+1+T);
    for(int i=1;i<=T;i++){
        int u = p[i].u;
        int v = p[i].v;
        if(seek(u) - seek(v)){
            ans += p[i].w;
            uni(u, v);
            if(u==n+1)sta[++top] = v;
            else if(v==n+1)sta[++top] = u;
            else{
                X[++ ptr] = u;
                Y[ptr] = v;
            }
        }
    }
    printf("%I64d\n", ans);
    printf("%d\n", top);
    for(int i=1;i<=top;i++){
        printf("%d%c", sta[i], " \n"[i==top]);
    }
    printf("%d\n", ptr);
    for(int i=1;i<=ptr;i++){
        printf("%d %d\n", X[i], Y[i]);
    }
}

int main(){
    work();
}
