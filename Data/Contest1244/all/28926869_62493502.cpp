#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define pi pair<ll,ll>
#define mod (ll)(1e9+7)
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;

ll n;
std::vector<ll> morder;
std::vector<ll> adj[100005];
std::vector<ll> cost[3];

bool visited[100005];

void dfs(ll node){

	visited[node] = 1;
	morder.pb(node);
	
	for (int i = 0; i < adj[node].size(); ++i)
	{
		ll nxt = adj[node][i];
		if(!visited[nxt])
			dfs(nxt);
	}
}

int main()
{	
	cin >> n;
		cost[0].pb(-1);
		cost[1].pb(-1);
		cost[2].pb(-1);
		
		for (int i = 1; i <= n; ++i)
		{
			ll x;
			cin >> x;
			cost[0].pb(x);
		}


		for (int i = 1; i <= n; ++i)
		{
			ll x;
			cin >> x;
			cost[1].pb(x);
		}


		for (int i = 1; i <= n; ++i)
		{
			ll x;
			cin >> x;
			cost[2].pb(x);
		}


		for (int i = 0; i < n-1; ++i)
		{
			ll x,y;
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		for (int i = 1; i <= n; ++i)
		{
			if(adj[i].size() >= 3){
				cout << -1 << endl;
				return 0;
			}
		}

		std::vector<ll> v;
		ll leaf = -1;
		for (int i = 1; i <= n; ++i)
		{
			if(adj[i].size()==1){
				leaf = i;
				break;
			}
		}

		dfs(leaf);
		ll final_cost = 1e17;

		std::vector<ll> mcostarr;

		ll mcost = 0;
		for(int i=0;i<morder.size();i++){
			ll val = morder[i];
			if(i%3 == 0){
				mcost += cost[0][val];
			}

			if(i%3 == 1){
				mcost += cost[1][val];
			}

			if(i%3 == 2){
				mcost += cost[2][val];
			}
		}
		mcostarr.pb(mcost);
		mcost = 0;


		mcost = 0;
		for(int i=0;i<morder.size();i++){
			ll val = morder[i];
			if(i%3 == 0){
				mcost += cost[0][val];
			}

			if(i%3 == 1){
				mcost += cost[2][val];
			}

			if(i%3 == 2){
				mcost += cost[1][val];
			}
		}
		mcostarr.pb(mcost);
		mcost = 0;


		mcost = 0;
		for(int i=0;i<morder.size();i++){
			ll val = morder[i];
			if(i%3 == 0){
				mcost += cost[1][val];
			}

			if(i%3 == 1){
				mcost += cost[0][val];
			}

			if(i%3 == 2){
				mcost += cost[2][val];
			}
		}
		mcostarr.pb(mcost);
		mcost = 0;


		mcost = 0;
		for(int i=0;i<morder.size();i++){
			ll val = morder[i];
			if(i%3 == 0){
				mcost += cost[1][val];
			}

			if(i%3 == 1){
				mcost += cost[2][val];
			}

			if(i%3 == 2){
				mcost += cost[0][val];
			}
		}
		mcostarr.pb(mcost);
		mcost = 0;


		mcost = 0;
		for(int i=0;i<morder.size();i++){
			ll val = morder[i];
			if(i%3 == 0){
				mcost += cost[2][val];
			}

			if(i%3 == 1){
				mcost += cost[0][val];
			}

			if(i%3 == 2){
				mcost += cost[1][val];
			}
		}
		mcostarr.pb(mcost);
		mcost = 0;



		mcost = 0;
		for(int i=0;i<morder.size();i++){
			ll val = morder[i];
			if(i%3 == 0){
				mcost += cost[2][val];
			}

			if(i%3 == 1){
				mcost += cost[1][val];
			}

			if(i%3 == 2){
				mcost += cost[0][val];
			}
		}
		mcostarr.pb(mcost);
		mcost = 0;

		ll ind = -1;

		for(int i=0;i<mcostarr.size();i++){
			if(mcostarr[i] <= final_cost){
				ind = i;
				final_cost = mcostarr[i];
			}
		}
		
		std::vector<int> badcode;
		if(ind == 0){
			badcode.pb(0);
			badcode.pb(1);
			badcode.pb(2);
		}

		if(ind == 1){
			badcode.pb(0);
			badcode.pb(2);
			badcode.pb(1);
		}

		if(ind == 2){
			badcode.pb(1);
			badcode.pb(0);
			badcode.pb(2);
		}

		if(ind == 3){
			badcode.pb(1);
			badcode.pb(2);
			badcode.pb(0);
		}

		if(ind == 4){
			badcode.pb(2);
			badcode.pb(0);
			badcode.pb(1);
		}

		if(ind == 5){
			badcode.pb(2);
			badcode.pb(1);
			badcode.pb(0);
		}


		cout << final_cost << endl;
		ll colors[n+1] = {0};

		for (int i = 0; i < morder.size() ; ++i)
		{
			ll val = morder[i];
			// cout << val << endl;
			colors[val] = badcode[i%3]+1;
		}

		for(int i=1;i<=n;i++){
			cout << colors[i] << " ";
		}
		cout << endl;

	
}