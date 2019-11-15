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
ll n , a, b , c; string s; 
void solve()
{
	cin>>n; 
	cin>>a>>b>>c; 
	cin>>s; 
	int x = 0 ; 
	
	string ans = ""; 
	for(int i =0 ; i<n ; i++)
	ans+="_"; 
	
	for(int i =0 ; i<n; i++)
	{
		if(s[i]=='R')
		{
			if(b)
			{
				b--; x++; 
				ans[i]='P'; 
			}
		}
		if(s[i]=='P')
		{
			if(c)
			{
				c--; x++; 
				ans[i]='S'; 
			}
		}
		if(s[i]=='S')
		{
			if(a)
			{
				a--; x++; 
				ans[i]='R'; 
			}
		}
	}
	//cout<<ans<<endl; 
	for(int i =0 ; i<n ; i++)
	{
		if(ans[i]=='_')
		{
			if(a)
			{
				ans[i]='R'; a--; 
			}
			else if(b)
			{
				ans[i]='P'; b--; 
			}
			else
			{
				ans[i]='S'; c--; 
			}
		}
	}
	int y = (n+1)/2; 
	if(x>=y)
	{
		cout<<"YES"<<endl; 
		cout<<ans<<endl; 
	}
	else
	cout<<"NO"<<endl;
}
		

 
 
int main()
{ ios; 
	ll t; cin>>t; 
	while(t--)
	{
		solve(); 
	
	}
	return(0); 
}
