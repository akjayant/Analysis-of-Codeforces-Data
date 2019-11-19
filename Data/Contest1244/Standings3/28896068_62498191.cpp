//Suleyman Atayew

#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define N 100010
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define inf 1000000007
#define pii pair <ll, ll>

using namespace std;

ll n;
ll a, b;
ll arr[5];
ll vis[5];
ll ANS[5];
ll v[N][5];
ll ans = 1e18;
vector <ll> A;
vector <ll> E[N];

void dfs(ll x, ll pr)
{
	A.pb(x);
	
	for(auto i: E[x]) if(i != pr) dfs(i, x);
}
void f(ll x)
{
	if(x == 3) {
		ll sum = 0;
		
		for(ll i = 0; i < A.size(); i++) {
			ll nd = A[i];
			
			sum += v[nd][arr[i%3]];
		}
		
		if(ans > sum) {
			ans = sum;
			for(ll i = 0; i <= 2; i++) ANS[i] = arr[i];
		}
		return;
	}
	for(ll i = 1; i <= 3; i++)
		if(vis[i] == 0) {
			vis[i] = 1;
			arr[x] = i;
			f(x+1);
			vis[i] = 0;
		}
}

int main()
{
	cin >> n;
	
	for(ll i = 1; i <= 3; i++)
		for(ll h = 1; h <= n; h++)
			cin >> v[h][i];
	
	
	for(ll i = 1; i < n; i++) {
		cin >> a >> b;
		
		E[a].pb(b);
		E[b].pb(a);
	}
	
	ll x = 0;
	for(ll i = 1; i <= n; i++) {
		if(E[i].size() > 2) {
			cout << -1;
			return 0;
		}
		
		if(E[i].size() == 1) x = i;
	}
	
	dfs(x, 0);
	
	f(0);
	
	cout << ans << "\n";
	
	int ASD[N];
	
	for(ll i = 0; i < n; i++) ASD[A[i]] = ANS[i%3];
	
	for(int i = 1; i <= n; i++)
		cout << ASD[i] << " ";
}