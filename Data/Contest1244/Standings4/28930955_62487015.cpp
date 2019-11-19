#include <bits/stdc++.h>
#include <unistd.h>
//#define mp make_pair
#define pb push_back
#define cl clear
#define in insert
#define er erase
#define S second
#define F first
#define endl "\n" 
#define all(v) (v).begin(), (v).end()
#define getbit(x, i) ((x >> i)&1)
#define sz(v) (v).size()
#define fr(i, a, b, d) for(ll i = a; i < b; i+= d)
#define frr(i, a, b, d) for(ll i = a; i >= b; i -= d)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define pll pair < ll, ll >
#define pii pair < ll, ll >
#define trace1(x)                cerr << #x << ": " << x << "\n";
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << "\n";
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << "\n";
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << "\n";
using namespace std;
const int N = 100005;
const ll M = 1e9 + 7;
int C[N][3];
vector < int > tree[N];
int degree[N];
int level[N];
bool vis[N];
vector < int > v1, v2, v3;
map < int, int > mp;
void dfs(int v){
	vis[v] = true;
	if(level[v]%3 == 0) v3.pb(v);
	else if(level[v]%3 == 1) v1.pb(v);
	else v2.pb(v);
	for(auto i: tree[v]) if(!vis[i]) level[i] = level[v] + 1, dfs(i);
}
int main(){
	fastio;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> C[i][0];
	for(int i = 1; i <= n; i++) cin >> C[i][1];
	for(int i = 1; i <= n; i++) cin >> C[i][2];
	for(int i = 1; i < n; i++){
		int x, y;
		cin >> x >> y;
		degree[x] += 1;
		degree[y] += 1;
		tree[x].pb(y);
		tree[y].pb(x);
	}
	int z = *max_element(degree + 1, degree + n+1);
	if(z > 2){
		cout << -1;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		if(degree[i] == 1){
			level[i] = 1; 
			dfs(i);
			break;
		}
	}
	ll ans = 1e18;
	vector < int > v(3);
	v[0] = 0, v[1] = 1, v[2] = 2;
	do{
		ll x = 0;
		for(auto i: v1) x += C[i][v[0]]*1LL;
		for(auto i: v2) x += C[i][v[1]]*1LL;
		for(auto i: v3) x += C[i][v[2]]*1LL;
		//trace4(v[0], v[1], v[2], x);
		if(x <  ans){
			ans = x;
			for(auto i: v1) mp[i] = v[0];
			for(auto i: v2) mp[i] = v[1];
			for(auto i: v3) mp[i] = v[2];
		
		}
	}
	while(next_permutation(all(v)));
	cout << ans << "\n";
	for(auto i: mp) cout << i.S + 1 << " ";
	return 0;
}	

