#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[3][100100];

ll cost[3][3];

vector<vector<ll> > g(100100);
ll done[100100];
ll group[100100];

void dfs(ll i, ll pos){
	if(done[i]) return;
	done[i]=1;
	group[i]=pos;
	for(ll j=0; j<3; ++j){
		cost[j][pos]+=arr[j][i];
	}
	for(ll j:g[i]) dfs(j, (pos+1)%3);
}

int main(){
	ll n; cin >> n;
	for(ll color=0; color<3; ++color){	
		for(ll i=1; i<=n; ++i){
			cin >> arr[color][i];
		}
	}
	for(ll i=0; i<n-1; ++i){
		ll a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		if(g[a].size() > 2 || g[b].size() > 2){
			cout << -1 << endl;
			return 0;
		}
	}
	ll endpoint;
	for(ll i=1; i<=n; ++i){
		if(g[i].size() == 1) endpoint=i;
	}
	dfs(endpoint, 0); //calcola cost
	//devo trovare la permutazione migliore di {1, 2, 3}
	ll best_a=0, best_b=0, best_c=0;
	ll best_tot=100100100100100100ll;
	for(ll a=0; a<3; ++a){
		for(ll b=0; b<3; ++b){
			for(ll c=0; c<3; ++c){
				if(a != b && a != c && b != c){
					ll tot=cost[a][0] + cost[b][1] + cost[c][2];
					if(tot<best_tot){
						best_tot=tot, best_a=a, best_b=b, best_c=c;
					}
				}
			}
		}
	}
	cout << best_tot << endl;
	for(ll i=1; i<=n; ++i){
		if(group[i] == 0) cout << best_a+1 << " ";
		if(group[i] == 1) cout << best_b+1 << " ";
		if(group[i] == 2) cout << best_c+1 << " ";
	}
	cout << endl;
}
