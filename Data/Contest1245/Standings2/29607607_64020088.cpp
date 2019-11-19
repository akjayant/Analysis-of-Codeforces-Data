#include<bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back
#define ll long long
using namespace std;
 
const ll INF = 1e9;
const long long LINF = 1e18;

long long res = 0;
 
void test(){
 
}
 
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	vector<pair<ll,ll> > cities;
	for(ll i = 0; i < n; i++){
		ll a,b; cin >> a >> b;
		cities.PB({a,b});
	}	
	priority_queue<pair<ll,pair<ll,ll> > > edges;
	vector<ll> cost(n);
	vector<ll> wirePerKm(n);
	for(ll i = 0; i < n; i++){
		cin >> cost[i];
		edges.push({-cost[i],{i,i}});
	}
	for(ll i = 0; i < n; i++) cin >> wirePerKm[i];
	vector<bool> visited(n);
	ll odw = 0;
	vector<ll> v1;
	vector<pair<ll,ll> > v2;
	while(odw != n){
		auto it = edges.top();
		ll x = it.ND.ST;
		ll y = it.ND.ND;
		edges.pop();
		if(visited[x] && visited[y]) continue;
		res += (-it.ST);
		if(x == y){
			v1.push_back(x+1);
		} else {
			v2.push_back({x+1,y+1});
		}
		if(!visited[y]) swap(x,y);
		for(ll i = 0; i < n; i++){
				if(i != x) 
edges.push({-((wirePerKm[i] + wirePerKm[x])*(abs(cities[i].ST-cities[x].ST) + abs(cities[i].ND-cities[x].ND))),{i,x}});
		}
		visited[x] = 1;
		odw++;
	}
	cout << res << "\n";
	cout << v1.size() << "\n";
	for(auto it : v1) cout << it << " ";
	cout << "\n";
	cout << v2.size() << "\n";
	for(auto it : v2) cout << it.ST << " " << it.ND << "\n";
}