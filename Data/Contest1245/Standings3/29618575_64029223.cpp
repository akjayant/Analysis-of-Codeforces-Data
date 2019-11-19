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
ll x[2002]; ll y[2002];ll n ; ll c[2002]; ll k[2002]; int vis[2002]; 
vector<int> bu ; vector<pair<int,int> > p ; 
ll ans ; 


void solve()
{
  cin>>n ; 
  for(ll i = 1; i<=n ; i++)
  {
  	cin>>x[i]>>y[i]; 
  }
  //cerr<<"A"; 
  lp(i,1,n+1)
  {
  	cin>>c[i]; 
  }
  lp(i,1,n+1)
  {
  	cin>>k[i]; 
  }
  
  
 priority_queue<pair<ll,pair<ll,ll> > >pq; 
 for(int i = 1; i<=n ; i++)
 pq.push(mp(-c[i],mp(0,i))); 
 ans = 0; 
 while(!pq.empty())
 {
 	int ind = pq.top().se.se; int par = pq.top().se.fi ; ll temp = -pq.top().fi;
	 pq.pop();  
	if(vis[ind]==1)
	continue; 
	vis[ind]=1;  ans+=temp; 
	if(par==0)
	{  
		bu.pb(ind); 
	}
	else
	{
		p.pb(mp(ind,par)); 
	}
 	for(int i = 1; i<=n ; i++)
 	{
 		if(vis[i]==0)
 		{
 			ll cost = (k[i]+k[ind])*(abs(x[i]-x[ind])+abs(y[i]-y[ind])); 
 			pq.push(mp(-cost,mp(ind,i))); 
		 }
	 }
 }
	
	cout<<ans<<endl; 
	cout<<bu.size()<<endl; 
	for(int i =0 ; i<bu.size(); i++)
	cout<<bu[i]<<" "; 
	cout<<endl; 
	cout<<p.size()<<endl;
	for(int i =0 ; i<p.size(); i++)
	cout<<p[i].fi<<" "<<p[i].se<<endl; 
  
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
