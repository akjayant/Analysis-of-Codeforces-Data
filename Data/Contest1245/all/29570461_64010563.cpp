
/**
 *     author:     TelmaZzzz
 *     create:     2019-11-01-22.29.38
**/
#include <map>
#include <set>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
//#include <random>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
void _R(int &x) { scanf("%d", &x); }
void _R(ll &x) { scanf("%lld", &x); }
void _R(db &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%lld", x); }
void _W(const db &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define erp(x,y,z) for(int x=y;x>=z;x--)
#define PB push_back
#define MP make_pair
#define INF 1073741824
#define inf 1152921504606846976
#define pi 3.14159265358979323846
#define Fi first
#define Se second
//#pragma comment(linker,"/STACK:10240000,10240000")
//mt19937 rand_(time(0));
const int N=3e5+7,M=2e6;
const long long mod=1e9+7;
inline int read(){int ret=0;char ch=getchar();bool f=1;for(;!isdigit(ch);ch=getchar()) f^=!(ch^'-');for(;isdigit(ch);ch=getchar()) ret=(ret<<1)+(ret<<3)+ch-48;return f?ret:-ret;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll ksm(ll a,ll b,ll mod){int ans=1;while(b){if(b&1) ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
ll inv2(ll a,ll mod){return ksm(a,mod-2,mod);}//逆元
//int head[N],NEXT[M],ver[M],tot;void link(int u,int v){ver[++tot]=v;NEXT[tot]=head[u];head[u]=tot;}
void TelmaZzzz(){
#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
}

struct node{
    ll x,y;
}que[3000];
ll c[N],k[N];
int fa[N];
int cha(int x){
    if(fa[x]==x) return x;
    return fa[x]=cha(fa[x]);
}
ll Abs(ll x){
    if(x<0) return -x;
    return x;
}
ll cal(int x,int y){
    return (Abs(que[x].x-que[y].x)+Abs(que[x].y-que[y].y))*(k[x]+k[y]);
}
vector<pair<ll,pair<int,int> > >q;
vector<pair<int,int> >res;
vector<int>pos;
int main(){
    TelmaZzzz();
    //ios::sync_with_stdio(false);
    int n;
    R(n);
    rep(i,1,n){
        R(que[i].x,que[i].y);
    }
    rep(i,1,n) R(c[i]);
    rep(i,1,n) R(k[i]);
    rep(i,1,n+1) fa[i]=i;
    rep(i,1,n){
        rep(j,1,n){
            if(i==j){
                q.PB(MP(c[i],MP(i,n+1)));
            }
            else {
                q.PB(MP(cal(i,j),MP(i,j)));
            }
        }
    }
    ll ans=0;
    sort(q.begin(),q.end());
    for(auto &it:q){
        int u=it.Se.Fi;
        int v=it.Se.Se;
        int x=cha(u);
        int y=cha(v);
        if(x!=y){
            ans+=it.Fi;
            fa[x]=y;
            if(v!=n+1){
                res.PB(MP(u,v));
            }
            else {
                pos.PB(u);
            }
        }
    }
    W(ans);
    printf("%d\n",pos.size());
    for(auto &it:pos) printf("%d ",it);
    puts("");
    printf("%d\n",res.size());
    for(auto &it:res){
        printf("%d %d\n",it.Fi,it.Se);
    }



    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}

