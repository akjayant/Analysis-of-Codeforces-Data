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

#define N  2001
ll n;
std::vector<pair<ll,pair<ll,ll>>> v;
ll parent[N];
ll findparent(ll node)
{
   if(parent[node]==node)
   return node;

   return (parent[node]=findparent(parent[node])); 
}
ll cord[N][2];
ll c1[N],c2[N];
int main()
{
	
	io
	cin>>n;
	rep(i,1,n+1)
	{
		cin>>cord[i][0]>>cord[i][1];
	}
	rep(i,1,n+1)
	{
		cin>>c1[i];
		v.pb({c1[i],{0,i}});
	}
	rep(i,1,n+1)
	{
		cin>>c2[i];
	}
	rep(i,1,n+1)
	{
		rep(j,i+1,n+1)
		{
			ll tc=(abs(cord[i][0]-cord[j][0])+abs(cord[i][1]-cord[j][1]))*(c2[i]+c2[j]);
			v.pb({tc,{i,j}});
		}
	}
	rep(i,0,n+1)
  	parent[i]=i;  
  	sort(all(v));    // sort in non-decreasing order according to weight 
  	ll weightmst=0;
  	std::set<ll> direct;
  	std::set<pii> both;
  	rep(i,0,v.size())
  {
     ll x=v[i].S.F;
     ll y=v[i].S.S;
     ll w=v[i].F;
     ll parentx=findparent(x);
     ll parenty=findparent(y);
     if(parentx==parenty)         // if the edge have same parents means that will form a 
     {
                                 // a cycle or loop
      
       continue;                  // so we dont add it to mst    
     }
     else
     {
       parent[parentx]=parenty;
       weightmst+=w;
       if(x!=0 && y!=0)
       	both.insert({x,y});
       else
       {
       	if(x==0 && y!=0)
       	{
       		direct.insert(y);
       	}
       	else
       	{
       		if(x!=0 && y==0)
       		{
       			direct.insert(x);
       		}
       	}
       }
     }
  }
  cout<<weightmst<<endl;
  cout<<direct.size()<<endl;
  for(auto i:direct)
  {
  	cout<<i<<" ";
  }
  cout<<endl;
  cout<<both.size()<<endl;
  for(auto i:both)
  {
  	cout<<i.F<<" "<<i.S<<endl;
  }
}