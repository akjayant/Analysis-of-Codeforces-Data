#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mp make_pair
#define pb push_back 
#define N 100010
using namespace std;
set<int> graph[N];
int visited[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		graph[a - 1].insert(b - 1);
		graph[b - 1].insert(a - 1);
	}
	set<int> df;
	for(int i = 1; i < n; i++)
		df.insert(i);
	set<pair<int, int> > pq;
	pq.insert(mp(0, 0));
	int ct = 0;
	int ans = 0;
	while(ct < n){
		pair<int, int> temp = *pq.begin();
		int x = temp.second;
		int wt = temp.first;
		pq.erase(pq.begin());
		if(visited[x])continue;
		visited[x] = 1;
		ans += wt;
		ct++;
		vector<int> er;
		for(auto i = df.begin(); i != df.end(); i++){
			int y = *i;
			if(!visited[y] && graph[x].find(y) == graph[x].end()){
				pq.insert(mp(0, y));
				er.pb(y);
			}
		}
		for(int i = 0; i < er.size(); i++){
			df.erase(er[i]);
		}
		for(auto i = graph[x].begin(); i != graph[x].end(); i++){
			int y = *i;
			if(!visited[y]){
				pq.insert(mp(1, y));
			}
		}
	}
	cout << ans << '\n';
}