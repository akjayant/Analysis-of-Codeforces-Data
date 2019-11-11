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
	int t;
	cin>>t;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		int aa=__gcd(a,b);
		if(aa==1)
		{
			cout<<"Finite"<<endl;
		}
		else
			cout<<"Infinite"<<endl;
	}
}