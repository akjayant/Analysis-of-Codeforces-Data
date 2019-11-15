#include<bits/stdc++.h>
using namespace std;

#define in ({ll x=0;int o=0,c=char();for(;!isdigit(c);c=getchar()) o=c=='-';for(;isdigit(c);c=getchar()) x=x*10+c-'0';o?-x:x;})
#define inchar ({char c=getchar();while(c==' '||c=='\n') c=getchar();c;})

auto min(auto a,auto b){return a<b?a:b;}
auto max(auto a,auto b){return a>b?a:b;}
bool Min(auto &a,auto b) {if(a>b) {a=b;return true;}return false;}
bool Max(auto &a,auto b) {if(a<b) {a=b;return true;}return false;}

#define ll long long
#define pi pair<int,int>
#define x first
#define y second

#define FOR(i,a,b) for(int i=a,_=b;i<=_;i++)
#define ROF(i,a,b) for(int i=b,_=a;_<=i;i--)
#define RR(x,a,b) {cout<<#x<<": ";FOR(__,a,b) cout<<x[__]<<" ";cout<<"\n";}
#define rr(x) " "<<#x<<'='<<x<<" "

#define bitl(x) (64-__builtin_clzll(x))
#define bitr(x) ((__builtin_ctzll(x))+1)
#define bit(x,i) ((x>>(i-1))&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))

#define VEC(i,a) for(auto&i:a)
#define pb push_back
#define vall(a) a.begin(),a.end()
#define fiv(a) (int)a.size()-1

#define false(x) if(!(x))
#define middle(a,b) (a+(b-(a))/2)
#define _2(x) (1ll<<x)
#define bitnum(x) __builtin_popcountll(x)
////////////////////////////////////////// PHAM XUAN HUY
const int N=305;
int n;
vector<int> v[N];
int V=1;
main()
{
   // freopen("hz.inp","r",stdin);
    // freopen(".out","w",stdout);
    n=in;int o=1;
    FOR(i,1,n*n)
    {
        v[V].pb(i);

        if(V==n&&o==1) o=-1;
        else if(V==1&&o==-1) o=1;
        else V+=o;

    }
    FOR(i,1,n)
    {
        VEC(j,v[i]) cout<<j<<" ";cout<<"\n";
    }
}
