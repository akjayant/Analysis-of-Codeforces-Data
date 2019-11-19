//#pragma GCC optimize(3)
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;++i)
#define per(i,a,n) for (int i=n-1;i>=a;--i)
#define d1(x) cerr<<#x<<" = "<<(x)<<endl;
#define d2(x,y) cerr<<#x<<" = "<<(x)<<"  "<<#y<<" = "<<(y)<<endl;
#define d3(x,y,z) cerr<<#x<<" = "<<(x)<<"  "<<#y<<" = "<<(y)<<"  "<<#z<<" = "<<(z)<<endl;
#define all(x) (x).begin(),(x).end()
#define me(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define Rint register int
typedef long long ll;
typedef pair<int,int> piir;typedef pair<int,ll> pilr;typedef pair<ll,ll> pllr;
const double PI=acos(-1);
template <typename T> void chmin(T &x,const T &y){    if(x>y) x=y;    }
template <typename T> void chmax(T &x,const T &y){    if(x<y) x=y;    }
template <typename T> T gcd(T x, T y){return y?gcd(y,x%y):x;}//¹«Ô¼Êý
template <class T> inline bool read(T&ret){
    char c=getchar(); int sgn;
    if(c==EOF) return 0;
    while (c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1; ret=(c=='-')?0:(c-'0');
    while(static_cast<void>(c=getchar()),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn; return 1;
}
template <class T>inline void write(T x){
    if(x>9) out(x/10); putchar(x%10+'0');
}
/*********************start here**********************************/
 
//const double eps=1e-9;
//const int mod=1e9;
//template <typename T> void Mod(T &x){   while(x>=mod) x-=mod;    }
const int N=2e3+5;
//const int M=5e4+5;


void solve(int times)
{
    ll n,m,jn=0,on=0,jm=0,om=0,t;
    cin>>n;
    while (n--) {
        cin>>t;
        if(t&1) jn++;
        else on++;
    }
    cin>>m;
    while (m--) {
        cin>>t;
        if(t&1) jm++;
        else om++;
    }
    cout<<jn*jm+on*om<<endl;
    
}
 
void Init()
{
}
 
int main()
{
#ifdef LOCAL_USER
    freopen("in.txt","r",stdin);
    //freopen("out2.txt","w",stdout);
#endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 
    int times=1;
    //int T;read(T);for(;T--;)
    int T;cin>>T;for(;T--;)
    //for(;;)
    {
        solve(times++);Init();
    }
    return 0;
}
