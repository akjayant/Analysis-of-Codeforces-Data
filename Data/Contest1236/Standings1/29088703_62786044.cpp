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

int main(){
    fastio;
    //srng;
    int ttt;
    cin>>ttt;
    while(ttt--){
        int a,b,c;
        cin>>a>>b>>c;
        int ans=min(b,c/2)*3;
        //b=b-(min(a,b/2))*2;
        b-=min(b,c/2);
        //cout<<b<<" "<<ans<<endl;
        ans+=min(a,b/2)*3;
        cout<<ans<<endl;
    }
    return 0;
}
