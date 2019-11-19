#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
 
// using namespace __gnu_pbds;
using namespace std;
 
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long ll;
typedef long double ld;
typedef pair <long long,long long> ii;
// typedef complex<long double> point;

struct node{
	ll u,v,w;
	bool t;
	bool operator <(const node& rhs) const{
		return w > rhs.w;
	}
};

vector <ll> id;
vector <bool> build;
ll ans = 0;

ll find(ll i){
	if (id[i] < 0) return i;
	return id[i] = find(id[i]);
}

void unio(ll i,ll j){
	ll a = find(i);
	ll b = find(j);
	if (a == b) return;
	if (id[a] > id[b]) swap(a,b);
	build[a] = build[a] | build[b];
	id[a] += id[b];
	id[b] = a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin >> n;
	vector <ii> arr(n);
	vector <ll> cost1(n);
	vector <ll> cost2(n);
	id.resize(n,-1);
	build.resize(n,false);
	for (int z=0;z<n;z++){
		cin >> arr[z].first >> arr[z].second;
	}
	for (int z=0;z<n;z++){
		cin >> cost1[z];
	}
	for (int z=0;z<n;z++){
		cin >> cost2[z];
	}
	priority_queue <node> que;
	for (int z=0;z<n;z++){
		for (int x=z+1;x<n;x++){
			node temp;
			temp.u = z;
			temp.v = x;
			temp.w = (cost2[z]+cost2[x])*(abs(arr[z].first-arr[x].first)+abs(arr[z].second-arr[x].second));
			temp.t = true;
			que.push(temp);
		}
	}
	for (int z=0;z<n;z++){
		node temp;
		temp.v = z;
		temp.u = z;
		temp.t = false;
		temp.w = cost1[z];
		que.push(temp);
	}
	vector <ll> v;
	vector <pair<ll,ll>> e;
	while (!que.empty()){
		node temp = que.top();
		que.pop();
		if (!temp.t){
			ll a = find(temp.v);
			if (!build[a]){
				ans += temp.w;
				v.push_back(temp.v);
			}
			build[temp.v] = true;
			build[a] = true;
		} else {
			ll a = find(temp.v);
			ll b = find(temp.u);
			if (build[a] && build[b]) continue;
			if (a != b){
				e.push_back(make_pair(temp.u,temp.v));
				ans += temp.w;
			}
			unio(a,b);
		}
	}
	cout << ans << endl;
	cout << v.size() << endl;
	for (ll i : v){
		cout << i+1 << " ";
	} cout << endl;
	cout << e.size() << endl;
	for (ii i : e){
		cout << i.first+1 << " " << i.second+1 << endl;
	}
}
 
 