#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define nl cout<<endl

#define pii pair<ll,ll>
#define vi  vector<ll>
#define vii vector<pii>
#define mi  map<ll,ll>
#define all(a)  (a).begin(),(a).end()

#define pb push_back
#define ff first
#define ss second
#define hell 1000000007

#define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl;
#define N 300009

ll power(ll a,ll b,ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
        ll n,m;
	n=1;
	cin>>m;ll x;cin>>x;

	ll curr=0;
	ll dp[N];
	dp[1]=n;dp[2]=n+1;
	//test2(dp[1],dp[2]);
	rep(i,3,m+1)
	{
		//test1(haha);
		dp[i]=dp[i-1]+dp[i-2];
		dp[i]%=hell;
		dp[i]=(dp[i]-(n-1)+hell)%hell;
		//test2(i,dp[3]);
	}
	ll start=(2*dp[m])%hell;
	//test1(start);
	n=m;m=x;

	ll fib[N];
	fib[0]=0;
	fib[1]=2;fib[2]=2;
	rep(i,3,m+1)
	{
		fib[i]=fib[i-1]+fib[i-2];
		fib[i]%=hell;
		//test2(i,fib[i]);
	}
	ll sum[N]={0};
	rep(i,1,m+1)
	{
		sum[i]=fib[i]+sum[i-1];
		sum[i]%=hell;
	}
		
	ll ans=(start+sum[m-1])%hell;
	cout<<ans<<endl;
}		