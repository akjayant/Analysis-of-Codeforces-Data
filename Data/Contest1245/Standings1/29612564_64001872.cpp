//{ PXH612
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int,int>
#define x first
#define y second

ll in() {ll x=0;int o=0,c=char();for(;!isdigit(c);c=getchar()) o=c=='-';for(;isdigit(c);c=getchar()) x=x*10+c-'0';return o?-x:x;}
char inchar() {char c=getchar();while(c==' '||c=='\n') c=getchar();return c;}
#define in in()
#define inchar inchar()

#define FOR(i,a,b) for(int i=a,_=b;i<=_;i++)
#define ROF(i,a,b) for(int i=b,_=a;_<=i;i--)
#define FR(i,n) FOR(i,1,n)
#define RR(x,a,b) {cout<<#x<<": ";FOR(__,a,b) cout<<x[__]<<" ";cout<<"\n";}
#define rr(x) " "<<#x<<'='<<(x)<<" "

template<typename A,typename B>A min(A a,B b){return a<b?a:b;}
template<typename A,typename B>A max(A a,B b){return a>b?a:b;}
template<typename A,typename B>bool Min(A &a,B b){if(a<b) return 0;a=b;return 1;}
template<typename A,typename B>bool Max(A &a,B b){if(a>b) return 0;a=b;return 1;}

#define VEC(i,a) for(auto&i:a)
#define pb push_back
#define vall(a) a.begin(),a.end()
#define fiv(a) (int)a.size()-1

#define bit(x,i) ((x>>(i-1))&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))
#define mu2(x) (1ll<<x)
#define bitnum(x) __builtin_popcountll(x)

#define freopen(x,o) freopen(x".inp","r",stdin);if(o) freopen(x".out","w",stdout);
#define false(x) if(!(x))
#define middle(a,b) (a+(b-(a))/2)
#define memset(x,a) memset(x,a,sizeof x)
//}
#define int ll
const int MOD=1e9+7;
const int N=1e5+5;
int n;
string s;

ll f[N];

void ADD(ll &x,ll y)
{
    x+=y;
    x%=MOD;
}
main()
{
    //freopen("C",0);
    cin>>s;s=" "+s;
    FOR(i,1,n=fiv(s)) if(s[i]=='w'||s[i]=='m') return cout<<0,0;

    f[0]=1;
    FOR(i,1,n)
    {
        if(i>=2) if((s[i]=='n'&&s[i-1]=='n') || (s[i]=='u'&&s[i-1]=='u'))
        {
            ADD(f[i],f[i-2]);
        }
        ADD(f[i],f[i-1]);
    }
    cout<<f[n];
}
