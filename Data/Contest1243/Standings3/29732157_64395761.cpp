#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define sz size()
#define mp make_pair
#define int long long int
#define double long double
#define bp __builtin_popcountll
#define inf 1000000000000000000
#define f(i,a,b) for(int i=a;i<=b;i++)
#define r(i,a,b) for(int i=a;i>=b;i--)
const int M=1e9+7;
const int N=1e5+5;

int32_t main()
{
	FAST
	int n;
	cin>>n;
	int ans=-1;
	int gc=0;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			gc=__gcd(gc,i);
			gc=__gcd(gc,n/i);
		}
	}
	if(gc==0)
	ans=n;
	else
	ans=gc;
	cout<<ans;
}