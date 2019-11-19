#include<bits/stdc++.h>
//ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll mod3=1000003;
ll mod4=998244853;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
ll beki(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k%2==1){
            ret*=now;
            ret%=mod;
        }
        now*=now;
        now%=mod;
        k/=2;
    }
    return ret;
}
ll gyaku(ll n){
    return beki(n,mod-2);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,m,k;cin>>n>>m>>k;
    ll h[k],w[k];
    rep(i,0,k)cin>>h[i]>>w[i];
    vector<ll> v[n+1],vv[m+1];
    rep(i,0,k){
        v[h[i]].push_back(w[i]);
        vv[w[i]].push_back(h[i]);
    }
    rep(i,1,n+1)sort(v[i].begin(),v[i].end());
    rep(i,1,m+1)sort(vv[i].begin(),vv[i].end());
    ll cnt=1;
    ll nh=1,nw=1;
    ll u=1,d=n+1,l=0,r=m+1;
    ll c=0;
    for(ll i=0;;i++){
        if(i%4==0){
            
            ll y=lower_bound(v[nh].begin(),v[nh].end(),nw)-v[nh].begin();
            ll ne=r;
            if(y!=v[nh].size())ne=min(ne,v[nh][y]);
            if(i!=0&&ne==nw+1)break;
            cnt+=ne-nw-1;
            nw=ne-1;
            r=ne-1;
        }
        else if(i%4==1){
            
            ll y=lower_bound(vv[nw].begin(),vv[nw].end(),nh)-vv[nw].begin();
            ll ne=d;
            if(y!=vv[nw].size())ne=min(ne,vv[nw][y]);
            if(ne==nh+1)break;
            cnt+=ne-nh-1;
            nh=ne-1;
            d=ne-1;
        }
        else if(i%4==2){
            ll y=lower_bound(v[nh].begin(),v[nh].end(),nw)-v[nh].begin();
            y--;
            ll ne=l;
            if(y>=0)ne=max(ne,v[nh][y]);
            if(ne==nw-1)break;
            cnt+=nw-ne-1;
            nw=ne+1;
            l=ne+1;
        }
        else if(i%4==3){
            ll y=lower_bound(vv[nw].begin(),vv[nw].end(),nh)-vv[nw].begin();
            y--;
            ll ne=u;
            if(y>=0)ne=max(ne,vv[nw][y]);
            if(ne==nh-1)break;
            cnt+=nh-ne-1;
            nh=ne+1;
            u=ne+1;
        }
    }
    if(cnt+k==n*m)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
