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
	int TESTS=1;
	cin>>TESTS;
	while(TESTS--)
	{
		ll n,i,j,m;
		cin>>n;
		ll p[n+1],o1=0,e1=0,o2=0,e2=0;
		for(i=0;i<n;i++){
			cin>>j;
			if(j%2)o1++;
			else e1++;
		}	
		cin>>m;
		for(i=0;i<m;i++){
			cin>>j;
			if(j%2)o2++;
			else e2++;
		}
		ll ans=o1*o2+e1*e2;
		cout<<ans<<"\n";
	}
	return 0;
}