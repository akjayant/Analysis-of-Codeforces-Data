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

#define N  100005

int main()
{
	ios
	ll n,i,j;
	cin>>n;
	ll a[n+1],sum=0;
	for(i=0;i<n;i++)
		cin>>a[i],sum+=a[i];
	sort(a,a+n);
	ll ans=0,a1=0;
	for(i=0;i<n;i++){
		a1+=a[i];
		ll a2=sum-a1;
		if(abs((i+1)-(n-i-1))<=1)
			ans=max(ans,a1*a1+a2*a2);
	}
	cout<<ans;
	return 0;
}