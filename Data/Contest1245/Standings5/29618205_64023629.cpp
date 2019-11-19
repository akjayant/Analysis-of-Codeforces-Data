#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int n;
ll x[2020], y[2020];
ll c[2020], k[2020];
ll cost[2020];
int par[2020];
bool done[2020];
ll ans = 0LL;
vector<int> bld;
vector< pair<int, int> > cnnct;

int main(){
	scanf("%d", &n);
	rep(i, n) scanf("%d%d", &x[i], &y[i]);
	rep(i, n) scanf("%d", &c[i]);
	rep(i, n) scanf("%d", &k[i]);
	rep(i, n) cost[i] = c[i];
	rep(i, n) done[i] = 0;
	rep(i, n) par[i] = -1;
	rep(the_number_of_powered_cities, n){
		ll mn = 0x3f3f3f3f3f3f3f3f;
		int mnpos;
		rep(i, n){
			if(!done[i]){
				if(cost[i] < mn){
					mn = cost[i];
					mnpos = i;
				}
			}
		}
		ans += mn;
		done[mnpos] = 1;
		rep(i, n){
			if(!done[i]){
				ll cost_to_connect = (abs(x[mnpos] - x[i]) + abs(y[mnpos] - y[i])) * (k[mnpos] + k[i]);
				if(cost_to_connect < cost[i]){
					cost[i] = cost_to_connect;
					par[i] = mnpos;
				}
			}
		}
	}
	rep(i, n){
		if(par[i] < 0) bld.push_back(i);
		else cnnct.push_back(make_pair(par[i], i));
	}
	cout << ans << endl;
	cout << bld.size() << endl;
	rep(i, bld.size()){
		cout << bld[i] + 1 << " ";
	}
	cout << endl;
	cout << cnnct.size() << endl;
	rep(i, cnnct.size()){
		cout << cnnct[i].first + 1 << " " << cnnct[i].second + 1 << endl;
	}
	return 0;
}