#include<bits/stdc++.h>
#define numm ch-48
#define pd putchar(' ')
#define pn putchar('\n')
#define pb push_back
#define debug(args...) cout<<#args<<"->"<<args<<endl
#define bug cout<<"************"
using namespace std;
template <typename T>
void read(T &res) {
    bool flag=false;char ch;
    while(!isdigit(ch=getchar())) (ch=='-')&&(flag=true);
    for(res=numm;isdigit(ch=getchar());res=(res<<1)+(res<<3)+numm);
    flag&&(res=-res);
}
template <typename T>
void write(T x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
typedef long long ll;
typedef long double ld;
const int maxn=2000+10;
const ll mod=1e9+7;
const int inf=0x3f3f3f3f;
const double alpha=0.7;
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
struct node {
    int u,v;
    ll w;
    node(){}
    node(int u,int v,ll w):u(u),v(v),w(w){}
    bool operator<(const node&a) {
        return w<a.w;
    }
}e[maxn*maxn+maxn];
struct a {
    ll x,y;
    int pos;
}a[maxn];
ll c[maxn],k[maxn];
int f[maxn];
vector<int >vec1;
vector<pii >vec2;
int getf(int v) {
    return f[v]==v?v:f[v]=getf(f[v]);
}
int main()
{
    int n;
    read(n);
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=n;i++) {
        read(a[i].x),read(a[i].y);
//        a[i].pos=i;
    }
    for(int i=1;i<=n;i++)
        read(c[i]);
    for(int i=1;i<=n;i++)
        read(k[i]);
    int cnt=0;
    for(int i=1;i<=n;i++) {
        e[++cnt]=node(0,i,c[i]);
        for(int j=i+1;j<=n;j++)
            e[++cnt]=node(i,j,(k[i]+k[j])*(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)));
    }
    sort(e+1,e+1+cnt);
    int num=0;
    ll sum=0;
    for(int i=1;i<=cnt;i++) {
        int u=e[i].u,v=e[i].v;
        int a=getf(u);
        int b=getf(v);
        if(a!=b) {
            f[b]=a;
            if(u==0)
                vec1.pb(v);
            else if(v==0)
                vec1.pb(u);
            else {
                vec2.pb(mp(u,v));
            }
            num++;
            sum+=e[i].w;
            if(num==n) break;

        }
    }
    write(sum);pn;
    write(vec1.size());pn;
    if(vec1.size()) {
        for(int i=0;i<vec1.size();i++)
            write(vec1[i]),pd;
        pn;
    }
    write(vec2.size());pn;
    if(vec2.size()) {
        for(int i=0;i<vec2.size();i++)
            write(vec2[i].fi),pd,write(vec2[i].se),pn;;
        pn;
    }
    return 0;
}
