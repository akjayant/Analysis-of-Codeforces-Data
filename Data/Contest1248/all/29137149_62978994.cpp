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
		int n;
		cin>>n;
		int c1=0;
		int c2=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x&1)
				c1++;
			else
				c2++;
		}
		int m;
		cin>>m;
		int c3=0;
		int c4=0;
		for(int i=0;i<m;i++)
		{
			int x;
			cin>>x;
			if(x&1)
				c3++;
			else
				c4++;
		}
		cout<<c1*c3+c2*c4<<endl;
	}
	return 0;
}