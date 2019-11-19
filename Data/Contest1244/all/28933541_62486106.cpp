#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mit map<int,int>::iterator
#define sit set<int>::iterator
#define itrm(g,x) for(mit g=x.begin();g!=x.end();g++)
#define itrs(g,x) for(sit g=x.begin();g!=x.end();g++)
#define ltype int
#define rep(i,j,k) for(ltype(i)=(j);(i)<=(k);(i)++)
#define rap(i,j,k) for(ltype(i)=(j);(i)<(k);(i)++)
#define per(i,j,k) for(ltype(i)=(j);(i)>=(k);(i)--)
#define pii pair<int,int>
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define fastio ios::sync_with_stdio(false)
const int inf=0x3f3f3f3f,mod=1000000007;
const double pi=3.1415926535897932,eps=1e-6;
ll n,p,w,d,x,len,y;
ll gcd(ll x,ll y){
    if(!y) return x;
    return gcd(y,x%y);
}
int main()
{
    fastio;
    cin>>n>>p>>w>>d;
    ll gc=gcd(w,d);
    if(p/w>n) {cout<<"-1";return 0;}
    ll k=-1;
    rep(i,0,min(100000ll,n)) if((p-d*i)%w==0&&d*i<=p) {k=i;break;}
    if(k==-1){cout<<"-1";return 0;}
    else {
        ll ans=(p-d*k)/w;
        if(ans+k>n) cout<<"-1";
        else cout<<ans<<" "<<k<<" "<<n-k-ans;
    }
    return 0;
}