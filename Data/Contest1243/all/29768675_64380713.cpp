#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define sz size()
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
ll ans[]={0,1,2,3,2,5,1,7,2,3,1};
const ll M=1e6+5;
int32_t main()
{
    ll n,m; cin>>n,m=n;
    if(n<=6) return cout<<ans[n]<<endl,0;
    vi tmp;
    for(ll i=2;i<M;i++) while(n%i==0){
        tmp.pb(i),n/=i;
    }
    if(n!=1) tmp.pb(n);
    sort(all(tmp)),tmp.resize(unique(all(tmp))-tmp.begin());
    if(tmp.size()>1) return cout<<1<<endl,0;
    return cout<<tmp[0]<<endl,0;
}
