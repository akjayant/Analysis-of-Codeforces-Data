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
	
	ll t;
	cin >> t;
	while(t--){
	ll a,b,c,d,k;
	cin >> a >> b >> c >> d >> k;
	ll pn = a/c;
	ll pnc = b/d;

	if(a%c != 0){
		pn+=1;
	} 

	if(b%d != 0){
		pnc+=1;
	} 

	if(pn + pnc <= k)
		cout << pn << " " << pnc << endl;
	else
		cout << -1 << endl;
	}

}