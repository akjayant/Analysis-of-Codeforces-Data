#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define llset tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
typedef long long int ll;
typedef long double ld;
#define en '\n'
const ll mod = 1e9+7,N = 1e6+7;
#define calncr for(int i=1  ;i<=1e6;i++) fac[i] = (fac[i-1]*i)%mod;
ll fac[N] = {0},visit[N] = {0},dist[N] = {0},prnt[N] = {0}, rnk[N]={0}, garr[N]={0};

ll gen_base(const ll before, const ll after) {
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 mt_rand(seed);
    int base = std::uniform_int_distribution<ll>(before+1, after)(mt_rand);
    return base % 2 == 0 ? base-1 : base;
}

ll pow(ll a,ll b)
{
    if(!b)
        return 1;
    ll p = pow(a,b/2);
    if(b%2)
        return (a*((p*p)%mod))%mod;
    else
        return (p*p)%mod;
}

ll modInv(ll a)
{
    return pow(a,mod-2);
}

ll nCr(ll n,ll r)
{
    return (fac[n]*modInv((fac[r]*fac[n-r])%mod))%mod;
}

ll _find(ll a)
{
    if(prnt[a]!=a)
        prnt[a] = _find(prnt[a]);
    return prnt[a];
}

ll _union(ll a,ll b)
{
    ll p = _find(a),q = _find(b);
    //cout<<a<<" : "<<b<<" "<<p<<" "<<q<<endl;
    if(p==q)
        return 0;
    if(rnk[p]<=rnk[q]){
        prnt[p] = q;
        rnk[q]++;
    }
    else{
        prnt[q] = p;
        rnk[p]++;
    }
    return 1;
}

ll hashf(ll r,ll x,ll mod)
{
    return (x+r)%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    fac[0] = 1;
    calncr;
    ll n;
    cin>>n;
    pair<ll,ll> p[n];
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        p[i] = {a,b};
    }
    ll c[n],k[n];
    for(int i=0;i<n;i++)
        cin>>c[i];
    for(int i=0;i<n;i++)
        cin>>k[i];
    ll mrk[n]={0};
    set<pair<ll,ll>> s;
    for(int i=0;i<n;i++){
        s.insert({c[i],i});
    }
    ll prnt[n]={0},ans=0,cc=0,ccc=0;
    while(s.size()){
        pair<ll,ll> pr = *s.begin();
        s.erase(s.begin());
        ll cst = pr.first,i = pr.second;
        if(cst==c[i]){
            mrk[i]++;
            cc++;
        }
        ans+=cst;
        set<pair<ll,ll>> st;
        for(auto it=s.begin();it!=s.end();it++){
            pair<ll,ll> pp = *it;
            if(pp.first>(abs(p[i].first-p[pp.second].first)+abs(p[i].second-p[pp.second].second))*(k[i]+k[pp.second])){
                prnt[pp.second] = i+1;
            }
            pp.first = min(pp.first,(abs(p[i].first-p[pp.second].first)+abs(p[i].second-p[pp.second].second))*(k[i]+k[pp.second]));
            st.insert(pp);
        }
        s = st;
    }
    cout<<ans<<en<<cc<<en;
    for(int i=0;i<n;i++){
        if(mrk[i])
            cout<<i+1<<" ";
    }
    cout<<en<<n-cc<<en;
    for(int i=0;i<n;i++){
        if(!prnt[i])
            continue;
        cout<<i+1<<" "<<prnt[i]<<en;
    }
}
