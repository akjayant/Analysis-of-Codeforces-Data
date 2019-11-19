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

int main()
{
	
	io
	
	ll n,m;
	cin>>n>>m;
	ll dp[2][2][N];
	dp[0][0][2]=1;
	dp[0][1][2]=1;
	dp[1][0][2]=1;
	dp[1][1][2]=1;
	rep(i,3,N)
	{
		dp[1][0][i]=(dp[1][1][i-1]%hell+dp[0][1][i-1]%hell)%hell;
		dp[0][0][i]=(dp[1][0][i-1])%hell;
		dp[0][1][i]=(dp[1][0][i-1]%hell+dp[0][0][i-1]%hell)%hell;
		dp[1][1][i]=(dp[0][1][i-1])%hell;
	}
	ll res=0;
	rep(i,0,2)
	{
		rep(j,0,2)
		{
			res=(res%hell+dp[i][j][n]%hell+dp[i][j][m]%hell)%hell;
		}
	}
	if(n==1 && m==1)
	{
		cout<<"2";
		exit(0);
	}
	if((n==1) || (m==1))	
	{
		cout<<res%hell;
		exit(0);
	}

	cout<<(res-2+hell)%hell;
}