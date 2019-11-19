#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
//ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//#pragma comment(linker, "/STACK:10240000,10240000")
using namespace std;

#define dbg(x) cout<<#x<<" = "<< (x)<< endl
#define dbg2(x1,x2) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<endl
#define dbg3(x1,x2,x3) cout<<#x1<<" = "<<x1<<" "<<#x2<<" = "<<x2<<" "<<#x3<<" = "<<x3<<endl
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

typedef pair<int,int> pll;
typedef long long ll;
typedef unsigned long long ull;
const ull hash1 = 201326611;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll _INF = 0xc0c0c0c0c0c0c0c0;
const ll mod =  (int)1e9+7;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll ksm(ll a,ll b,ll mod){int ans=1;while(b){if(b&1) ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
ll inv2(ll a,ll mod){return ksm(a,mod-2,mod);}
void exgcd(ll a,ll b,ll &x,ll &y,ll &d){if(!b) {d = a;x = 1;y=0;return;}else{exgcd(b,a%b,y,x,d);y-=x*(a/b);}}//printf("%lld*a + %lld*b = %lld\n", x, y, d);
//ull ha[MAX_N],pp[MAX_N];

inline int read()
{
    int date = 0,m = 1; char ch = 0;
    while(ch!='-'&&(ch<'0'|ch>'9'))ch = getchar();
    if(ch=='-'){m = -1; ch = getchar();}
    while(ch>='0' && ch<='9')
    {
        date = date*10+ch-'0';
        ch = getchar();
    }return date*m;
}

/*namespace sgt
{
    #define mid ((l+r)>>1)

    #undef mid
}*/

/*int root[MAX_N],cnt,sz;
namespace hjt
{
    #define mid ((l+r)>>1)
    struct node{int l,r,maxx;}T[MAX_N*40];

    #undef mid
}*/

int main()
{
    //ios::sync_with_stdio(false);
    //freopen("a.txt","r",stdin);
    //freopen("b.txt","w",stdout);
    ll n,p,d,w,x,y,tmp;
    scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
    ll GCD = gcd(w,d);
    if(p%GCD!=0)
    {
        puts("-1");
        return 0;
    }
    p/=GCD;d/=GCD;w/=GCD;
    exgcd(w,d,x,y,tmp);
    y = (y%w+2*w)%w;
    y = y*(p%w)%w;
    x = (p-d*y)/w;
    if(x<0)
    {
        puts("-1");
        return 0;
    }
    if(n<x+y)
    {
        puts("-1");
        return 0;
    }
    printf("%lld %lld %lld\n",x,y,n-x-y);
    //fclose(stdin);
    //fclose(stdout);
    //cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}

