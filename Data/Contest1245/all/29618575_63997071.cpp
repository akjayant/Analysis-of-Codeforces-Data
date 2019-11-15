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
ll a, b ; 
ll gcd(ll x, ll y)
{
	if(x%y==0)
	return(y); 
	return(gcd(y,x%y)); 
}
void solve()
{
	cin>>a>>b; 
	if(gcd(a,b)==1)
	cout<<"Finite"<<endl; 
	else
	cout<<"Infinite"<<endl; 
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
