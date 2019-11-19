#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
set<int> s;
set<int> :: iterator it2;
vector<int> v[100002];
int bio[100002];
queue<int> q;
vector<int> vec;

void bfs() {
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int p = 0;
		vec.clear();
		for (set<int>:: iterator it = s.begin(); it != s.end(); it++) {
			while (p < v[x].size() && v[x][p] < *it) p ++;
			if (p < v[x].size() && *it == v[x][p]) p ++;
			else if (bio[*it] == 0) {
				bio[*it] = 1;
				vec.push_back(*it);
				q.push(*it);
			}
		}
		
		for (int i = 0; i < vec.size(); i++) {
			s.erase(vec[i]);
		}
	}
	
	/*s.erase(x);
	int p = 0;
	for (set<int> :: iterator it = s.begin(); it != s.end(); it++) {
		while (p < v[x].size() && v[x][p] < *it) p++;
		if (p < v[x].size() && *it == v[x][p]) p ++;
		else {
			//cout << x << " -> " << *it << endl;
			set<int> :: iterator nov = it;
			dfs(*it);
			it = nov;
		}
	}*/
}

int main() {

	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
		s.insert(i);
	}

	int k = 0;
	for (int i = 1; i <= n; i++) {
		it2 = s.find(i);
		if (it2 != s.end()) {
			k ++;
			bio[i] = 1;
			q.push(i);
			s.erase(i);
			bfs();
		}
	}
	
	cout << k-1;

	return 0;
}
