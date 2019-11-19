#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double
#define f(i,x,n) for(int i=x;i<n;i++)
#define int long long
#define mod 1000000007
#define endl "\n"
const int INF = 1e18;
void fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
int32_t main() 
{
	fastio();
	int n;
	cin>>n;
	if(n==1)
	{	cout<<1;
		return 0;
	}
	vector<int>vc;
	for(int i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			int tt=n/i;
			if(tt==i)
			{
				vc.pb(i);
			}
			else
			{
				vc.pb(tt);
				vc.pb(i);
			}
		}
	}
	sort(vc.begin(),vc.end());
	int gg=0;
	f(i,0,vc.size())
	{
		if(vc[i]==1)
			continue;
		else
			gg=__gcd(vc[i],gg);
	}
	cout<<gg<<endl;
}