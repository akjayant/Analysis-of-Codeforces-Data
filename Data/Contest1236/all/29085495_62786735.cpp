#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
const int mod=1e9+7;

typedef long long ll;
ll mypow(ll x,ll k){
    ll ans=1;
    while(k){
        if(k&1)ans=ans*x%mod;
        x=x*x%mod;
        k>>=1;
    }
    return ans;
}
int main()
{
	ll n,m;
	while(cin>>n>>m){
        ll x=(mypow(2,m)-1+mod)%mod;
        ll ans=mypow(x,n);
        cout<<ans<<endl;
	}
    return 0;
}
