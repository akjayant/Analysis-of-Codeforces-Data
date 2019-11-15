#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define endl "\n"
 

int pow1(int n, int p)
{
	if(p==0)	return 1;
	int x=pow1(n, p/2);
	x=(x*x)%mod;
	if(p%2==0)
		return x;
	else
		return (x*n)%mod;
}

int32_t main()
{
	fast;
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		int ans=0;
		int x=(b+c)/3;
		x=min(x, b);
		x=min(x, c/2);
		ans+=x*3;
		b-=x;
		int y=(a+b)/3;
		y=min(y, a);
		y=min(y, b/2);
		ans+=y*3;
		cout<<ans<<endl;
	}
	return 0;
}