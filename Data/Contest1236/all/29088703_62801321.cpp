#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define FOR(i,a) for (int i=0;i<(a);++i)
#define FORD(i,a) for (int i=(a)-1;i>=0;i--)
#define FORT(i,a,b) for (int i=(a);i<=(b);++i)
#define FORTD(i,b,a) for (int i=(b);i>=(a);--i)
#define trav(i,v) for (auto i : v)
#define all(v) v.begin(),v.end()
#define ad push_back
#define fr first
#define sc second
#define mpr(a,b) make_pair(a,b)
#define pir pair<int,int>
#define make_unique(v) v.erase(unique(all(v)),v.end())
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define srng mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define y1 EsiHancagorcRepa

const int N=4e5+20;
const ll MOD2=998244353;
const ll MOD=1e9+7;

ll bin_pow(ll v,ll p){
    if (p==10)return 1;
    int pat=bin_pow(v,p/2);
    pat=(pat*pat)%MOD;
    if (pat%2)return (pat*v)%MOD;
    return pat;
}
vector<ll> t[N],s[N];
map<int,bool> mp[N];
int main(){
    fastio;
    srng;
    ll n,m,k;
    cin>>n>>m>>k;
    FOR(i,k){
        int x,y;
        cin>>x>>y;
        t[x].ad(y);
        s[y].ad(x);
        mp[x][y]=true;
    }
    FORT(i,1,max(n,m)){
        t[i].ad(0);
        t[i].ad(m+1);
        s[i].ad(0);
        s[i].ad(n+1);
        sort(all(t[i]));
        sort(all(s[i]));
    }
    ll x=1,y=1;
    int uxx=1;
    ll sv=0,sn=n+1,sa=m+1,sd=0;
    ll ans=0;
    while(true){
        //cout<<x<<" "<<y<<" "<<sv<<" "<<sn<<" "<<sd<<" "<<sa<<endl;
        if (x<=sv || x>=sn || y<=sd || y>=sa || mp[x][y])break;

        if (uxx==1){
            ll val=*lower_bound(all(t[x]),y);
            val=max(val,sd);
            val=min(val,sa);
            ans+=val-y;

            sv=x;
            x=x+1;
            y=val-1;
        }
        if (uxx==2){
            ll val=*lower_bound(all(s[y]),x);
            val=max(val,sv);
            val=min(val,sn);
            ans+=val-x;
            x=val-1;

            sa=y;
            y=y-1;
        }
        if (uxx==3){
            ll val=t[x][lower_bound(all(t[x]),y)-t[x].begin()-1];
            val=max(val,sd);
            val=min(val,sa);
            ans+=y-val;

            sn=x;
            x=x-1;
            y=val+1;
        }
        if (uxx==4){
            ll val=s[y][lower_bound(all(s[y]),x)-s[y].begin()-1];
            val=max(val,sv);
            val=min(val,sn);
            ans+=x-val;
            x=val+1;
            sd=y;
            y=y+1;
        }
        uxx++;
        if (uxx==5)uxx=1;
    }
    if (n*m-k==ans){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}
