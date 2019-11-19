/* Dsingh_24 */

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ios	    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

#define N  100085
ll f[N];
ll expo(ll base, ll exponent, ll mod) {								//return base^exponent modulo modulus
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = ans*base ;
            ans = ans%mod;
        }
        base = base*base;
        base %= mod;
        exponent>>= 1;
    }
    return ans%mod;
}
ll inv(ll x){
	return expo(x,hell-2,hell)%hell;
}
ll ncr(ll n,ll r){
	if(r>n||n<=0||r<0)return 0LL;
	// cout<<f[n]<<" "<<inv(f[n-r])<<" "<<inv(f[r])<<"\n";
	return (f[n]*inv(f[n-r])%hell*inv(f[r]))%hell;
}
int main()
{
	ios
	ll n,m,i,j;
	f[0]=1;
	for(i=1;i<N;i++)
		f[i]=(f[i-1]*i)%hell;
	cin>>n>>m;
	ll ans=0;
	// cout<<ncr(5,2);
	for(i=1;i<n;i++){
		if(n-i>=i)
		ans+=ncr(n-i,i);
		ans%=hell;
		// cout<<"yen"<<ncr(n-i,i)<<"\n";
	}
	for(i=1;i<m;i++){
		if(m-i>=i)
		ans+=ncr(m-i,i);
		ans%=hell;
		// cout<<ncr(m-i,i)<<"\n";
		// cout<<ans<<"\n";
	}
	ans=(ans*2+2)%hell;
	cout<<ans;
	return 0;
}