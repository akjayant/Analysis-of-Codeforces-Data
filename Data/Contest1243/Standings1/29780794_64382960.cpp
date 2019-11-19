#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rint register int
typedef long long ll;
typedef long long unsigned llu;
using namespace std;
const int N=2e5+5;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const int bs=31;
const double eps=1e-8;
const ll zzz=1e9;
struct iiios{
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
ll pr[N];
int k;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin>>n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            pr[k++]=i;
            while(n%i==0) n/=i;
        }
    }
    if(n>1) pr[k++]=n;
    if(k==1) cout<<pr[0]<<endl;
    else cout<<1<<endl;
}
