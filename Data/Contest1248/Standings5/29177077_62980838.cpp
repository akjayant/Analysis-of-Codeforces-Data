/* ****TCIITB**** */

#include<bits/stdc++.h>
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
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
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

#define N  100005

int main()
{
	
	io
	
	ll n;
	cin>>n;
	std::vector<ll> a(n);
	ll s1=0,s2=0;
	rep(i,0,n)
	{
		cin>>a[i];
		s1+=a[i];
	}
	sort(all(a));
	ll res=0;
	
	rep(i,0,n/2)
	{
		s2+=a[i];
	}
	cout<<(s2*s2+(s1-s2)*(s1-s2));
}