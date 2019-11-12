#include <bits/stdc++.h>    
using namespace std;
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb  push_back
#define show(x) cout<<(#x)<<" : "<<x<<endl;
#define ll  long long
#define ld  long double
#define fill(a,val) memset(a,val,sizeof(a))
#define mp  make_pair
#define ff  first
#define ss  second
#define pii pair<ll,ll>
#define sq(x) ((x)*(x))
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define endl "\n"
const ll MOD     = 1000*1000*1000+7;
const ll INF     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll MOD2    = 998244353;
const ll N 	     = 501010;
const ll N2      = 1000*1000;
const ld PI  = 3.14159265;
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);} 
ll power(ll x,ll y,ll p){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;} 
signed main()
{
	//CHECK for LONG LONG and LONG DOUBLE
	//*comment for all except cc/cf	
	#ifndef ONLINE_JUDGE
	   	freopen("input.txt","r",stdin);
	   	freopen("outputt.txt","w",stdout);
	#endif//*/
	fastio();	
	int n;
	cin>>n;
	int a[n][n];
	int count=0;
	int dum = n*n;
	int i = 0 , j =0;

	while(count!=dum)
	{
		a[i][j] = count+1;
		count++;
		if(j%2==0)
			i++;
		else
			i--;
		if(i==n)
		{
			i = n-1;
			j++;
		}
		if(i==-1)
		{
			i = 0;
			j++;
		}
	}
	for (int ii = 0; ii < n; ++ii)
	{
		for (int jj = 0; jj < n; ++jj)
		{
			cout<<a[ii][jj]<<" ";
		}
		cout<<endl;
	}
	return 0;
}