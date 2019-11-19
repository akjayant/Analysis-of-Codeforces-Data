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
#include<algorithm>
using namespace std ;
ll mod = 998244353 ;
ll p[3][100000] ;
//DFS(is_vis , adj , ind , nodes) ;
void DFS(ll is_vis[] , vector<ll> adj[] , ll ind , vector<ll> &nodes)
{
	nodes.pub(ind) ;
	fo(i , adj[ind].size())
	{
		if(is_vis[adj[ind][i]] == 0)
		{
			is_vis[adj[ind][i]] = 1 ;
			DFS(is_vis , adj , adj[ind][i] , nodes) ;
		}
	}
	return ;
}

void calc(ll &mini , ll a , ll b , ll c , ll ans[] , vector<ll> order[])
{
	ll sum = 0 ;

		fo(j , order[0].size())
		{
			sum += p[a][order[0][j]] ;
		}
		fo(j , order[1].size())
		{
			sum += p[b][order[1][j]] ;
		}
		fo(j , order[2].size())
		{
			sum += p[c][order[2][j]] ;
		}
	//cout << " sum = " << sum << endl ;
	if(sum < mini)
	{
		mini = sum ;
		fo(j , order[0].size())
		{
			ans[order[0][j]] = a ;
		}
		fo(j , order[1].size())
		{
			ans[order[1][j]] = b ;
		}
		fo(j , order[2].size())
		{
			ans[order[2][j]] = c ;
		}

	}
	return ;
}

int main()
{
	ll n ;
    cin >> n ;
	fo(i , 3)
	{
		fo(j , n)
		{
			cin >> p[i][j] ;
		}
	}
	vector<ll> adj[n] ;
	fo(i , n-1)
	{
		ll u , v ;
		cin >> u >> v ;
		u-- ; v-- ;
		adj[u].pub(v) ;
		adj[v].pub(u) ;
	}
	//exit(0) ;
	int flag = 1 ;
	fo(i , n)
	{
		if(adj[i].size() > 2)
			flag = 0 ;
	}
	if(flag == 0)
		cout << -1 << endl;
	else
	{
		ll is_vis[n] ;
		ll ind ;
		fo(i , n)
		{
			if(adj[i].size() == 1)
				ind = i ;
			is_vis[i] = 0 ;
		}
		is_vis[ind] = 1 ;
		vector<ll> nodes ;
		DFS(is_vis , adj , ind , nodes) ;
		//exit(0) ;
		/*fo(i , nodes.size())
            cout << nodes[i] << ' ';*/
		vector<ll> order[3] ;
		fo(i , n)
		{
			order[i%3].pub(nodes[i]) ;
		}
		ll mini = 100000000000000000 ;
		ll ans[n] ;
		calc(mini , 0 , 1 , 2 , ans , order) ;
		calc(mini , 0 , 2 , 1 , ans , order) ;
		calc(mini , 1 , 0 , 2 , ans , order) ;
		calc(mini , 1 , 2 , 0 , ans , order) ;
		calc(mini , 2 , 0 , 1 , ans , order) ;
		calc(mini , 2 , 1 , 0 , ans , order) ;

		cout << mini << '\n';
		fo(i , n)
			cout << ans[i]+1 << ' ';
	}
	return 0;
}
