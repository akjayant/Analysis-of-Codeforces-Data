#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define pi pair<ll,ll>
#define mod (ll)(1e9+7)
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int main()
{
	
	ll n,p,w,d;
	cin >> n >> p >> w >> d;

	ll minwin = p/w;
	if( p % w)
		minwin += 1;

	
	if(minwin > n){
		cout << -1 << endl;
		return 0;
	}

	ll delta = minwin*w - p;

	if(delta == 0){
		cout << minwin << " " <<  0 << " " << n-minwin << endl;  
		return 0;
	}
	//  delta - 10**5

	else{
		
		// ll each = w - d;
		
		// if(delta % each == 0){
		// 	ll changes = delta/each;
		// 	cout << minwin-changes << " " << changes << " " << n-minwin << endl;
		// 	return 0;
		// }

		// else{
		// 	cout << -1 << endl;
		// 	return 0;
		// }

		for(ll x1 = 0; x1 <= 100000; x1++)
		{	
			ll val1 = (w-d)*x1;

			ll pos = val1 - delta;
			if(pos >= 0){
				if(pos%d == 0){
					ll x2 = pos/d;

					ll winm = minwin-x1; 
					ll drawm = x1+x2;

					if(winm + drawm <= n and winm >= 0){
						cout << winm << " " << drawm << " " << n-winm-drawm << endl;
						return 0;
					}

				}
			}

		}

		cout << -1 << endl;
		return 0;

	}

}