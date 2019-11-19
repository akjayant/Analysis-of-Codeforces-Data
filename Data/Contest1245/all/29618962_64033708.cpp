//#include<bits/stdc++.h>
#define ll long long
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair
#define fo(i , n) for(ll i = 0 ; i < n ; i++)
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<utility>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
using namespace std ;
ll z = 1000000007 ;
typedef pair<ll , pair<ll ,ll> > pi ;


int main()
{
	ll n ;
	cin >> n ;
	vector<pair<ll ,ll> > pos ;
	fo(i , n)
	{
		ll u , v ;
		cin >> u >> v ;
		pos.pub(mp(u , v)) ;
	}
	vector<ll> k ;
	vector<ll> c ;
	fo(i , n)
	{
		ll u ;
		cin >> u ;
		c.pub(u) ;
	}
	fo(i , n)
	{
		ll u ;
		cin >> u ;
		k.pub(u) ;
	}
	vector<ll> tow ;
	vector<pair<ll , ll> > edge ;
	ll is_vis[n] , parent[n] , cost[n] ;
	fo(i , n)
	{
		is_vis[i] = 0 ;
		parent[i] = -1 ;
		cost[i] = 100000000000000000 ;
	}

	priority_queue<pi, vector<pi>, greater<pi> > pq ;

	fo(i , n)
	{
		pair<ll , ll> g = mp(1 , i) ;
		pi h = mp(c[i] , g) ;
		pq.push(h) ;
	}
	ll ans = 0 ;
	while(!pq.empty())
	{
		if(is_vis[pq.top().second.second] == 0)
		{
			is_vis[pq.top().second.second] = 1 ;
			ans += pq.top().first ;
			if(pq.top().second.first == 1)
			{
				tow.pub(pq.top().second.second) ;
			}
			else
			{
				edge.pub(mp(pq.top().second.second , parent[pq.top().second.second])) ;
			}
			ll u = pq.top().second.second ;
			pq.pop() ;
			fo(i , n)
			{
				if(i != u)
				{
					ll dist = abs(pos[i].first - pos[u].first) + abs(pos[i].second - pos[u].second) ;
					ll exp = (k[i] + k[u])*(dist) ;
					if(cost[i] > exp)
					{
						parent[i] = u ;
						cost[i] = exp ;
						pair<ll , ll> g = mp(2 , i) ;
						pi h = mp(cost[i] , g) ;
						pq.push(h) ;
					}
				}
			}
		}
		else
		{
			pq.pop() ;
		}
	}
	cout << ans << '\n' ;
	cout << tow.size() << '\n' ;
	fo(i , tow.size())
		cout << tow[i] + 1 << ' ' ;
	cout << '\n' << edge.size() << '\n' ;
	fo(i , edge.size())
		cout << edge[i].first + 1 << ' ' << edge[i].second + 1 << '\n' ;
	return 0;
}
