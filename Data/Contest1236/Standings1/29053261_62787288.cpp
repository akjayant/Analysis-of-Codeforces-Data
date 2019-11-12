#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007
#define F first
#define S second
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll P(ll x,ll y){
    ll ret = 1;
    while(y){
        if(y%2)ret = (ret*x)%mod;
        x = (x*x)%mod;
        y/=2;
        
    }
    return ret;
}

int main(){
	FIO
    ll n,m;
    cin >> n >> m;
    ll ans = (P(2,m)-1+mod)%mod;
    ans = P(ans,n);
    cout << ans << endl;
	return 0;
}





