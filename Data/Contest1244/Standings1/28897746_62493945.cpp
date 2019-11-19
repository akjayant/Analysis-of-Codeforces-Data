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

ll gya[1000010];
ll kai[1000010];
ll beki(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k%2==1){
            ret*=now;
            ret%=mod2;
        }
        now*=now;
        now%=mod2;
        k/=2;
    }
    return ret;
}
ll gyaku(ll n){
    return beki(n,mod2-2);
}
void nckinit(ll n){
    kai[0]=1;
    kai[1]=1;
    for(int i=2;i<=n;i++){
        kai[i]=kai[i-1]*i;
        kai[i]%=mod2;
    }
    gya[n]=gyaku(kai[n]);
    for(int i=n-1;i>=1;i--){
        gya[i]=gya[i+1]*(i+1);
        gya[i]%=mod2;
    }
    gya[0]=1;
}
ll nck(ll n,ll k){
    if(k<0)return 0;
    if(k==0||n==k)return 1;
    ll ret=kai[n];
    ret*=gya[n-k];
    ret%=mod2;
    ret*=gya[k];
    ret%=mod2;
    return ret;
}
ll npk(ll n,ll k){
    if(k<0)return 0;
    if(k==0)return 1;
    ll ret=kai[n];
    ret*=gya[n-k];
    ret%=mod2;
    return ret;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,k;cin>>n>>k;
    ll a[n];
    vector<ll> v;
    rep(i,0,n){
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(a,a+n);
    sort(v.begin(),v.end());
    ll sum[n+1];
    sum[0]=0;
    rep(i,0,n)sum[i+1]=sum[i]+a[i];
    ll u=1000000000;
    ll d=-1;
    while(u-d>1){
        ll mid=(u+d)/2;
        ll mi=inf;
        rep(i,0,n){
            ll ue=a[i]+mid;
            ll y=upper_bound(v.begin(),v.end(),ue)-v.begin();
            ll co=-sum[i+1]+a[i]*(i+1);
            if(y<n){
                co+=sum[n]-sum[y]-ue*(n-y);
            }
            mi=min(mi,co);
        }
        rrep(i,n-1,0){
            ll ue=a[i]-mid;
            ll y=lower_bound(v.begin(),v.end(),ue)-v.begin();
            ll co=-sum[y]+ue*y;
            co+=sum[n]-sum[i+1]-a[i]*(n-i-1);
            mi=min(mi,co);
        }
        if(mi<=k){
            u=mid;
        }
        else d=mid;
    }
    cout<<u<<endl;
}
