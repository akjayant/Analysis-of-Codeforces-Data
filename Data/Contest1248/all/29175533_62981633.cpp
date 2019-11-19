#include <bits/stdc++.h> 
using namespace std;
#define fl(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define mx 1005
#define mx2 20
#define inf 1e9
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
ll solve(ll x,ll y)
{
	return x*x + y*y;
}
main()
{
	int n;
	cin>>n;
	int arr[n];
	ll sum  = 0, sum1 = 0;
	fl(i,0,n)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	fl(i,0,n/2)
	{
		sum += arr[i];
		sum1 += arr[n-i-1];
	}
	if(n&1)
	{
		sum1 += arr[n/2];
	}
	cout<<solve(sum,sum1);
}