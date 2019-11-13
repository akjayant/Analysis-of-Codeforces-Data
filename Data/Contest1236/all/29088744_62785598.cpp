#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(a,b) memset(a,b,sizeof(a))
#define msn(a,n,b) for(int i=0;i<=n;i++)a[i]=b
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define fi first
#define se second
using namespace std;
mt19937 rng_32(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
const int mod=1e9+7;
const int seed=233;
const double PI=acos(-1.0);
const double eps=1e-7;
const int inf=0x3f3f3f3f;
const int max_n=100005;
namespace {
    inline int Add(int x,int y){return (x+=y)>=mod?x-mod:x;}
    inline int Sub(int x,int y){return (x-=y)<0?x+mod:x;}
    inline int Mul(int x,int y) {return 1ll*x*y%mod;}
    inline int Pow(int x,int y=mod-2){if(x==0)return 0;int res=1;while(y){if(y&1)res=1ll*res*x%mod;x=1ll*x*x%mod;y>>=1;}return res;}
}
/**********************head************************/
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    int ans=Pow(2,m);
    ans=Sub(ans,1);
    ans=Pow(ans,n);
    printf("%d\n",ans);
    return 0;
}