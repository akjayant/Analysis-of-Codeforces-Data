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
    ll n;cin>>n;
    ll c[3][n];
    rep(i,0,3){
        rep(j,0,n)cin>>c[i][j];
    }
    vector<ll> v[n];
    rep(i,0,n-1){
        ll a,b;cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    ll num=-1;
    rep(i,0,n){
        if(v[i].size()==1)num=i;
        if(v[i].size()>=3){
            cout<<-1<<endl;
            return 0;
        }
    }
    ll ans[n];
    ll mi=inf;
    ll pa[n];
    pa[num]=-1;
    queue<ll> q;
    q.push(num);
    ll chi[n];
    while(q.size()>0){
        ll now=q.front();q.pop();
        //cout<<now<<endl;
        rep(i,0,v[now].size()){
            if(v[now][i]!=pa[now]){
                q.push(v[now][i]);
                pa[v[now][i]]=now;
                chi[now]=v[now][i];
            }
        }
    }
    rep(i,0,3){
        rep(j,0,3){
            if(i==j)continue;
            ll now=num;
            ll co=c[i][num];
            now=chi[now];
            co+=c[j][now];
            ll h=0;
            ll anss[n];
            if(i==0){
                if(j==1)h=2;
                else h=1;
            }
            if(i==1){
                if(j==0)h=2;
                else h=0;
            }
            if(i==2){
                if(j==0)h=1;
                else h=0;
            }
            anss[num]=i;
            anss[now]=j;
            rep(k,2,n){
                ll col;
                if(k%3==0)col=i;
                else if(k%3==1)col=j;
                else col=h;
                now=chi[now];
                co+=c[col][now];
                anss[now]=col;
            }
        
        if(co<mi){
            rep(k,0,n)ans[k]=anss[k];
            mi=co;
        }
        }
        
    }
    cout<<mi<<endl;
    rep(i,0,n)cout<<ans[i]+1<<" ";
    cout<<endl;
}
