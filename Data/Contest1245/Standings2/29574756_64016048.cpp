#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<vector>
#include<map>
    
#define fst first
#define sc second
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,mid,root<<1
#define rson mid+1,r,root<<1|1
#define lc root<<1
#define rc root<<1|1
#define lowbit(x) ((x)&(-x)) 

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
typedef pair<ll,ll> PLL;

const db eps = 1e-6;
const int mod = 1e9+7;
const int maxn = 6e6+100;
const int maxm = 2e6+100;
const int inf = 0x3f3f3f3f;
const db pi = acos(-1.0);

int f[maxn];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
struct node{
    int u,v;
    ll w;
}edge[maxn];
int tot;
void add(int x, int y, ll w){
    edge[++tot].u=x;
    edge[tot].v=y;
    edge[tot].w=w;
}
bool cmp(node a, node b){
    return a.w<b.w;
}
int n,m;
PI a[maxn];
ll c[maxn],k[maxn];
vector<PI>anss;
vector<int>C;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        f[i]=i;
        scanf("%d %d", &a[i].fst,&a[i].sc);
    }
    for(int i = 1; i <= n; i++){
        scanf("%lld",&c[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%lld", &k[i]);
    }
    f[n+1]=n+1;
    for(int i = 1; i <= n; i++){
        add(n+1,i,c[i]);
        for(int j = i+1; j <= n; j++){
            ll len = abs(a[i].fst-a[j].fst)+abs(a[i].sc-a[j].sc);
            add(i,j,len*(k[i]+k[j]));
        }
    }
    sort(edge+1,edge+1+tot,cmp);
    ll ans = 0;
    int cnt = 0;
    for(int i = 1; i <= tot; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        ll w = edge[i].w;
        int t1 = find(u);
        int t2 = find(v);
        if(t1!=t2){
            f[t1]=t2;
            if(u==n+1)C.pb(v);
            if(v==n+1)C.pb(u);
            if(u!=n+1&&v!=n+1){
                anss.pb(make_pair(u,v));
            }
            ans+=w;
            cnt++;
        }
        if(cnt==n)break;
    }
    printf("%lld\n",ans);
    printf("%d\n",(int)C.size());
    for(int i = 0; i < (int)C.size(); i++){
        printf("%d ",C[i]);
    }printf("\n");
    printf("%d\n",(int)anss.size());
    for(int i = 0; i < (int)anss.size(); i++){
        printf("%d %d\n",anss[i].fst,anss[i].sc);
    }
    return 0;
}
/*

*/
