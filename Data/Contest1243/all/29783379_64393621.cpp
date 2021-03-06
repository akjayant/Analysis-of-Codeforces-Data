#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;	

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define test() ll t;cin>>t;for(ll test = 1;test<=t;test++)
#define f first
#define s second
#define pb push_back
#define nl cout<<"\n"
#define MOD(x) ((x%P)+P)%P
#define vec(v) loop(i,0,v.size()) cout<<v[i]<<" "; nl
const int N = 100005;
const ll P = 1000000007;
const double eps = 1e-6;

int main()
{
	fastio();
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	ll n; cin>>n;
	ll ans = n;
	for(ll i=2; (i*i)<=n; i++)
	{
		if(n%i==0)
		{
			ans = __gcd(ans,i);
			ans = __gcd(ans,n/i);
		}
	}
	cout<<ans,nl;


	cerr << "\nTime elapsed : " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}