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
    if (p==0)return 1;
    ll pat=bin_pow(v,p/2);
    pat=(pat*pat)%MOD;
    if (p%2)return (pat*v)%MOD;
    return pat;
}

int main(){
    fastio;
    srng;
    ll n,m;
    cin>>n>>m;
    //cout<<bin_pow(2,5)<<endl;
    cout<<bin_pow((bin_pow(2,m)-1ll+MOD)%MOD,n)<<endl;
    return 0;
}
