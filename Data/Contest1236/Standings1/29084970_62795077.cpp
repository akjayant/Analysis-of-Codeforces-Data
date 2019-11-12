//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rint register int
typedef long long ll;
using namespace std;
const int N=30*30*30+5;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const double eps=1e-14;
const double PI=acos(-1);
const ll zzz=1e9;
struct ios{
    inline char gc(){
        static const int IN_LEN=1<<18|1;
        static char buf[IN_LEN],*s,*t;
        return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;
    }
    template<typename _Tp> inline ios&operator>>(_Tp&x){
        static char ch,sgn;ch=gc(),sgn=0;
        for(;!isdigit(ch);ch=gc()){if(ch==-1)return *this;sgn|=ch=='-';}
        for(x=0;isdigit(ch);ch=gc()) x=x*10+(ch^'0');
        sgn&&(x=-x);
    }
}io;

ll qpow(ll x,ll y)
{
    ll ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
int a[1000][1000],k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif
    /*
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     */

    int n;
    io>>n;
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=n;j++)
            a[j][i]=++k;
        i++;
        for(int j=n;j>=1;j--)
            a[j][i]=++k;
    }
    if(n%2==1)
    for(int j=n;j>=1;j--)
        a[j][n]=++k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}