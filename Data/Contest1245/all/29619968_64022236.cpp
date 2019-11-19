#include<bits/stdc++.h>
using namespace std;
#define ls rt<<1
#define rs (rt<<1)+1
#define PI acos(-1)
#define eps 1e-8
#define ll long long
#define fuck(x) cout<<#x<<"     "<<x<<endl;
typedef pair<int,int> pii;
const int inf=2e9;
const int maxn=5e6+10;
int d[4][2]={1,0,-1,0,0,1,0,-1};
//int lowbit(int x){return x&-x;}
//oid add(int x,int v){while(x<=n)bit[x]+=v,x+=lowbit(x);}
//int sum(int x){int ans=0;while(x>=1) ans+=bit[x],x-=lowbit(x);return ans;}
inline ll read() {
    ll s = 0,w = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') w = -1;
        ch = getchar();
    }
    while(isdigit(ch))
        s = s * 10 + ch - '0',ch = getchar();
    return s * w;
}
inline void write(ll x) {
    if(x < 0)
        putchar('-'), x = -x;
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}

struct node{
    int x,y;
}nod[2000+10];
struct edge{
    int x,y;
    ll val;
}e[maxn],vv[maxn];
int c[maxn],k[maxn],fa[maxn];
bool vis[3000];
bool cmp(const edge&nn,const edge&mm){
    return nn.val<mm.val;
}

int ifind(int x){
    return fa[x]==x?x:fa[x]=ifind(fa[x]);
}

vector<int>v;


int main(){
    int n,cnt=0,cntt=0;
    ll ans=0;
    n=read();
    for(int i=0;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++)
        nod[i].x=read(),nod[i].y=read();
    for(int i=1;i<=n;i++)
        c[i]=read();
    for(int i=1;i<=n;i++)
        k[i]=read();
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            ll dis=1LL*(k[i]+k[j])*(abs(nod[i].x-nod[j].x)+abs(nod[i].y-nod[j].y));
            e[++cnt]={i,j,dis};
        }
    for(int i=1;i<=n;i++)
        e[++cnt]={0,i,c[i]};
    sort(e+1,e+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        int fx,fy;
        fx=ifind(e[i].x);
        fy=ifind(e[i].y);
        if(fx!=fy){
            fa[fx]=fy;
            ans+=e[i].val;
            if(e[i].y==0){
                v.push_back(e[i].x);
            } else
            if(e[i].x==0)
                v.push_back(e[i].y);
            else
                vv[++cntt]=e[i];
        }

    }
    write(ans);
    puts("");
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
        printf("%d ",v[i]);
    puts("");
    cout<<cntt<<endl;
    for(int i=1;i<=cntt;i++)
        printf("%d %d\n",vv[i].x,vv[i].y);
    return 0;
}