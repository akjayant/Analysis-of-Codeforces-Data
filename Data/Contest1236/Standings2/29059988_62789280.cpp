#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , ll >
#define F first
#define S second
#define int long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
const int N=1e5+100,mod=1e9+7;
ll power(ll n, ll k){
    if (k==0){
        return 1;
    }
    else{
        if (k%2==0){
            ll x=power(n,k/2);
            return x*x%mod;
        }
        else{
            ll x=power(n,k/2);
            x=x*x%mod;
            return x*n%mod;
        }
    }
}
int32_t main(){
    sync;
    ll n,m;
    cin >> n >> m;
    ll ans=power(2,m);
    ans--;
    ans+=mod;
    ans%=mod;
    ans=power(ans,n);
    cout << ans;
}































