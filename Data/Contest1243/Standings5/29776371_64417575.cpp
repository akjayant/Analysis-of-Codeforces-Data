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
	
	set<ll> diff;
	rep(i,1,sqrt(n)+1)
	{
		if(n%i==0)
		{
			if(i!=1)
				diff.insert(i);
			if(n/i!=i)
			{
				if(n/i!=1)
					diff.insert(n/i);
			}
		}
	}
	if(n==1)
	{
		cout<<"1";
		exit(0);
	}
	// if(n%2==0)
	// {
	// 	cout<<"2";
	// 	exit(0);
	// }
	ll res=n;
	for(auto i:diff)
	{
		res=__gcd(res,i);
	}
	cout<<res;
}