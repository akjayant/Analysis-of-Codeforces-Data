#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

#define F first
#define S second
#define se second
#define fi first
#define pb push_back
#define eb emplace_back
#define mk make_pair

#define N 1000007 //10e6 +7

int pai[N];
pii cost[N];
ll c[N];

void init(int n){
	for(int i=1; i<=n; i++){
		pai[i]=i;
		cost[i] = mk(c[i], i);
	}
}

int find(int i){
	if(pai[i]==i)return i;
	return pai[i]=find(pai[i]);
}

void join(int a, int b){
	a=find(a);
	b=find(b);
	cost[b] = min(cost[a], cost[b]);
	pai[a]=pai[b];
}

ll x[N], y[N];
ll k[N];
bool vis[N];

vector<tuple<ll, int, int>>edges;

vector<int>power;
vector<pii>conn;


int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> x[i] >> y[i];
	}
	for(int i=1; i<=n; i++){
		cin >> c[i];
	}
	for(int i=1; i<=n; i++){
		cin >> k[i];
	}
	init(n);

	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			edges.eb(((k[i]+k[j])*(abs(x[i]-x[j]) + abs(y[i]-y[j]))), i, j);
		}
	}
	sort(edges.begin(), edges.end());

	ll ans=0;

	for(int i=0; i<edges.size(); i++){
		int a, b;ll w;

		tie(w, a, b) = edges[i];

		if(find(a) == find(b))continue;

		if(cost[find(a)].fi + cost[find(b)].fi < w + min(cost[find(a)].fi, cost[find(b)].fi))continue;

		ans+=w;
		//cout << "conn " << a << " " << b << " cost " << w << endl;
		join(a, b);
		conn.eb(a, b);
	}

	for(int i=1; i<=n; i++){
		if(vis[find(i)])continue;
		else {
			vis[find(i)]=true;
			//cout << "power " << i << " cost " << cost[find(i)].fi << endl;
			ans+=cost[find(i)].fi;
			power.pb(cost[find(i)].se);
		}
	}
	cout << ans << endl;
	cout << power.size() << endl;
	for(int i=0; i<power.size(); i++){
		cout << power[i] << " \n"[i==power.size()-1];
	}
	cout << conn.size() << endl;
	for(int i=0; i<conn.size(); i++){
		cout << conn[i].fi << " " << conn[i].se << endl;
	}

}