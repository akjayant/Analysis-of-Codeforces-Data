#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N= 1e5 + 5;
const ll mod=1e9 + 7;
#define debug(x) cerr<<#x<<" is "<<x<<endl;

set< ll >rem;
ll dist[N];
bool vis[N];
vector<pair<ll, ll> > adj[N];

ll primsMST(ll source) //Finds the cost and makes the MST
{
	for(ll i=1;i<=N;i++)
		dist[i]=1e18;
	set<pair<ll, ll> > s;
	s.insert({0, source});
	ll cost=0;
	dist[source]=0;
	while(!s.empty())
	{
		pair<ll,ll> x = *(s.begin());
		s.erase(x);
		rem.erase(x.second);
		vis[x.second]=1;
		cost+=x.first;
		ll u=x.second;
		ll w=x.first;
		set<ll> tmp = rem;
		for(ll i=0;i<adj[x.second].size();i++)
		{
		    pair<ll,ll> it = adj[x.second][i];
			if(tmp.count(it.first))tmp.erase(it.first);
			if(vis[it.first])continue;
			if(dist[it.first] > it.second){
				s.erase({dist[it.first], it.first});
				dist[it.first]=it.second;
				s.insert({dist[it.first], it.first});
			}
		}
		for(set<ll>::iterator itr=tmp.begin() ; itr!=tmp.end() ; itr++){
            if(vis[*itr])continue;
            if(dist[*itr]>0){
                s.erase({dist[*itr],*itr});
                dist[*itr]=0;
                rem.erase(*itr);
                s.insert({dist[*itr],*itr});
            }
		}
	}
	return cost;
}


int main(){
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll u,v;
        cin>>u>>v;
        if(u>v)swap(u,v);
        adj[u].push_back(make_pair(v,1));
        adj[v].push_back(make_pair(u,1));
    }
    for(ll i=1;i<=n;i++)rem.insert(i);
    cout<<primsMST(1);
}

