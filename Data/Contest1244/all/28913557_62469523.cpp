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
	   	freopen("output.txt","w",stdout);
	#endif//*/
	fastio();	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int left = -1 , right = -1;
		for (int i = 0; i < n; ++i)
		{
			if(s[i]=='1'&&left==-1)
			{
				left = i;
			}
			if(s[i]=='1')
				right=i;
		}

		if(left==-1)
		{
			cout<<n<<endl;
		}
		else
		{
			left++;
			right = n-right;
			int ans = right+right;
			ans = max(ans , (left+left));
			ans = max(ans,n+1);
			int dum = 2*(n-right+1);
			int dum2 = 2*(n-left+1);
			ans = max(ans,dum);
			ans = max(ans,dum2);
			
			cout<<ans<<endl;
		}
	}
	return 0;
}