#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>

vector <ll> v;

ll fep(ll x, ll y, ll mod)
{ll res=1;while(y>0){if(y&1)res=(res*x)%mod;
    y=y>>1;x=(x*x)%mod;}return res%mod;}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	ll n,i,m,j,k,x,y,a,b;
	string s;
	
	cin >> n >> m;
	x=fep(2,m,1000000007)-1;
	x=fep(x,n,1000000007);
	cout << x;

	return 0;
}
