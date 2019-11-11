/* ****TCIITB**** */

#include<bits/stdc++.h>
#define io          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define time        cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
using namespace std;

#define N  100005
ll dp[N];
int main()
{
	
	io
	string x;
	cin>>x;
	ll res=1;
	dp[1]=1;
	dp[2]=2;
	rep(i,3,N)
	{
		dp[i]=(dp[i-1]+dp[i-2])%hell;
	}
	rep(i,0,x.length())
	{
		
		if(x[i]=='w' || x[i]=='m')
		{
			cout<<"0";
			exit(0);
		}
		if(x[i]=='u')
		{
			ll cnt=0;
			while(i<x.length() && x[i]=='u')
			{
				cnt++;
				i++;
			}
			res=(res%hell*dp[cnt]%hell)%hell;
			i--;
			continue;

		}
		if(x[i]=='n')
		{
			ll cnt=0;
			while(i<x.length() && x[i]=='n')
			{
				cnt++;
				i++;
			}
			res=(res%hell*dp[cnt]%hell)%hell;
			i--;
			continue;
		}
	}
	cout<<res%hell<<endl;
	
}