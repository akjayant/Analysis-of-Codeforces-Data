#include <bits/stdc++.h>
using namespace std;
#define int long long

#define MAXN @
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define fs first
#define sc second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){
	return o<<"("<<p.fs<<","<<p.sc<<")";
}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){
	o<<"{";
	for(const T& v:vc) o<<v<<",";
	o<<"}";
	return o;
}


int n;
int deg[101010],c1[101010],c2[101010],c3[101010],ret[101010];
vector<int> adj[101010];
vector<int> res;
int c[5][101010];

void dfs(int s, int p){
	res.push_back(s);
	for(auto t:adj[s]){
		if(t!=p){
			dfs(t, s);
		}
	}
}

void solve(){

	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> c[1][i];
	}
	for(int i=1;i<=n;i++){
		cin >> c[2][i];
	}
	for(int i=1;i<=n;i++){
		cin >> c[3][i];
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin >> x >> y;
		deg[x]++;
		deg[y]++;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int root = 0;
	for(int i=1;i<=n;i++){
		if(deg[i]>2){
			cout << -1 << endl;
			return ;
		}
		if(deg[i]==1){
			root = i;
		}
	}
	dfs(root, 0);
	int ans = 1000000000000000000;
	pair<int,int> p = {1,2};
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j)continue;
			int cur = c[i][res[0]]+c[j][res[1]];
			int sum = i+j;
			int pre1 = i;
			int pre2 = j;
			for(int k=2;k<n;k++){
				int v = 6-pre1-pre2;
				cur+= c[v][res[k]];
				pre1 = pre2;
				pre2 = v;
			}
			if(cur<ans){
				ans = cur;
				p = {i,j};
			}
		}
	}
	cout << ans << endl;
	int pre1 = p.first;;
	int pre2 = p.second;
	ret[res[0]] = pre1;
	ret[res[1]] = pre2;
	for(int k=2;k<n;k++){
			int v = 6-pre1-pre2;
			pre1 = pre2;
			pre2 = v;
			ret[res[k]] = v;
	}
	for(int i=1;i<=n;i++){
		cout << ret[i] << " ";
	}


}



signed main(){

#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
#endif

ios::sync_with_stdio(false);
cin.tie(0);

cout.precision(8);

  int t = 1;
  while(t--)
  solve();

cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

return 0;

}
