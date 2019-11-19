#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define st first
#define nd second
ll x[2005],y[2005];
ll c[2005];
ll k[2005];
ll kMin[2005];
bool odw[2005];

ll dist[2005];

ll ANS = 0;
priority_queue<pair<ll,pair<int,int> > > pq;
map<pair<int,int> ,vector<int> > mapa;
map<pair<int,int> ,vector<int> >::iterator it;
vector<pair<int,int> > ans;

ll odl(ll a, ll b){
	return (ll)(abs(x[a] - x[b]) + (ll)abs(y[a] - y[b])) * (kMin[a] + k[b]);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		mapa[{x[i],y[i]}].push_back(i);
	}
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	for(int i = 1; i <= n; i++)
		cin >> k[i];
	for(int i = 1; i <= n; i++){
		it = mapa.find({x[i],y[i]});
		ll mini = 2e9;
		for(int j = 0; j < (int) (*it).second.size(); j++)
			mini = min(mini,k[((it -> second)[j])]);
		kMin[i] = mini;
	}
	for(int i = 1; i <= n; i++){
		pq.push({-c[i],{i,i}});
	}
	int e = 0;
	int v = 0;
	while(!pq.empty()){
		ll dst = -pq.top().st;
		int id = pq.top().nd.nd;
		int from = pq.top().nd.st;
		pq.pop();
		if(odw[id] == 1)
			continue;
		dist[id] = dst;
		if((ll)c[id] == dst){
			v++;
			ans.push_back({id,id});
		}
		else{
			e++;
			ans.push_back({from,id});
		}
		//cout << " from:"<<from << " id :"<<id<< " dst:" << dst << endl;
		//cout << "k[from:"<<k[from] << " k[id]:"<<k[id]<<endl;
		it = mapa.find({x[id],y[id]});
		for(int i = 0; i < (int) (*it).second.size(); i++)
			odw[(it -> second)[i]] = 1;
		for(int i = 1; i <= n; i++){
			if(!odw[i])
				pq.push({-(odl(id,i)),{id,i}});
		}
	}
	for(int i = 1; i <= n; i++){
		ANS += dist[i];
		//cout << "dist["<<i<<"]:"<<dist[i]<<endl;
	}
	cout << ANS << '\n';
	cout << v << '\n';
	for(int i = 0; i < (int) ans.size(); i++)
		if(ans[i].st == ans[i].nd)
			cout << ans[i].st << ' ';
	cout << '\n';
	cout << e << '\n';
	for(int i = 0; i < (int) ans.size(); i++)
		if(ans[i].st != ans[i].nd)
			cout << ans[i].st << ' ' << ans[i].nd <<'\n';
	return 0;
}
