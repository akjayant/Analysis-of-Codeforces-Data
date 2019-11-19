#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int ll
typedef pair<int,int> pr;
const int mxn = 2e5+5;
const int mxm = 1;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-7;
const double pii = 3.1415926535898;
#define mpr make_pair
int gcd(int x,int y){if(y==0) return x; else return gcd(y,x%y);}
int qpow(int a,int b){int ans=1; while(b){ if(b&1) ans=ans*a%mod; b>>=1; a=a*a%mod; } return ans;}
int lowbit(int x){return (x&(-x));}
int qmul(int a,int b){int ans=0; while(b){ if(b&1) ans=(ans+a)%mod; b>>=1; a=(a+a)%mod; } return ans; }
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


vector<int> e[mxn];
int c[mxn][5],d[mxn];
int now[mxn],tmp[mxn],ans,cnt;
int n;


void dfs(int u,int fa,int llas,int las){
    tmp[u] = 6 - llas - las;
    cnt += c[u][tmp[u]];
    for(int i=0;i<e[u].size();i++){
        int v = e[u][i];
        if(v==fa)continue;
        dfs(v,u,las,tmp[u]);
    }
}

void solve(int a,int b){
    int x,y;
    cnt = 0;
    for(int i=1;i<=n;i++){
        if(d[i]==1){
            x=i;
            break;
        }
    }
    y = e[x][0];
    for(int i=1;i<=n;i++) tmp[i]=0;
    tmp[x] = a,tmp[y] = b;
    cnt += c[x][a],cnt += c[y][b];
    if(e[y][0]==x){
        dfs(e[y][1],y,a,b);
    }
    else{
        dfs(e[y][0],y,a,b);
    }
    if(cnt<ans){
        ans = cnt;
        for(int i=1;i<=n;i++){
            now[i]=tmp[i];
        }
    }
}


signed main(void){
    scanf("%lld",&n);
    for(int i=1;i<=3;i++){
        for(int j = 1;j<=n;j++){
            scanf("%lld",&c[j][i]);
        }
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        e[u].pb(v),e[v].pb(u);
        d[u]++,d[v]++;
    }
    for(int i=1;i<=n;i++){
        if(d[i]>2){
            printf("-1\n");
            return 0;
        }
    }

    ans = 99999999999999999LL;
    solve(1,2);
    solve(1,3);
    solve(2,1);
    solve(2,3);
    solve(3,1);
    solve(3,2);
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++){
        printf("%lld ",now[i]);
    }
}


//int vis[mxn];
//signed main(void){
//    FAST_IO;
//    int n,p,w,d;
//    cin>>n>>p>>w>>d;
//    double le = (double)(p - n * w)/(double)(d * (w-d));
//    double ri = (double)(p - n * d)/(double)(w * (w-d));
//    if((le - ri)>eps){
////        printf("-1\n");
//        cout<<"-1\n";
//        return 0;
//    }
//    for(int i = ceil(le);i<=floor(ri);i++){
//
//        int y = (n-i) * w-d;
//        if(y<0)continue;
//        if(y==0){
//            if(y % (w-d))continue;
//            y/=(w-d);
//            int x = n-i-y;
//            if(x>=0&&y>=0){
////                printf("%ll")
//                cout<<x<<" "<<y<<" "<<i<<"\n";
//                return 0;
//            }
//        }
//    }
//        cout<<"-1\n";
//        return 0;
//}
