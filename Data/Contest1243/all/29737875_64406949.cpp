# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int) 1e5 + 1;

int n, m;
int a, b;
vector < int > g[maxn];
int p[maxn], u[maxn];
set < int > s, c;

int cmp(int a, int b){
	return  (int)g[a].size() < (int)g[b].size();
}

int cur;
void bfs(int v){
	queue < int > q;
	q.push(v);
	while(!q.empty()){
		int z = q.front();
		q.pop();
		u[z] = 1;
		for(int i : g[z]){
			if(cur % 2){
				c.erase(i);
				if(!u[i]){
					s.insert(i);
				}
			}
			else {
				s.erase(i);
				if(!u[i]){
					c.insert(i);
				}
			}
		}	
		if(cur % 2 == 0){
			for(int i : s){
				q.push(i);
				u[i] = 1;
			}
			s.clear();
		}
		else {
			for(int i : c){
				u[i] = 1;
				q.push(i);
			}
			c.clear();
		}
		cur++;
	}
}

int ans;
int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		p[i] = i;
		s.insert(i);
	}
	sort(p + 1, p + n + 1, &cmp);
	for(int i = 1; i <= n; i++){
		if(!u[p[i]]){
			ans++;
			bfs(p[i]);
		}
	}
	cout << ans - 1;
	return 0;
}