#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define int long long
#define M 1000000007
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
// Use pr(a,b,c,d,e) or cerr<<anything or prc(v.begin(),v.end()) or prc(v,v+n)

const int N = 100007;
vector <int> v[N];
vector <int> path;

void dfs(int x, int p = -1)
{
	path.push_back(x);
	for(auto& i : v[x])
	{
		if(i!=p)
			dfs(i, x);
	}
}

void solve()
{
	int i, j, k, n, m, q;
	int x, y, l, r;
	cin >> n;
	int cost[n+1][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			cin >> cost[j+1][i];
		}
	}

	for(int i=0;i<n-1;i++){
		cin >> x >> y;
		v[x].push_back(y), v[y].push_back(x);
		if(v[x].size()>=3 or v[y].size()>=3){
			cout << -1 << endl;
			return;
		}
	}
	if(n==1){
		int mn = LLONG_MAX, foo;
		for(int i=0;i<3;i++){
			if(cost[1][i] < mn){
				mn = cost[1][i], foo = i;
			}
		}
		cout << foo + 1 << endl;
		return;
	}

	int id;
	for(int i=1;i<=n;i++){
		if(v[i].size()==1){
			id = i;
			break;
		}
	}

	// pr(id);
	dfs(id);
	vector <vector <int> > type = {{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,1,0}, {2,0,1}};
	int mn_cost = LLONG_MAX, cur_cost, foo;
	for(int i=0;i<6;i++){
		cur_cost = 0;
		for(int j=0;j<n;j++){
			cur_cost += cost[path[j]][type[i][j%3]];
		}
		if(cur_cost<mn_cost){
			mn_cost = cur_cost, foo = i;
		}
	}
	vector <int> colors(n+1);
	for(int i=0;i<n;i++){
		colors[path[i]] = type[foo][i%3];
	}
	cout << mn_cost << endl;
	for(int i=1;i<=n;i++)
		cout << colors[i]+1 << " ";
	cout << endl;
}

int32_t main()
{
	fastio;
	int t;
	// cin >> t;
	t  = 1;
	for(int pp=1;pp<=t;pp++){
		solve();
	}
	return 0;
}