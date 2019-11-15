#include <bits/stdc++.h>
using namespace std; 
#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ld long double
#define fi first 
#define se second 
#define mp make_pair
#define pb push_back
#define ull unsigned long long int
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define mo 1000000007
string s; ll dp[100005]; 
void solve()
{
	cin>>s; 
	int n = s.size(); 
	dp[0]=1 ;dp[1]=1 ;  
	for(int i = 2; i<=n; i++)
	{
	  if(s[i-1]=='u'&&s[i-2]=='u')
	  {
	  	dp[i]= (dp[i-1]+dp[i-2])%mo; 
	  }
	  else if(s[i-1]=='n'&&s[i-2]=='n')
	  {
	  	dp[i]= (dp[i-1]+dp[i-2])%mo; 
	  }
	  else
	  {
	  	dp[i]= dp[i-1]; 
	  }
	     
	}
	for(int i = 0 ; i<n ; i++)
	{
		if(s[i]=='m'||s[i]=='w')
		{
			cout<<0<<endl; 
			return; 
		}
	}
	cout<<dp[n]; 
}
		

 
 
int main()
{ ios; 
	ll t; t = 1; 
	while(t--)
	{
		solve(); 
	
	}
	return(0); 
}
