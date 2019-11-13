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
	string s;
	cin>>s;
	int n=s.length();
	f(i,0,n)
	{
		if(s[i]=='w'||s[i]=='m')
		{
			cout<<0;
			return 0;
		}
	}
	int arr[n+1];
	arr[1]=1;
	arr[2]=2;
	f(i,3,n+1)
	{
		arr[i]=(arr[i-1]+arr[i-2])%mod;
	}
	int ans=1;
	int cu=0,cv=0;
	f(i,0,n)
	{
		if(s[i]=='u')
		{
			if(cv!=0)
				ans=(ans*arr[cv])%mod;
			cu++;
			cv=0;
		}
		else if(s[i]=='n')
		{
			if(cu!=0)
				ans=(ans*arr[cu])%mod;
			cv++;
			cu=0;
		}
		else
		{
			if(cv!=0)
				ans=(ans*arr[cv])%mod;
			if(cu!=0)
				ans=(ans*arr[cu])%mod;
			cu=0;cv=0;
		}
	}
	if(cv!=0)
	ans=(ans*arr[cv])%mod;
	if(cu!=0)
	ans=(ans*arr[cu])%mod;
	cout<<ans<<endl;	
}