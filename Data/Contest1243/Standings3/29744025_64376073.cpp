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
	int k;
	cin>>k;
	while(k--)
	{int n;
	cin>>n;
	int a[n];
	f(i,0,n)
	cin>>a[i];
	sort(a,a+n);
	int mx=1,ans=1,mn=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if(a[i]<=mn)
			mn=a[i];
		ans=min(mn,n-i);
		mx=max(ans,mx);
	}	
	cout<<mx<<endl;}
}