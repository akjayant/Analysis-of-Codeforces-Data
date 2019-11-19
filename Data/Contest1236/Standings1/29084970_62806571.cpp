//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rint register int
typedef long long ll;
using namespace std;
const int N=1e5+5;
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
vector<int> row[N],col[N];
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

    int n,m,k;
    io>>n>>m>>k;
    ll sum=(ll)n*m-k;
    while(k--)
    {
        int x,y;
        io>>x>>y;
        row[x].push_back(y);
        col[y].push_back(x);
    }
    for(int i=1;i<=n;i++) row[i].push_back(0),row[i].push_back(m+1),sort(row[i].begin(),row[i].end());
    for(int i=1;i<=m;i++) col[i].push_back(0),col[i].push_back(n+1),sort(col[i].begin(),col[i].end());
    int x=1,y=0,f=1,u=1,l=0,d=n+1,r=m+1;
#define No {cout<<"No";return 0;}
    while(sum>0)
    {
        if(f==1)
        {
            int t=row[x][upper_bound(row[x].begin(),row[x].end(),y)-row[x].begin()];
            int q=min(t-1,r-1);
            sum-=q-y;
            if(y==q) No
            r=y=q;
        }
        if(f==2)
        {
            int t=col[y][upper_bound(col[y].begin(),col[y].end(),x)-col[y].begin()];
            int q=min(t-1,d-1);
            sum-=q-x;
            if(x==q) No
            d=x=q;
        }
        if(f==3)
        {
            int t=row[x][upper_bound(row[x].begin(),row[x].end(),y)-row[x].begin()-1];
            int q=max(t+1,l+1);
            sum-=y-q;
            if(y==q) No
            l=y=q;
        }
        if(f==4)
        {
            int t=col[y][upper_bound(col[y].begin(),col[y].end(),x)-col[y].begin()-1];
            int q=max(t+1,u+1);
            sum-=x-q;
            if(x==q) No
            u=x=q;
        }
        f=f%4+1;
    }
    cout<<"Yes";
    return 0;
}