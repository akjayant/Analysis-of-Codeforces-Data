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
const int N=2e5+5;
int n,k;
int a[N],im[N],ok;
int l[N],r[N];
void CHUTRINH()
{
    k%=2;
    if(k) FOR(i,1,n) a[i]=1-a[i];
    FOR(i,1,n) cout<<((a[i])?'B':'W');
    exit(0);
}

int DIS(int u,int v)
{
    if(u>v) v+=n;
    return v-u;
}
main()
{
//    freopen("F.inp","r",stdin);
    // freopen(".out","w",stdout);
    n=in;k=in;
    FOR(i,1,n) a[i]=inchar=='B';
    FOR(i,1,n)
    {
        int nex=i<n?i+1:1;
        int las=1<i?i-1:n;
        if(a[i]==a[nex]) im[i]=im[nex]=1,ok=1;
        if(a[i]==a[las]) im[i]=im[las]=1,ok=1;
    }
    if(ok==0) CHUTRINH();
    int las=0;
    FOR(i,1,n) if(im[i]) las=i;
    FOR(i,1,n)
    {
        if(im[i]) las=i;
        else l[i]=las;
    }
    ROF(i,1,n) if(im[i]) las=i;
    ROF(i,1,n)
    {
        if(im[i]) las=i;
        else r[i]=las;
    }
    FOR(i,1,n)
    {
        int res;
        if(im[i]) res=a[i];
        else
        {
            int lenl=DIS(l[i],i);
            int lenr=DIS(i,r[i]);
            if(lenl<lenr) res=a[l[i]];
            else res=a[r[i]];

            false(lenl<=k||lenr<=k)
            {
                if(k%2==1) res=1-a[i];
                else res=a[i];
            }
        }
        cout<<(res?'B':'W');
    }
}
